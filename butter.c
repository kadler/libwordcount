#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#ifdef HAVE_LIBZ
#include <zlib.h>
#define fdopen gzdopen
#define fread gzfread
#endif

#include "wordcount.h"

#define WORD "butter"

int main(int argc, char** argv)
{
    static char buffer[16 * 1024];
    int fd = 0;
#ifdef HAVE_LIBZ
    gzFile f;
#else
    FILE* f;
#endif
    
    if(argc == 2) {
        fd = open(argv[1], O_RDONLY);
        if(fd < 0) {
            printf("Couldn't open %s\n", argv[1]);
            return 1;
        }
    }
    
    f = fdopen(fd, "r");
    
    count_init(WORD, sizeof(WORD)-1);
    
    size_t bytes;
    struct timespec start, end;
    memset(&start, 0, sizeof(start));
    memset(&end, 0, sizeof(end));
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    do {
        bytes = fread(buffer, 1, sizeof(buffer), f);
        count_word(buffer, bytes);
    } while(bytes);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    end.tv_sec -= start.tv_sec;
    end.tv_nsec -= start.tv_nsec;
    
    printf("There were %zu instances of %s\n", count_end(), WORD);
    printf("It took %ld.%09ld seconds to count them all\n", (long) end.tv_sec, end.tv_nsec);
    
    return 0;
}
