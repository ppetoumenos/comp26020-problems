import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("retval.cpp")
    with open("retval.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("retval.cpp", exe_name="retval", cc="g++", ggdb=True, lm=True, std='c++17')

@check50.check(exists)
def validate(sources_buf):
    pass

@check50.check(compiles)
def output_correct():
    check50.run("./retval")\
            .stdout(r'CLOCK_MONOTONIC: \d+-\d+-\d+T\d+:\d+:\d+.\d+', regex=True)\
            .stdout(r'CLOCK_REALTIME: \d+-\d+-\d+T\d+:\d+:\d+.\d+', regex=True)\
            .stdout('CLOCK_TAI: ERROR!')\
            .exit()
