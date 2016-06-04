/*
 * Copyright 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <llvm/ADT/StringRef.h>

#include "Utils.h"

enum class DeclarationType {
  function,
  variable,
  inconsistent,
};

static const char* declarationTypeName(DeclarationType type) {
  switch (type) {
    case DeclarationType::function:
      return "function";
    case DeclarationType::variable:
      return "variable";
    case DeclarationType::inconsistent:
      return "inconsistent";
  }
}

struct CompilationType {
  std::string arch;
  int api_level;

 private:
  auto tie() const {
    return std::tie(arch, api_level);
  }

 public:
  bool operator<(const CompilationType& other) const {
    return tie() < other.tie();
  }

  bool operator==(const CompilationType& other) const {
    return tie() == other.tie();
  }

  std::string describe() const {
    return arch + "-" + std::to_string(api_level);
  }
};

struct DeclarationAvailability {
  int introduced = 0;
  int deprecated = 0;
  int obsoleted = 0;

  void dump(std::ostream& out = std::cout) const {
    out << describe();
  }

  bool empty() const {
    return !(introduced || deprecated || obsoleted);
  }

  auto tie() const {
    return std::tie(introduced, deprecated, obsoleted);
  }

  bool operator==(const DeclarationAvailability& rhs) const {
    return this->tie() == rhs.tie();
  }

  bool operator!=(const DeclarationAvailability& rhs) const {
    return !(*this == rhs);
  }

  std::string describe() const {
    if (!(introduced || deprecated || obsoleted)) {
      return "no availability";
    }

    std::stringstream out;
    bool need_comma = false;
    auto comma = [&out, &need_comma]() {
      if (!need_comma) {
        need_comma = true;
        return;
      }
      out << ", ";
    };

    if (introduced != 0) {
      comma();
      out << "introduced = " << introduced;
    }
    if (deprecated != 0) {
      comma();
      out << "deprecated = " << deprecated;
    }
    if (obsoleted != 0) {
      comma();
      out << "obsoleted = " << obsoleted;
    }

    return out.str();
  }
};

struct DeclarationLocation {
  std::string filename;
  unsigned line_number;
  unsigned column;
  DeclarationType type;
  bool is_extern;
  bool is_definition;
  DeclarationAvailability availability;

  auto tie() const {
    return std::tie(filename, line_number, column, type, is_extern, is_definition);
  }

  bool operator<(const DeclarationLocation& other) const {
    return tie() < other.tie();
  }

  bool operator==(const DeclarationLocation& other) const {
    return tie() == other.tie();
  }

  void dump(const std::string& base_path = "", std::ostream& out = std::cout) const {
    const char* var_type = declarationTypeName(type);
    const char* declaration_type = is_definition ? "definition" : "declaration";
    const char* linkage = is_extern ? "extern" : "static";

    std::string stripped_path;
    if (llvm::StringRef(filename).startswith(base_path)) {
      stripped_path = filename.substr(base_path.size());
    } else {
      stripped_path = filename;
    }

    out << "        " << linkage << " " << var_type << " " << declaration_type << " @ "
        << stripped_path << ":" << line_number << ":" << column;

    out << "\t[";
    availability.dump(out);
    out << "]\n";
  }
};

struct Declaration {
  std::string name;
  std::set<DeclarationLocation> locations;

  bool hasDefinition() const {
    for (const auto& location : locations) {
      if (location.is_definition) {
        return true;
      }
    }
    return false;
  }

  DeclarationType type() const {
    DeclarationType result = locations.begin()->type;
    for (const DeclarationLocation& location : locations) {
      if (location.type != result) {
        result = DeclarationType::inconsistent;
      }
    }
    return result;
  }

  void dump(const std::string& base_path = "", std::ostream& out = std::cout) const {
    out << "    " << name << " declared in " << locations.size() << " locations:\n";
    for (const DeclarationLocation& location : locations) {
      location.dump(base_path, out);
    }
  }
};

namespace clang {
class ASTUnit;
}

class HeaderDatabase {
 public:
  std::map<std::string, Declaration> declarations;

  void parseAST(clang::ASTUnit* ast);

  void dump(const std::string& base_path = "", std::ostream& out = std::cout) const {
    out << "HeaderDatabase contains " << declarations.size() << " declarations:\n";
    for (const auto& pair : declarations) {
      pair.second.dump(base_path, out);
    }
  }
};
