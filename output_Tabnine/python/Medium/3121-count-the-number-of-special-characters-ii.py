# You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
# Return the number of special letters in word.
# Example 1:
# Input: word = "aaAbcBC"
# Output: 3
# Explanation:
# The special characters are 'a', 'b', and 'c'.
# Example 2:
# Input: word = "abc"
# Output: 0
# Explanation:
# There are no special characters in word.
# Example 3:
# Input: word = "AbBCab"
# Output: 0
# Explanation:
# There are no special characters in word.
# Constraints:
# 1 <= word.length <= 2 * 105
# word consists of only lowercase and uppercase English letters.

class Solution(object):
    def numberOfSpecialChars(self, word):
        """
        :type word: str
        :rtype: int
        """
        lower_count = 0
        upper_count = 0
        special_count = 0
        
        for c in word:
            if c.islower():
                lower_count += 1
            elif c.isupper():
                upper_count += 1
            else:
                special_count += 1
        
        return min(lower_count, upper_count, special_count)
        