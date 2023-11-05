
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <unordered_map>

bool IsPermutation(const std::string &str1, const std::string &str2) {

  std::string s1{str1}, s2{str2};
  s1.erase(std::remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
  s2.erase(std::remove_if(s2.begin(), s2.end(), ::isspace), s2.end());

  if (s1.length() != s2.length())
    return false;

  int letters[128] = {0};
  for (char c : s1) {
    letters[c]++;
  }

  for (char c : s2) {
    if (letters[c] == 0)
      return false;
    letters[c]--;
  }

  return true;
}

TEST(TEST_POSITIVE_CASE, IsPermutation) {
  ASSERT_TRUE(IsPermutation("abc", "cab"));
  ASSERT_TRUE(IsPermutation("god", "     dog"));
  ASSERT_TRUE(IsPermutation("aaaaa", "aaaaa"));
}

TEST(TEST_NEGATIVE_CASE, IsPermutation) {
  ASSERT_FALSE(IsPermutation("abc", "abe"));
  ASSERT_FALSE(IsPermutation("1233", "abe"));
  ASSERT_FALSE(IsPermutation("111", "abe"));
  ASSERT_FALSE(IsPermutation("111", "aaa"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
