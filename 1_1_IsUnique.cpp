
#include "gtest/gtest.h"
#include <set>
#include <string>

// TODO: The algo requires pure array
bool IsUnique(const std::string &str) {

  std::set<char> hash;

  for (auto c : str) {
    if (hash.count(c)) {
      return false;
    }
    hash.insert(c);
  }

  return true;
}

TEST(TEST_REPEATED_CHARS, IsUnique) { 
    ASSERT_FALSE(IsUnique("aaa"));
    ASSERT_FALSE(IsUnique("acdbea"));
}

TEST(TEST_UNIQUE_CHARS, IsUnique) { 
    ASSERT_TRUE(IsUnique("abd")); 
    ASSERT_TRUE(IsUnique("zab")); 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
