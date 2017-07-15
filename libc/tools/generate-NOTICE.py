#!/usr/bin/python
# Run with directory arguments from any directory, with no special setup required.
# Or:
# for i in libc libdl libm linker libstdc++ ; do ./libc/tools/generate-NOTICE.py $i > $i/NOTICE ; done

import ftplib
import hashlib
import os
import re
import shutil
import string
import subprocess
import sys
import tarfile
import tempfile

VERBOSE = False

def warn(s):
    sys.stderr.write("warning: %s\n" % s)

def warn_verbose(s):
    if VERBOSE:
        warn(s)

def is_interesting(path):
    path = path.lower()
    uninteresting_extensions = [
        ".bp",
        ".map",
        ".mk",
        ".py",
        ".pyc",
        ".swp",
        ".txt",
    ]
    if os.path.splitext(path)[1] in uninteresting_extensions:
        return False
    if path.endswith("/notice") or path.endswith("/readme"):
        return False
    return True

def is_auto_generated(content):
    if "Generated by gensyscalls.py" in content or "generated by genserv.py" in content:
        return True
    if "This header was automatically generated from a Linux kernel header" in content:
        return True
    return False

copyrights = set()

def extract_copyright_at(lines, i):
    hash = lines[i].startswith("#")

    # Do we need to back up to find the start of the copyright header?
    start = i
    if not hash:
        while start > 0:
            if "/*" in lines[start - 1]:
                break
            start -= 1

    # Read comment lines until we hit something that terminates a
    # copyright header.
    while i < len(lines):
        if "*/" in lines[i]:
            break
        if hash and len(lines[i]) == 0:
            break
        if "\t@(#)" in lines[i] or "\tfrom: @(#)" in lines[i] or "From: @(#)" in lines[i] or "from OpenBSD:" in lines[i]:
            break
        if "\tcitrus Id: " in lines[i]:
            break
        if "\t$Citrus: " in lines[i] or "\t$OpenBSD: " in lines[i] or " $FreeBSD: " in lines[i] or "\t$NetBSD: " in lines[i]:
            break
        if "$FreeBSD$" in lines[i] or "$Citrus$" in lines[i]:
            break
        # OpenBSD likes to say where stuff originally came from:
        if "Original version ID:" in lines[i]:
            break
        i += 1

    end = i

    # Trim trailing cruft.
    while end > 0:
        if lines[end - 1] != " *" and lines[end - 1] != " * ====================================================":
            break
        end -= 1

    # Remove C/assembler comment formatting, pulling out just the text.
    clean_lines = []
    for line in lines[start:end]:
        line = line.replace("\t", "    ")
        line = line.replace("/* ", "")
        line = re.sub("^ \* ", "", line)
        line = line.replace("** ", "")
        line = line.replace("# ", "")
        if line.startswith("++Copyright++"):
            continue
        line = line.replace("--Copyright--", "")
        line = line.rstrip()
        # These come last and take care of "blank" comment lines.
        if line == "#" or line == " *" or line == "**" or line == "-":
            line = ""
        clean_lines.append(line)

    # Trim blank lines from head and tail.
    while clean_lines[0] == "":
        clean_lines = clean_lines[1:]
    while clean_lines[len(clean_lines) - 1] == "":
        clean_lines = clean_lines[0:(len(clean_lines) - 1)]

    copyright = "\n".join(clean_lines)
    copyrights.add(copyright)

    return i


def do_file(path):
    with open(path, "r") as the_file:
        try:
            content = open(path, "r").read().decode("utf-8")
        except UnicodeDecodeError:
            warn("bad UTF-8 in %s" % path)
            content = open(path, "r").read().decode("iso-8859-1")

    lines = content.split("\n")

    if len(lines) <= 4:
        warn_verbose("ignoring short file %s" % path)
        return

    if is_auto_generated(content):
        warn_verbose("ignoring auto-generated file %s" % path)
        return

    if not "Copyright" in content:
        if "public domain" in content.lower():
            warn("ignoring public domain file %s" % path)
            return
        warn('no copyright notice found in "%s" (%d lines)' % (path, len(lines)))
        return

    # Manually iterate because extract_copyright_at tells us how many lines to skip.
    i = 0
    while i < len(lines):
        if "Copyright" in lines[i] and not "@(#) Copyright" in lines[i]:
            i = extract_copyright_at(lines, i)
        else:
            i += 1


def do_dir(path):
    for directory, sub_directories, filenames in os.walk(arg):
        if ".git" in sub_directories:
            sub_directories.remove(".git")
        sub_directories = sorted(sub_directories)

        for filename in sorted(filenames):
            path = os.path.join(directory, filename)
            if is_interesting(path):
                do_file(path)


args = sys.argv[1:]
if len(args) == 0:
    args = [ "." ]

for arg in args:
    if os.path.isdir(arg):
        do_dir(arg)
    else:
        do_file(arg)

for copyright in sorted(copyrights):
    print copyright.encode("utf-8")
    print
    print "-------------------------------------------------------------------"
    print

sys.exit(0)
