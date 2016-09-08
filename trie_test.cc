#include "trie.hpp"
#include "gtest/gtest.h"

namespace {

class TrieTest : public ::testing::Test {
 protected: 
  TrieTest() {
    trie.Build({"hello", "world", "apple", 
                "你好", "世界", "苹果"});
  }
  Trie trie;
};


TEST_F(TrieTest, TestContain) {
  vector<string> words = this->trie.ContainedWords("hello");
  EXPECT_EQ(words, vector<string>({"hello"}));
  words = this->trie.ContainedWords("helloooworld");
  EXPECT_EQ(words, vector<string>({"hello", "world"}));
  words = this->trie.ContainedWords("你好啊大苹果");
  EXPECT_EQ(words, vector<string>({"你好", "苹果"}));
  words = this->trie.ContainedWords("大苹果小苹果");
  EXPECT_EQ(words, vector<string>({"苹果"}));
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
