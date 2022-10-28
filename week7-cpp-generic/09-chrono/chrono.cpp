#include <algorithm> // for min and max
#include <array>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#define SIZE1 (500 * 1000)
#define SIZE2 (500 * 1024)

// C array implementation

void add_arrays1(
        int *arr1, int *arr2, int *result,
        int size1, int size2)
{
    int max_size = std::max(size1, size2);

    for (int i = 0; i < max_size; ++i) {
        if (i < size1)
            result[i] = arr1[i];

        if (i < size2)
            result[i] += arr2[i];
    }
}

void init_array1(int *arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = i;
}

// std::array implementation

template <size_t N1, size_t N2>
void add_arrays2(
        std::array<int, N1>& arr1,
        std::array<int, N2>& arr2,
        std::array<int, std::max(N1, N2)>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        if (i < arr1.size())
            result[i] = arr1[i];

        if (i < arr2.size())
            result[i] += arr2[i];
    }
}

template <size_t N>
void init_array2(std::array<int, N>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = i;
}

// std::vector implementation

void add_arrays3(
        std::vector<int>& arr1,
        std::vector<int>& arr2,
        std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        if (i < arr1.size())
            result[i] = arr1[i];

        if (i < arr2.size())
            result[i] += arr2[i];
    }
}

void init_array3(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = i;
}


int main(int argc, char **argv) {
    int sum = 0;

    {
        int array1[SIZE1];
        int array2[SIZE2];

        init_array1(array1, SIZE1);
        init_array1(array2, SIZE2);

        int result_size = std::max(SIZE1, SIZE2);
        int result_array[result_size];

        for (int i = 0; i < result_size; ++i)
            result_array[i] = 0;

        add_arrays1(array1, array2, result_array, SIZE1, SIZE2);
        sum += result_array[std::min(SIZE1, SIZE2)]; // Bogus, forces compiler to evaluate result_array
    }

    {
        std::array<int, SIZE1> array1;
        std::array<int, SIZE2> array2;
        std::array<int, std::max(SIZE1, SIZE2)> result_array;

        init_array2(array1);
        init_array2(array2);

        add_arrays2(array1, array2, result_array);
        sum += result_array[std::min(SIZE1, SIZE2)]; // Bogus, forces compiler to evaluate result_array
    }

    {
        std::vector<int> array1(SIZE1);
        std::vector<int> array2(SIZE2);
        std::vector<int> result_array(std::max(SIZE1, SIZE2));

        init_array3(array1);
        init_array3(array2);

        add_arrays3(array1, array2, result_array);
        sum += result_array[std::min(SIZE1, SIZE2)]; // Bogus, forces compiler to evaluate result_array
    }

    std::cout << sum << "\n";
    return 0;
}
