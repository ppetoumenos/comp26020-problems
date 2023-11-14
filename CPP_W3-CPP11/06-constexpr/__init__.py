import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("constexpr.cpp")
    with open("constexpr.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("constexpr.cpp", exe_name="constexpr", cc="g++", ggdb=True, lm=True, std='c++17')

@check50.check(exists)
def validate(sources_buf):
    pass

@check50.check(compiles)
def output_correct():
    proc = check50.run("./constexpr").exit()
    print(proc.stdout())
    proc.stdout("Array size is: 16378. Program run for \d+ microseconds")

