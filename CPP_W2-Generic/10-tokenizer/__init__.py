import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("encoder.cpp")
    with open("encoder.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("encoder.cpp", exe_name="encoder", cc="g++", ggdb=True, lm=True, std='c++20')

@check50.check(compiles)
def output_correct():
    check50.run('./encoder "hello world"')\
            .stdout("hello	11203")\
            .stdout("world	18215")\
            .exit()

