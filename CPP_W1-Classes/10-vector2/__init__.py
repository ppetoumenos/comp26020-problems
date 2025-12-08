import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("vector.cpp")
    check50.exists("vector.h")
    check50.exists("main.cpp")
    with open("vector.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("vector.cpp", "main.cpp", exe_name="vector", cc="g++", ggdb=True, lm=True, std='c++20')

@check50.check(exists)
def validate(sources_buf):
    pass

@check50.check(compiles)
def output_correct():
    check50.run("./vector")\
            .stdout("The size of the vector should be 10 and it's 10")\
            .stdout("Element 5 should be 6 and it's 6")\
            .stdout("")\
            .stdout("The vector should have 11 elements now and it has 11")\
            .stdout("The eleventh element should be 24 and it's 24")\
            .stdout("")\
            .stdout("The vector should have 30011 elements now and it has 30011")\
            .stdout("The last element should be 29999 and it's 29999")\
            .stdout("")\
            .exit()

