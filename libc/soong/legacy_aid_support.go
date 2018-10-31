// Copyright (C) 2016 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

package legacyaidsupport

import (
  "android/soong/android"
  "android/soong/cc"
)

func init() {
  android.RegisterModuleType("legacyaidsupport_defaults", MmiAidFactory)
}

func MmiAidFactory() android.Module {
  module := cc.DefaultsFactory()
  android.AddLoadHook(module, MmiAidDefaults)

  return module
}

func MmiAidDefaults(ctx android.LoadHookContext) {
  var cflags []string
  type props struct {
       Cflags  []string
  }

  p := &props{}

  if ctx.Config().VendorConfig("MMIFeature").Bool("LegacyAidNumbers") {
      cflags = append(cflags, "-DMOTO_SUPPORT_LEGACY_AID_NUMBERS")
  }

  if ctx.Config().VendorConfig("MMIFeature").Bool("LegacyAidNames") {
      cflags = append(cflags, "-DMOTO_SUPPORT_LEGACY_AID_NAMES")
  }

  p.Cflags = cflags
  ctx.AppendProperties(p)
}
