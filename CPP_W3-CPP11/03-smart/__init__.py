import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("smart.cpp")
    with open("smart.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("smart.cpp", exe_name="smart", cc="g++", ggdb=True, lm=True, std='c++17')

@check50.check(exists)
def validate(sources_buf):
    pass

@check50.check(compiles)
def output_correct():
    check50.c.valgrind("./smart")\
            .stdout('4468')\
            .exit()
