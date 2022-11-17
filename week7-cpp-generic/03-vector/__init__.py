import check50
import check50.c
import re

@check50.check()
def exists():
    check50.exists("vector.cpp")
    with open("vector.cpp") as f:
        sources_buf = f.read()
    return sources_buf

@check50.check(exists)
def compiles():
    check50.c.compile("vector.cpp", exe_name="vector", cc="g++", ggdb=True, lm=True, std='c++17')

@check50.check(exists)
def validate(sources_buf):
    if "malloc(" in sources_buf or "free(" in sources_buf:
        raise check50.Failure("There should be no calls to malloc/free")
    if re.search("add_arrays.*[\n]{0,1}.*size[1|2].*[\n]{0,1}.*\)", sources_buf):
        raise check50.Failure("add_arrays should not take size1 or size2 as parameters")

@check50.check(compiles)
def output_correct():
    check50.run("./vector 100 154")\
            .stdout("0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 60 62 64 66 68 70 72 74 76 78 80 82 84 86 88 90 92 94 96 98 100 102 104 106 108 110 112 114 116 118 120 122 124 126 128 130 132 134 136 138 140 142 144 146 148 150 152 154 156 158 160 162 164 166 168 170 172 174 176 178 180 182 184 186 188 190 192 194 196 198 100 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120 121 122 123 124 125 126 127 128 129 130 131 132 133 134 135 136 137 138 139 140 141 142 143 144 145 146 147 148 149 150 151 152 153")\
            .exit()

