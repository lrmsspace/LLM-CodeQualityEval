# You are given two strings word1 and word2.
# A string x is called valid if x can be rearranged to have word2 as a prefix.
# Return the total number of valid substrings of word1.
# Example 1:
# Input: word1 = "bcca", word2 = "abc"
# Output: 1
# Explanation:
# The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
# Example 2:
# Input: word1 = "abcabc", word2 = "abc"
# Output: 10
# Explanation:
# All the substrings except substrings of size 1 and size 2 are valid.
# Example 3:
# Input: word1 = "abcabc", word2 = "aaabc"
# Output: 0
# Constraints:
# 1 <= word1.length <= 105
# 1 <= word2.length <= 104
# word1 and word2 consist only of lowercase English letters.

class Solution(object):
    def validSubstringCount(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        from collections import Counter

        count_word2 = Counter(word2)
        len_word2 = len(word2)
        valid_count = 0
        current_count = Counter()

        left = 0
        for right in range(len(word1)):
            current_count[word1[right]] += 1
            
            while (right - left + 1) > len_word2:
                current_count[word1[left]] -= 1
                if current_count[word1[left]] == 0:
                    del current_count[word1[left]]
                left += 1
            
            if len(current_count) == len(count_word2) and all(current_count[char] >= count_word2[char] for char in count_word2):
                valid_count += (right - left + 1)

        return valid_count        