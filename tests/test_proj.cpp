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

TEST(ProjTest, ReadFileCreatesLinkedList)
{
  Bytes *readed = readfile("linked.txt");

  ASSERT_NE(readed, nullptr);
  ASSERT_NE(readed->next, nullptr);

  EXPECT_EQ(memcmp(readed->data, "ABCDEFGHIJKLMNOP", 16), 0);
  EXPECT_EQ(memcmp(readed->next->data, "abcdefghijklmnop", 16), 0);

  EXPECT_EQ(readed->next->next, nullptr);
}