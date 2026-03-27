import os
import sys

callLocation = os.path.abspath(".")

def resourcePath(relativePath):
	if hasattr(sys, "_MEIPASS"):
		basePath = sys._MEIPASS
	else:
		basePath = os.path.abspath(".")

	return os.path.join(basePath, relativePath)