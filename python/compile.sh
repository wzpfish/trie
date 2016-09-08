#!/bin/bash
swig -c++ -python trie.i
g++ -std=c++11 -fPIC -shared trie_wrap.cxx -o _trie.so -I/home/v-zhipew/anaconda2/include/python2.7
