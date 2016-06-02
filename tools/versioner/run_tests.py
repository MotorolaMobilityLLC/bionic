#!/usr/bin/env python3

import os
import subprocess
import sys

red = '\033[91m'
green = '\033[92m'
bold = '\033[1m'
reset = '\033[0m'
prefix_pass = bold + "[" + green + "PASS" + reset + bold + "]" + reset
prefix_fail = bold + "[" + red + "FAIL" + reset + bold + "]" + reset


def indent(text, spaces=4):
    prefix = "    "
    return "\n".join([prefix + line for line in text.split("\n")])


def run_test(test_name, path):
    os.chdir(path)
    process = subprocess.Popen(
        ["/bin/sh", "run.sh"], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    (output, error) = process.communicate()

    if os.path.exists("expected_fail"):
        with open("expected_fail") as f:
            expected_output = f.read()
            if output != expected_output:
                print("{} {}: expected output mismatch".format(
                    prefix_fail, test_name))
                print("")
                print("  Expected:")
                print(indent(expected_output))
                print("  Actual:")
                print(indent(output))
                return False
    elif process.returncode != 0:
        print("{} {}: unexpected failure:".format(prefix_fail, test_name))
        print("")
        print(indent(output))
        return False

    print("{} {}".format(prefix_pass, test_name))
    return True

root_dir = os.path.dirname(os.path.realpath(__file__))
test_dir = os.path.join(root_dir, "tests")
tests = os.listdir(test_dir)

success = True
for test in sorted(tests):
    if not run_test(test, os.path.join(test_dir, test)):
        success = False

sys.exit(0 if success else 1)
