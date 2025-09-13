# You are given two strings, word1 and word2, of equal length. You need to transform word1 into word2.
# For this, divide word1 into one or more contiguous substrings. For each substring substr you can perform the following operations:
# Replace: Replace the character at any one index of substr with another lowercase English letter.
# Swap: Swap any two characters in substr.
# Reverse Substring: Reverse substr.
# Each of these counts as one operation and each character of each substring can be used in each type of operation at most once (i.e. no single index may be involved in more than one replace, one swap, or one reverse).
# Return the minimum number of operations required to transform word1 into word2.
# Example 1:
# Input: word1 = "abcdf", word2 = "dacbe"
# Output: 4
# Explanation:
# Divide word1 into "ab", "c", and "df". The operations are:
# For the substring "ab",
# Perform operation of type 3 on "ab" -> "ba".
# Perform operation of type 1 on "ba" -> "da".
# For the substring "c" do no operations.
# For the substring "df",
# Perform operation of type 1 on "df" -> "bf".
# Perform operation of type 1 on "bf" -> "be".
# Example 2:
# Input: word1 = "abceded", word2 = "baecfef"
# Output: 4
# Explanation:
# Divide word1 into "ab", "ce", and "ded". The operations are:
# For the substring "ab",
# Perform operation of type 2 on "ab" -> "ba".
# For the substring "ce",
# Perform operation of type 2 on "ce" -> "ec".
# For the substring "ded",
# Perform operation of type 1 on "ded" -> "fed".
# Perform operation of type 1 on "fed" -> "fef".
# Example 3:
# Input: word1 = "abcdef", word2 = "fedabc"
# Output: 2
# Explanation:
# Divide word1 into "abcdef". The operations are:
# For the substring "abcdef",
# Perform operation of type 3 on "abcdef" -> "fedcba".
# Perform operation of type 2 on "fedcba" -> "fedabc".
# Constraints:
# 1 <= word1.length == word2.length <= 100
# word1 and word2 consist only of lowercase English letters.

class Solution(object):
    def minOperations(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        # Create a dictionary to store the indices of each character in word1
        word1_indices = {}
        for i, c in enumerate(word1):
            if c not in word1_indices:
                word1_indices[c] = []
            word1_indices[c].append(i)

        # Create a dictionary to store the indices of each character in word2
        word2_indices = {}
        for i, c in enumerate(word2):
            if c not in word2_indices:
                word2_indices[c] = []
            word2_indices[c].append(i)

        # Initialize the result with 0
        result = 0

        # Iterate through the characters in word1
        for c in word1_indices:
            # If the character is not present in word2, return -1
            if c not in word2_indices:
                return -1

            # Calculate the minimum number of operations required to transform the characters in word1 into word2
            result += max(len(word1_indices[c]) - len(word2_indices[c]), 0)

        # Return the result
        return result
        