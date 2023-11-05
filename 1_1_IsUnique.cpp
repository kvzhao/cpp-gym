
#include "gtest/gtest.h"
#include <iostream>
#include <string>

bool IsUnique(const std::string &str) {

  // ascii only has 128
  if (str.length() > 128)
    return false;

  // space optimization
  int hash = 0;

  for (char c : str) {

    int val = c - 'a';

    if ((hash & (1 << val))) {
      return false;
    }

    hash |= (1 << val);
  }

  return true;
}

TEST(TEST_REPEATED_CHARS, IsUnique) {
  ASSERT_FALSE(IsUnique("aaa"));
  ASSERT_FALSE(IsUnique("00"));
  ASSERT_FALSE(IsUnique("acdbea"));
  ASSERT_FALSE(IsUnique("avzxcjthl;q5jnfhv;"));
}

TEST(TEST_UNIQUE_CHARS, IsUnique) {
  ASSERT_TRUE(IsUnique("abd"));
  ASSERT_TRUE(IsUnique("zab"));
  ASSERT_TRUE(IsUnique("1234567890-=+`~"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
