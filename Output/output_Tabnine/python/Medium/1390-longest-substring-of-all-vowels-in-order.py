#https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
#A string is considered beautiful if it satisfies the following conditions:
#	Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
#	The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
#For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
#Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.
#A substring is a contiguous sequence of characters in a string.
# 
#Example 1:
#Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
#Output: 13
#Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
#Example 2:
#Input: word = "aeeeiiiioooauuuaeiou"
#Output: 5
#Explanation: The longest beautiful substring in word is "aeiou" of length 5.
#Example 3:
#Input: word = "a"
#Output: 0
#Explanation: There is no beautiful substring, so return 0.
# 
#Constraints:
#	1 <= word.length <= 5 * 105
#	word consists of characters 'a', 'e', 'i', 'o', and 'u'.
class Solution(object):
    def longestBeautifulSubstring(self, word):
        """
        :type word: str
        :rtype: int
        """
        # Initialize variables
        vowels = 'aeiou'
        max_length = 0
        current_length = 0
        last_vowel_index = -1
        
        # Iterate through the word
        for i, char in enumerate(word):
            # If the current character is a vowel
            if char in vowels:
                # If the current character is the first vowel or the last vowel index is less than the current index
                if last_vowel_index == -1 or i - last_vowel_index > current_length:
                    current_length += 1
                # If the current character is not the first vowel but the last vowel index is equal to the current index
                elif i - last_vowel_index == current_length:
                    current_length += 1
                # If the current character is not a vowel
                else:
                    # Update the maximum length if necessary
                    max_length = max(max_length, current_length)
                    current_length = 1
                # Update the last vowel index
                last_vowel_index = i
            # If the current character is not a vowel
            else:
                # Reset the current length and the last vowel index
                current_length = 0
                last_vowel_index = -1
        
        # Update the maximum length if necessary
        max_length = max(max_length, current_length)
        
        return max_length
        