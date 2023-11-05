

#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include <iostream>

std::string ConvertToURL(const std::string& input, int length) {
    std::string output, word;
    std::istringstream iss{input};

    while(iss >> word) {
        output += word + "%20";
    }
    output.erase(output.rfind("%20"));

    return output;
}

TEST(TEST_URL_PATH, ConvertToURL) {
    EXPECT_EQ(ConvertToURL("Mr John Smith     ", 13), "Mr%20John%20Smith");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
