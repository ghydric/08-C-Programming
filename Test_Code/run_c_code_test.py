import ctypes, ctypes.util

num1 = 15

c_func_path = ctypes.util.find_library(("c_print_num_func"))

c_function = ctypes.CDLL(c_func_path)

c_function.print_num.argtypes(ctypes.c_int)

c_function.print_num(num1)