#!/usr/bin/env python3

import argparse
import random
import string

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate file for testing libwordcount')
    parser.add_argument('word', help='Word to be counted for')
    parser.add_argument('count', type=int, help='Number of times to include word in the output')

    args = parser.parse_args()
    chance = len(args.word)*2

    while args.count > 0:
        r = random.randint(0, chance)
        
        if r == 0:
            print(args.word, end='')
            args.count -= 1
        else:
            print(''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(r)), end='')

    print()
