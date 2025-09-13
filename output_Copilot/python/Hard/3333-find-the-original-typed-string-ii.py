# Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
# You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
# Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
# Since the answer may be very large, return it modulo 109 + 7.
# Example 1:
# Input: word = "aabbccdd", k = 7
# Output: 5
# Explanation:
# The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
# Example 2:
# Input: word = "aabbccdd", k = 8
# Output: 1
# Explanation:
# The only possible string is "aabbccdd".
# Example 3:
# Input: word = "aaabbb", k = 3
# Output: 8
# Constraints:
# 1 <= word.length <= 5 * 105
# word consists only of lowercase English letters.
# 1 <= k <= 2000

class Solution(object):
    def possibleStringCount(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(word)
        
        # Count the frequency of each character in the word
        freq = {}
        for char in word:
            if char in freq:
                freq[char] += 1
            else:
                freq[char] = 1
        
        # Calculate the number of distinct characters
        distinct_count = len(freq)
        
        # If the length of the word is less than k, return 0
        if n < k:
            return 0
        
        # Calculate the number of possible original strings
        result = 1
        for count in freq.values():
            result *= (count + 1)

        # If the number of distinct characters is less than k, return 0
        if distinct_count < k:
            return 0

        # Return the result modulo 10^9 + 7
        return result % MOD
