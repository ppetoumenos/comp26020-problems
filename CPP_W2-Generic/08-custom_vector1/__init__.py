import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("main.cpp")
    check50.exists("vector.h")
    with open("vector.h") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("main.cpp", exe_name="main", cc="g++", ggdb=True, lm=True, std='c++20')

@check50.check(exists)
def validate(sources_buf):
    return

@check50.check(compiles)
def output_correct():
    check50.run("./main")\
            .stdout("The size of the vector should be 10 and it's 10")\
            .stdout("")\
            .stdout("Position 6 had the value 0")\
            .stdout("Position 6 now has the value 5")\
            .stdout("The vector should have 11 elements now and it has 11")\
            .stdout("The vector should have 30011 elements now and it has 30011")\
            .stdout("Position 6 in v has the value  5")\
            .stdout("Position 6 in v2 has the value 15")\
            .stdout("")\
            .stdout("Vector of vectors v3 has 3 subvectors with sizes 1, 5, and 15")\
            .exit()

