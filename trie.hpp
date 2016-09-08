#ifndef TRIE_SRC_TRIE_H_
#define TRIE_SRC_TRIE_H_

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;

class Trie {
 public:
  Trie() { root_ = new TrieNode(); }
  Trie(const vector<string>& words) { 
    root_ = new TrieNode();
    Build(words); 
  }
  ~Trie() { delete root_; }

  void Clear() {
    if (root_) {
      delete root_;
      root_ = nullptr;
    }
  }

  void Build(const vector<string>& words) {
    if (root_ == nullptr) {
      root_ = new TrieNode();
    }
    for (string word : words) {
      Insert(word);
    } 
  }
  
  void Insert(const string& word) {
    TrieNode* curr = root_;
    for (char c : word) {
      if (curr->children.count(c) == 0) {
        curr->children[c] = new TrieNode();
      } 
      curr = curr->children[c];
    }
    curr->end_of_word = true;
  }

  vector<string> ContainedWords(const string& text) {
    vector<string> contained_words;
    unordered_set<string> visited;
    for (std::size_t i = 0; i < text.size(); ++i) {
      string sub_text = text.substr(i);
      vector<string> words = ContainedWordsFromBegin(sub_text);
      for (const string& word : words) {
        if (!visited.count(word)) {
          visited.insert(word);
          contained_words.push_back(word);
        }
      }
    }
    return contained_words;
  }

  vector<string> ContainedWordsFromBegin(const string& text) {
    vector<string> contained_words;
    TrieNode* curr = root_;
    for (std::size_t i = 0; i < text.size(); ++i) {
      char c = text[i];
      if (curr->children.count(c) == 0) {
        return contained_words; 
      }
      curr = curr->children[c];
      if (curr->end_of_word) {
        contained_words.push_back(text.substr(0, i + 1));
      }
    }
    return contained_words;
  }

 private:
  struct TrieNode {
    TrieNode() : end_of_word(false) {}
    ~TrieNode() {
      for (auto k_v : children) {
        delete k_v.second;
      }
    }
    unordered_map<char, TrieNode*> children;
    bool end_of_word;
  };
  
  TrieNode* root_;
};

#endif
