#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <stddef.h>

void count_init(const char* str, size_t len);
size_t count_end();

void count_word(const char* str, size_t len);

#endif
