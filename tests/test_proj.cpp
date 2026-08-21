#include "../includes/hexdump.h"
#include "../includes/reader.h"
#include <gtest/gtest.h>

TEST(ProjTest, Example) { EXPECT_EQ(example(), 1); };

TEST(ProjTest, ReadFile) {
  filedata data = readfile("hello.txt");
  EXPECT_EQ(data.length, 13);
}