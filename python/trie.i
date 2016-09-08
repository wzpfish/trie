%module trie
%{
#include "trie.h"
%}

%include "std_string.i"
%include "std_set.i"
%include "std_vector.i"
%include "std_map.i"

namespace std {
  %template(StringVector) std::vector<std::string>;
  %template(StringSet) std::set<std::string>;
  %template(StringIntMap) std::map<std::string, int>;
};

%include "trie.h"
