#pragma once

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 24

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct Bytes
  {
    char data[17];
    struct Bytes *next;
  } Bytes;

  Bytes *readfile(const char *path);

#ifdef __cplusplus
}
#endif