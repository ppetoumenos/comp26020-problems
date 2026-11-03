The code here is the solution of 09-custom\_vector2 from Week 2. Can you modify the code to avoid all manual memory management and utilise move semantics?

```shell
The size of the vector should be 10 and it's 10

Position 6 had the value 0
Position 6 now has the value 5
The vector should have 11 elements now and it has 11
The vector should have 30011 elements now and it has 30011
Position 6 in v has the value  5
Position 6 in v2 has the value 15

Vector of vectors v3 has 3 subvectors with sizes 1, 5, and 15
The sum of the subvector sizes is 21
The moved vector should have 30011 elements now and it has 30011
The moved vector's underlying storage was moved from the old vector
```

Check the correctness of your program with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/main/CPP_W3-CPP11/07-custom_vector3
```
