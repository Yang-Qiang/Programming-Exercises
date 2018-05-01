#!/usr/bin/env python3
# coding=utf-8

import sys

count = 0;

def main(str1, str2):
    global count
    for i in range(0, len(str1) + 1):
        str = str1[:i] + str2 + str1[i:]
        if str == str[::-1]:
            count += 1

if __name__ == "__main__":
    main(sys.argv[1], sys.argv[2])
    print(count)
    
