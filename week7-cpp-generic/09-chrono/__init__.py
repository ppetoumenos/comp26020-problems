import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("chrono.cpp")
    with open("chrono.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("chrono.cpp", exe_name="chrono", cc="g++", cflags="-std=c++17 -O1")

@check50.check(exists)
def validate(sources_buf):
    return

@check50.check(compiles)
def output_correct():
    check50.run("./array")\
            .stdout()\
            .exit()

