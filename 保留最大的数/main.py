#!/usr/bin/python env
import sys

def save_max_num(nums, n):
    length = len(nums)
    i = 0
    while n > 0 and i < length -1 :
        if nums[i] > nums[i + 1]:
            i += 1
            continue

        nums.pop(i)
        n -= 1;
        if i > 0:
            i -= 1
    if n > 0:
        nums = nums[:-n]

    return ''.join(nums)


if __name__ == "__main__":
    nums = list(sys.argv[1])
    n = int(sys.argv[2])
    print save_max_num(nums, n)
