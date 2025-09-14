# You are given two strings word1 and word2.
# A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
# A sequence of indices seq is called valid if:
# The indices are sorted in ascending order.
# Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
# Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.
# Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.
# Example 1:
# Input: word1 = "vbcca", word2 = "abc"
# Output: [0,1,2]
# Explanation:
# The lexicographically smallest valid sequence of indices is [0, 1, 2]:
# Change word1[0] to 'a'.
# word1[1] is already 'b'.
# word1[2] is already 'c'.
# Example 2:
# Input: word1 = "bacdc", word2 = "abc"
# Output: [1,2,4]
# Explanation:
# The lexicographically smallest valid sequence of indices is [1, 2, 4]:
# word1[1] is already 'a'.
# Change word1[2] to 'b'.
# word1[4] is already 'c'.
# Example 3:
# Input: word1 = "aaaaaa", word2 = "aaabc"
# Output: []
# Explanation:
# There is no valid sequence of indices.
# Example 4:
# Input: word1 = "abc", word2 = "ab"
# Output: [0,1]
# Constraints:
# 1 <= word2.length < word1.length <= 3 * 105
# word1 and word2 consist only of lowercase English letters.

class Solution(object):
    def validSequence(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: List[int]
        """
        n = len(word1)
        m = len(word2)
        
        # Initialize a 2D dp array with False values
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        
        # Initialize a dictionary to store the last index of each character in word1
        last_index = {}
        
        # Iterate through word1 and word2 in reverse order
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                # If the characters are equal, set the dp value at the current indices to True
                if word1[i] == word2[j]:
                    dp[i][j] = True
                    # Update the last index of the current character in word1
                    last_index[word1[i]] = i
        # Initialize a list to store the valid sequence of indices
        sequence = []
        
        # Iterate through word2 in reverse order
        for i in range(m - 1, -1, -1):
            # If the current character exists in word1 and the dp value at the last index of the character is True
            if word2[i] in last_index and dp[last_index[word2[i]] + 1][i]:
                # Add the current index to the sequence
                sequence.append(last_index[word2[i]])
                # Update the last index of the current character in word1
                last_index[word2[i]] += 1
            # If no valid sequence is found, return an empty list
            else:
                return []
        
        # Reverse the sequence to get the lexicographically smallest valid sequence of indices
        sequence.reverse()
        
        return sequence
        