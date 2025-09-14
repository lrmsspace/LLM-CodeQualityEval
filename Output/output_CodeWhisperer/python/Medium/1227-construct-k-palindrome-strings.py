#https://leetcode.com/problems/construct-k-palindrome-strings/
#Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
# 
#Example 1:
#Input: s = "annabelle", k = 2
#Output: true
#Explanation: You can construct two palindromes using all characters in s.
#Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
#Example 2:
#Input: s = "leetcode", k = 3
#Output: false
#Explanation: It is impossible to construct 3 palindromes using all the characters of s.
#Example 3:
#Input: s = "true", k = 4
#Output: true
#Explanation: The only possible solution is to put each character in a separate string.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of lowercase English letters.
#	1 <= k <= 105
class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        if len(s) < k:
            return False
        
        char_count = {}
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        odd_count = 0
        for count in char_count.values():
            if count % 2 != 0:
                odd_count += 1
        
        return odd_count <= k
        