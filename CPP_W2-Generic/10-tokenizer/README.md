The program [encoder.cpp](encoder.cpp) takes a string which is passed as the
only command line argument and translates it into a sequence of token
embeddings. This is common task in Natural Language Processing and LLMs.
Normally the string would be translated into an array of integer numbers that
would then be fed to a transformer or an LSTM, but in this case we just print
successive words in the string together with each word's embedding, separated
with a tab.

The encoding for each token is stored in the file `token_encodings.txt`. The
first field of each line is the word, the second one is the associated
embedding.

Can you load the `token_encodings.txt` file, store the mappings from word to
number, and the use those mappings to translate the input string into a sequence
of numbers?

This is an open-ended exercise and you can use whichever approach you want, but
we suggest you use fstreams, maps or unordered maps, and stringstreams. In the
live session, I will show how to solve this exercise in a way that requires
very little code.

An example of expected output is:
```shell
./encoder "hello world"
hello	11203
world	18215
```

Check the correctness of your program with this command:
```shell
check50 -l --ansi-log ppetoumenos/comp26020-problems/main/CPP_W2-Generic/10-tokenizer
```
