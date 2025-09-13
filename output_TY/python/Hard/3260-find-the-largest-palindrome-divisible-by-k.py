# You are given two positive integers n and k.
# An integer x is called k-palindromic if:
# x is a palindrome.
# x is divisible by k.
# Return the largest integer having n digits (as a string) that is k-palindromic.
# Note that the integer must not have leading zeros.
# Example 1:
# Input: n = 3, k = 5
# Output: "595"
# Explanation:
# 595 is the largest k-palindromic integer with 3 digits.
# Example 2:
# Input: n = 1, k = 4
# Output: "8"
# Explanation:
# 4 and 8 are the only k-palindromic integers with 1 digit.
# Example 3:
# Input: n = 5, k = 6
# Output: "89898"
# Constraints:
# 1 <= n <= 105
# 1 <= k <= 9

class Solution(object):
    def largestPalindrome(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        if n == 1:
            # 单个数字的情况，从9到1检查是否能被k整除
            for x in range(9, 0, -1):
                if x % k == 0:
                    return str(x)
        
        res = []
        
        # 奇偶长度分别处理
        is_odd = (n % 2 == 1)
        half_len = (n + 1) // 2
        
        # 构造最大回文的一半
        prefix = [9] * (half_len - 1) + [8]  # 初始为类似 998 的形式，避免一开始就全是9导致无法整除
        
        while True:
            s = ''.join(str(d) for d in prefix)
            rev_s = s if not is_odd else s[:-1][::-1]
            full_palindrome = s + rev_s
            
            if full_palindrome[0] == '0':
                prefix = [9] * (half_len - 1) + [7]
                continue

            num = int(full_palindrome)
            if num % k == 0:
                return full_palindrome
            
            # 减少最后一位，尝试下一个可能的回文
            i = half_len - 1
            while i >= 0 and prefix[i] == 0:
                prefix[i] = 9
                i -= 1
            if i < 0:
                break
            prefix[i] -= 1

        return "0" * n