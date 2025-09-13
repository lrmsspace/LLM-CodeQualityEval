# You are given two positive integers n and k.
# An integer x is called k-palindromic if:
# x is a palindrome.
# x is divisible by k.
# An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.
# Return the count of good integers containing n digits.
# Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.
# Example 1:
# Input: n = 3, k = 5
# Output: 27
# Explanation:
# Some of the good integers are:
# 551 because it can be rearranged to form 515.
# 525 because it is already k-palindromic.
# Example 2:
# Input: n = 1, k = 4
# Output: 2
# Explanation:
# The two good integers are 4 and 8.
# Example 3:
# Input: n = 5, k = 6
# Output: 2468
# Constraints:
# 1 <= n <= 10
# 1 <= k <= 9

import itertools

class Solution(object):
    def countGoodIntegers(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def is_palindrome(x):
            s = str(x)
            return s == s[::-1]

        def is_k_palindromic(x):
            return x % k == 0 and is_palindrome(x)

        seen = set()
        digits = '0123456789'

        # 生成所有 n 位不带前导零的数字组合
        for num_tuple in itertools.product('123456789', repeat=1):  # 第一位非 0
            first_digit = num_tuple[0]
            remaining_length = n - 1
            for rest in itertools.product('0123456789', repeat=remaining_length):
                full_digits = first_digit + ''.join(rest)
                perm_set = set(itertools.permutations(full_digits))
                for perm in perm_set:
                    if perm[0] == '0':  # 跳过有前导零的排列
                        continue
                    num = int(''.join(perm))
                    if is_k_palindromic(num):
                        seen.add(full_digits)
                        break  # 找到一个合法排列即可

        return len(seen)