import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("move.cpp")
    with open("move.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("move.cpp", exe_name="move", cc="g++", ggdb=True, lm=True, std='c++17')

@check50.check(exists)
def validate(sources_buf):
    pass

@check50.check(compiles)
def output_correct():
    check50.run("./move")\
            .stdout('invalid')\
            .stdout('HElloWorld')\
            .stdout('heLloWorld')\
            .exit()
