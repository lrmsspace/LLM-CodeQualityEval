#https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/
#Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "0110", n = 3
#Output: true
#Example 2:
#Input: s = "0110", n = 4
#Output: false
# 
#Constraints:
#	1 <= s.length <= 1000
#	s[i] is either '0' or '1'.
#	1 <= n <= 109
class Solution(object):
    def queryString(self, s, n):
        """
        :type s: str
        :type n: int
        :rtype: bool
        """
        # Convert the binary string to an integer
        s_int = int(s, 2)
        
        # Check if all numbers from 1 to n can be represented as substrings of s
        for i in range(1, n + 1):
            if (s_int & ((1 << len(s)) - 1)) < i:
                return False
            s_int >>= 1
        
        return True        