import os
import sys
import argparse
import subprocess

from cli.utils import resourcePath as rp
from cli.utils import callLocation

def initCommand(args):
    cFilePath = rp("file")

    cFileProcess = subprocess.run([cFilePath, "init", callLocation], capture_output=True, text=True)

    if (cFileProcess.returncode == 0) and (cFileProcess != "\n"):
        print(cFileProcess.stdout)
    else:
        print(cFileProcess.stderr)

def start():
    parser = argparse.ArgumentParser(prog="Revis")
    subparsers = parser.add_subparsers(dest="command")

    initParser = subparsers.add_parser("init")
    initParser.set_defaults(func=initCommand)

    args = parser.parse_args()

    args.func(args)