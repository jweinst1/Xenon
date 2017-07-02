from ctypes import *
import os

xss = cdll.LoadLibrary(os.path.abspath("libxss.so.1"))
print xss.xss_test_1()