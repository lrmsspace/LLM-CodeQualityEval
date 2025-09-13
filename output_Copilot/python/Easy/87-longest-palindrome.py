#https://leetcode.com/problems/longest-palindrome/
#Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
#Letters are case sensitive, for example, "Aa" is not considered a palindrome.
# 
#Example 1:
#Input: s = "abccccdd"
#Output: 7
#Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
#Example 2:
#Input: s = "a"
#Output: 1
#Explanation: The longest palindrome that can be built is "a", whose length is 1.
# 
#Constraints:
#	1 <= s.length <= 2000
#	s consists of lowercase and/or uppercase English letters only.
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        odd_found = False
        char_count = {}
        
        # Count the occurrences of each character
        for char in s:
            if char in char_count:
                char_count[char] += 1
            else:
                char_count[char] = 1
        
        # Calculate the length of the longest palindrome
        for count in char_count.values():
            if count % 2 == 0:
                count += count
            else:
                count += count - 1
                odd_found = True
        
        # If there was an odd character, we can add one more to the palindrome length
        if odd_found:
            count += 1
        
        return count        