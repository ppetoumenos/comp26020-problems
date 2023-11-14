import check50
import check50.c
import re

@check50.check(timeout=60)
def exists():
    check50.exists("constexpr.cpp")
    with open("constexpr.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists, timeout=60)
def compiles():
    check50.c.compile("constexpr.cpp", exe_name="constexpr", cc="g++", ggdb=True, lm=True, std='c++17', O2=True)

@check50.check(exists, timeout=60)
def validate(sources_buf):
    pass

@check50.check(compiles, timeout=60)
def output_correct():
    output = check50.run("./constexpr").stdout(timeout=60)
    check50.log(output)
    if not re.match("Array size is: 16378. Program ran for \d+ microseconds", output):
        raise check50.Mismatch("Array size is: 16378. Program ran for \d+ microseconds", output)

