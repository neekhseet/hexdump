#pragma once
#include <stddef.h>

#define MAX_BUFF_SIZE 24

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char *data;
  size_t length;
} filedata;

filedata readfile(const char *path);

#ifdef __cplusplus
}
#endif