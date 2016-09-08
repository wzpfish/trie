#ifndef TRIE_H_
#define TRIE_H_

#include <vector>
#include <string>
#include <map>
#include <set>

class Trie {
 public:
  Trie() { root_ = new TrieNode(); }
  Trie(const std::vector<std::string>& words) { 
    root_ = new TrieNode();
    Build(words); 
  }
  ~Trie() { Clear(); }
  
  void Clear() {
    if (root_) {
      delete root_;
      root_ = nullptr;
    }
  }

  void Build(const std::vector<std::string>& words) {
    if (root_ == nullptr) {
      root_ = new TrieNode();
    }
    for (std::string word : words) {
      Insert(word);
    } 
  }
  
  void Insert(const std::string& word) {
    TrieNode* curr = root_;
    for (char c : word) {
      if (curr->children.count(c) == 0) {
        curr->children[c] = new TrieNode();
      } 
      curr = curr->children[c];
    }
    curr->end_of_word = true;
  }

  std::vector<std::string> ContainedWords(const std::string& text) {
    std::vector<std::string> contained_words;
    std::set<std::string> visited;
    for (std::size_t i = 0; i < text.size(); ++i) {
      std::string sub_text = text.substr(i);
      std::vector<std::string> words = ContainedWordsFromBegin(sub_text);
      for (const std::string& word : words) {
        if (!visited.count(word)) {
          visited.insert(word);
          contained_words.push_back(word);
        }
      }
    }
    return contained_words;
  }

  std::vector<std::string> ContainedWordsFromBegin(const std::string& text) {
    std::vector<std::string> contained_words;
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
    std::map<char, TrieNode*> children;
    bool end_of_word;
  };
  
  TrieNode* root_;
};

#endif
