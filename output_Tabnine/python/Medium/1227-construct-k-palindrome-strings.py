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
        # Count the frequency of each character in s
        freq = [0] * 26
        for char in s:
            freq[ord(char) - ord('a')] += 1
        
        # If the number of characters is not divisible by k, return False
        if len(s) % k!= 0:
            return False
        
        # Calculate the maximum frequency
        max_freq = max(freq)
        
        # If there are characters with a frequency greater than max_freq/2, return False
        for freq in freq:
            if freq > max_freq // 2:
                return False
        
        # If all conditions are satisfied, return True
        return True
        