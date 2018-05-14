# libwordcount

## About

`libwordcount` is a library to count the occurrences of a given word in chunks of text, even occurrences split across chunks. This allows you to process large text files in a streaming fashion without having to read the whole thing in to memory.

Because `libwordcount` uses length parameters, it is just as useful for finding occurrences of arbitrary binary data just as well as words. Just the same, it does not support case-insensitive matching or any sort of Unicode normalization.

In addition to the `libwordcount` library, this package also contains a `butter` sample appications, which counts the occurrences of the word "butter" in a given text file or `stdin`. This sample application can optionally be linked to `zlib` read occurrences in `gz` compressed text files as well as plain text.

## Usage

To use libwordcount, simply open a reader by calling `count_init` and giving it the word (and length of the word) to count:

```C
#include <wordcount.h>

count_init("Salsa", 5);
```

Then just feed chunks of data to `count_word`:

```C
count_word(chunk, sizeof(chunk));
```

Once you've fed all the data through the counter, simply call `count_end` to get the final count:

```C
printf("Found %zu words, count_end());
```

## Notes

libwordcount is **NOT** a thread safe library (though it would not take much work to make it so).

## Installation

See `INSTALL` for installation instructions.