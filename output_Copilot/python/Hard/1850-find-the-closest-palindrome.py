#https://leetcode.com/problems/find-the-closest-palindrome/
#Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
#The closest is defined as the absolute difference minimized between two integers.
# 
#Example 1:
#Input: n = "123"
#Output: "121"
#Example 2:
#Input: n = "1"
#Output: "0"
#Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
# 
#Constraints:
#	1 <= n.length <= 18
#	n consists of only digits.
#	n does not have leading zeros.
#	n is representing an integer in the range [1, 1018 - 1].
class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        # 生成所有可能的回文数
        candidates = set()
        length = len(n)
        prefix = int(n[:(length + 1) // 2])    
        for i in [-1, 0, 1]:
            new_prefix = str(int(prefix) + i)
            if length % 2 == 0:
                candidates.add(new_prefix + new_prefix[::-1])
            else:
                candidates.add(new_prefix + new_prefix[-2::-1])
        candidates.add('9' * (length - 1))
        candidates.add('1' + '0' * (length - 1) + '1')
        candidates.discard(n)
        # 找到最接近的回文数
        closest = None
        min_diff = float('inf')
        for candidate in candidates:
            diff = abs(int(candidate) - int(n))
            if diff < min_diff or (diff == min_diff and int(candidate) < int(closest)):
                closest = candidate
                min_diff = diff
        return closest    