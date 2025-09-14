# You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
# Return the number of special letters in word.
# Example 1:
# Input: word = "aaAbcBC"
# Output: 3
# Explanation:
# The special characters in word are 'a', 'b', and 'c'.
# Example 2:
# Input: word = "abc"
# Output: 0
# Explanation:
# No character in word appears in uppercase.
# Example 3:
# Input: word = "abBCab"
# Output: 1
# Explanation:
# The only special character in word is 'b'.
# Constraints:
# 1 <= word.length <= 50
# word consists of only lowercase and uppercase English letters.

class Solution(object):
    def numberOfSpecialChars(self, word):
        """
        :type word: str
        :rtype: int
        """
        special_chars = set()
        seen_lower = set()
        seen_upper = set()
        
        for char in word:
            if char.islower():
                seen_lower.add(char)
            elif char.isupper():
                seen_upper.add(char)
        
        for char in seen_lower:
            if char.upper() in seen_upper:
                special_chars.add(char)
        
        return len(special_chars)
        