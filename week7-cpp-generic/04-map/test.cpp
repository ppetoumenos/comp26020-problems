#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#define SIZE (32 * 1024 * 1024)

int dot(std::map<int, int>& a, std::map<int, int>& b)
{
    int sum = 0;
	for (std::pair<int, int> p : a) {
		std::map<int, int>::iterator it = b.find(p.first);
        if (it != b.end())
            sum += p.second * it->second;
    }
    return sum;

}

void init_vector(std::map<int, int>& v)
{
	for (int i = 0; i < SIZE; ++i) {
        if ((rand() % 0xfff) == 0)
            v[i] = rand() & 0xf;
    }
}


int main(int argc, char **argv)
{
    srand(0);
    std::map<int, int> a, b;
    init_vector(a);
    init_vector(b);

    std::cout << dot(a, b) << "\n";

    return 0;
}
