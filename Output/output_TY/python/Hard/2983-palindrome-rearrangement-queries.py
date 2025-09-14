# You are given a 0-indexed string s having an even length n.
# You are also given a 0-indexed 2D integer array, queries, where queries[i] = [ai, bi, ci, di].
# For each query i, you are allowed to perform the following operations:
# Rearrange the characters within the substring s[ai:bi], where 0 <= ai <= bi < n / 2.
# Rearrange the characters within the substring s[ci:di], where n / 2 <= ci <= di < n.
# For each query, your task is to determine whether it is possible to make s a palindrome by performing the operations.
# Each query is answered independently of the others.
# Return a 0-indexed array answer, where answer[i] == true if it is possible to make s a palindrome by performing operations specified by the ith query, and false otherwise.
# A substring is a contiguous sequence of characters within a string.
# s[x:y] represents the substring consisting of characters from the index x to index y in s, both inclusive.
# Example 1:
# Input: s = "abcabc", queries = [[1,1,3,5],[0,2,5,5]]
# Output: [true,true]
# Explanation: In this example, there are two queries:
# In the first query:
# - a0 = 1, b0 = 1, c0 = 3, d0 = 5.
# - So, you are allowed to rearrange s[1:1] => abcabc and s[3:5] => abcabc.
# - To make s a palindrome, s[3:5] can be rearranged to become => abccba.
# - Now, s is a palindrome. So, answer[0] = true.
# In the second query:
# - a1 = 0, b1 = 2, c1 = 5, d1 = 5.
# - So, you are allowed to rearrange s[0:2] => abcabc and s[5:5] => abcabc.
# - To make s a palindrome, s[0:2] can be rearranged to become => cbaabc.
# - Now, s is a palindrome. So, answer[1] = true.
# Example 2:
# Input: s = "abbcdecbba", queries = [[0,2,7,9]]
# Output: [false]
# Explanation: In this example, there is only one query.
# a0 = 0, b0 = 2, c0 = 7, d0 = 9.
# So, you are allowed to rearrange s[0:2] => abbcdecbba and s[7:9] => abbcdecbba.
# It is not possible to make s a palindrome by rearranging these substrings because s[3:6] is not a palindrome.
# So, answer[0] = false.
# Example 3:
# Input: s = "acbcab", queries = [[1,2,4,5]]
# Output: [true]
# Explanation: In this example, there is only one query.
# a0 = 1, b0 = 2, c0 = 4, d0 = 5.
# So, you are allowed to rearrange s[1:2] => acbcab and s[4:5] => acbcab.
# To make s a palindrome s[1:2] can be rearranged to become abccab.
# Then, s[4:5] can be rearranged to become abccba.
# Now, s is a palindrome. So, answer[0] = true.
# Constraints:
# 2 <= n == s.length <= 105
# 1 <= queries.length <= 105
# queries[i].length == 4
# ai == queries[i][0], bi == queries[i][1]
# ci == queries[i][2], di == queries[i][3]
# 0 <= ai <= bi < n / 2
# n / 2 <= ci <= di < n 
# n is even.
# s consists of only lowercase English letters.

from collections import Counter
from typing import List

class Solution(object):
    def canMakePalindromeQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        n = len(s)
        mid = n // 2

        # 计算前缀和的字符计数
        prefix = [Counter()]
        for i in range(n):
            cnt = prefix[-1].copy()
            cnt[s[i]] += 1
            prefix.append(cnt)

        def get_count(l, r):
            """获取 s[l:r+1] 的字符计数"""
            res = Counter()
            for ch in set(prefix[r + 1]) | set(prefix[l]):
                res[ch] = prefix[r + 1][ch] - prefix[l][ch]
            return res

        left_count = get_count(0, mid - 1)
        right_count = get_count(mid, n - 1)

        res = [False] * len(queries)

        for i, (a, b, c, d) in enumerate(queries):
            fixed_left = (0, a - 1)
            fixed_right = (d + 1, n - 1)
            var_left = (a, b)
            var_right = (c, d)

            # 获取固定区域的字符分布
            fixed_left_cnt = get_count(fixed_left[0], fixed_left[1])
            fixed_right_cnt = get_count(fixed_right[0], fixed_right[1])

            # 固定区域的字符差值
            diff = Counter()
            for ch in set(fixed_left_cnt) | set(fixed_right_cnt):
                rev_ch = ch  # 因为是对称位置，所以字符本身要匹配
                diff[rev_ch] += fixed_left_cnt[ch]
                diff[rev_ch] -= fixed_right_cnt[ch]

            # 检查变量区域是否可以弥补这个差值
            var_left_cnt = get_count(var_left[0], var_left[1])
            var_right_cnt = get_count(var_right[0], var_right[1])

            # 先尝试用左边变量区补负数
            for ch in diff:
                need = diff[ch]
                if need < 0:
                    use = min(-need, var_left_cnt[ch])
                    var_left_cnt[ch] -= use
                    diff[ch] += use

            # 再尝试用右边变量区补正数
            for ch in diff:
                need = diff[ch]
                if need > 0:
                    use = min(need, var_right_cnt[ch])
                    var_right_cnt[ch] -= use
                    diff[ch] -= use

            # 最终检查是否所有差值都为 0
            valid = all(v == 0 for v in diff.values())
            res[i] = valid

        return res