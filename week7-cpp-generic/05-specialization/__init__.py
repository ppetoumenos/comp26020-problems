import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("specialization.cpp")
    with open("specialization.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("specialization.cpp", exe_name="specialization", cc="g++")

@check50.check(exists)
def validate(sources_buf):
    if "template<>" not in sources_buf and "template <>" not in sources_buf:
        raise check50.Failure("There should be an explicit specialization for Array8 and bool");

@check50.check(compiles)
def output_correct():
    check50.run("./specialization")\
            .stdout("168")\
            .exit()

