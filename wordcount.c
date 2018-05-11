#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "wordcount.h"

static char* word = NULL;
static int state = 0;
static size_t last = 0;
static size_t count = 0;


void count_init(const char* str, size_t len) {
    word = malloc(len);
    memcpy(word, str, len);
    
    state = 0;
    last = len-1;
    count = 0;
}

size_t count_end() {
    free(word);
    word = NULL;
    
    return count;
}

void count_word(const char* str, size_t len)
{
    for(; len; --len, str++) {
        if (*str != word[state]) {
            state = 0;
        } else if(++state == last) {
            state = 0;
            ++count;
        }
    }
}
