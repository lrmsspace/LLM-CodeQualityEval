#https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
#You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
#Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
# 
#Example 1:
#Input: s = "aabaaaacaabc", k = 2
#Output: 8
#Explanation: 
#Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
#Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
#A total of 3 + 5 = 8 minutes is needed.
#It can be proven that 8 is the minimum number of minutes needed.
#Example 2:
#Input: s = "a", k = 1
#Output: -1
#Explanation: It is not possible to take one 'b' or 'c' so return -1.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of only the letters 'a', 'b', and 'c'.
#	0 <= k <= s.length
class Solution(object):
    def takeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        a, b, c = s.count('a'), s.count('b'), s.count('c')
        if a < k or b < k or c < k:
            return -1
        
        res = 0
        left, right = 0, len(s) - 1
        while a < k or b < k or c < k:
            if s[left] == 'a' and a < k:
                a += 1
                left += 1
            elif s[right] == 'a' and a < k:
                a += 1
                right -= 1
            if s[left] == 'b' and b < k:
                b += 1
                left += 1
            elif s[right] == 'b' and b < k:
                b += 1
                right -= 1
            if s[left] == 'c' and c < k:
                c += 1
                left += 1
            elif s[right] == 'c' and c < k:
                c += 1
                right -= 1
            res += 1
        return res
