# You are given a string word of size n, and an integer k such that k divides n.
# In one operation, you can pick any two indices i and j, that are divisible by k, then replace the substring of length k starting at i with the substring of length k starting at j. That is, replace the substring word[i..i + k - 1] with the substring word[j..j + k - 1].
# Return the minimum number of operations required to make word k-periodic.
# We say that word is k-periodic if there is some string s of length k such that word can be obtained by concatenating s an arbitrary number of times. For example, if word == “ababab”, then word is 2-periodic for s = "ab".
# Example 1:
# Input: word = "leetcodeleet", k = 4
# Output: 1
# Explanation:
# We can obtain a 4-periodic string by picking i = 4 and j = 0. After this operation, word becomes equal to "leetleetleet".
# Example 2:
# Input: word = "leetcoleet", k = 2
# Output: 3
# Explanation:
# We can obtain a 2-periodic string by applying the operations in the table below.
# i
# j
# word
# 0
# 2
# etetcoleet
# 4
# 0
# etetetleet
# 6
# 0
# etetetetet
# Constraints:
# 1 <= n == word.length <= 105
# 1 <= k <= word.length
# k divides word.length.
# word consists only of lowercase English letters.

class Solution(object):
    def minimumOperationsToMakeKPeriodic(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        # Check if the word is already k-periodic
        if word[:k] * (len(word) // k) == word:
            return 0
        
        # Find the first index where the word is not k-periodic
        for i in range(len(word) - k + 1):
            if word[:k]!= word[i:i+k]:
                break
        
        # Perform the operations to make the word k-periodic
        operations = 0
        for j in range(i + k, len(word), k):
            if word[:k]!= word[j:j+k]:
                operations += 1
                word = word[:j] + word[j:j+k] + word[j+k:]
        
        return operations
        