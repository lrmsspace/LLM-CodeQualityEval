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
        # Initialize a dictionary to count the occurrences of each character in the string
        char_count = {}
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        # Initialize variables to keep track of the longest palindrome length and the number of unique characters
        max_length = 0
        unique_count = 0
        
        # Iterate through the character count dictionary
        for count in char_count.values():
            # If the count is odd, increment the unique_count by 1 and add 1 to the max_length
            if count % 2 == 1:
                unique_count += 1
                max_length += 1
            # If the count is even, increment the max_length by the count
            else:
                max_length += count
        
        # If there is only one unique character, add 1 to the max_length
        if unique_count == 1:
            max_length += 1
        
        return max_length
        