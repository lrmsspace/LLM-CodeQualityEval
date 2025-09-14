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

        special_chars = set()
        seen_lower = set()
        seen_upper = set()

        for c in word:
            if c.islower():
                seen_lower.add(c)
            elif c.isupper():
                seen_upper.add(c.lower())

        for c in seen_lower:
            if c in seen_upper:
                special_chars.add(c)

        return len(special_chars)