#include "../includes/hexdump.h"
#include "../includes/reader.h"
#include <gtest/gtest.h>

TEST(ProjTest, ReadFile) {
  filedata data = readfile("hello.txt");
  EXPECT_EQ(data.length, 13);
}