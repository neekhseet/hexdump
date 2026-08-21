#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct filedata {
  char *data;
  size_t length;
} filedata;

filedata readfile(const char *path);

#ifdef __cplusplus
}
#endif