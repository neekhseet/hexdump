#include "../includes/hexdump.h"
#include "../includes/reader.h"
#include <gtest/gtest.h>

TEST(ProjTest, ReadFile)
{
  Bytes *readed = readfile("hello.txt");
  ASSERT_NE(readed, nullptr);
  EXPECT_EQ(memcmp(readed->data, "Hello", 5), 0);
  EXPECT_STREQ(readed->data, "Hello, world!");
}