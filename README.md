# trie
A cpp Trie implemention (Not very completed)

## Introduction
This Trie implemention is mainly used to find the substring of a text which is in a word dictionary.

For example,

Given a word dictionary containing "apple", "banana", "pear" and a text "appleeepearaa", we want to find "apple" and "pear" in the text.


## Usage

### Compile

To be used in Python, build the dynamic lib first. (Need swig and python, change your own python include dir)

```
cd python && ./compile.sh
```

### Program

```
import trie

words = load_words()

tree = trie.Tree(words)
contained_words = trie.ContainedWords(text)
```

### Benchmark

Test for 65876 Chinese words, 10000 Chinese sentences.

Without trie: 53.0635809898 seconds

With trie: 0.665399074554 seconds

