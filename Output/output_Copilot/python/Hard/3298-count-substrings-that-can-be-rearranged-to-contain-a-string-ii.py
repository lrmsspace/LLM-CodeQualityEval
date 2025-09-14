# You are given two strings word1 and word2.
# A string x is called valid if x can be rearranged to have word2 as a prefix.
# Return the total number of valid substrings of word1.
# Note that the memory limits in this problem are smaller than usual, so you must implement a solution with a linear runtime complexity.
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
# 1 <= word1.length <= 106
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

        # Count the frequency of characters in word2
        target_count = Counter(word2)
        target_length = len(word2)
        valid_count = 0

        # Sliding window to count valid substrings in word1
        current_count = Counter()
        left = 0

        for right in range(len(word1)):
            current_count[word1[right]] += 1
            
            # Check if the current window is valid
            while (right - left + 1) >= target_length:
                if all(current_count[char] >= target_count[char] for char in target_count):
                    valid_count += 1
                
                # Move the left pointer to shrink the window
                current_count[word1[left]] -= 1
                if current_count[word1[left]] == 0:
                    del current_count[word1[left]]
                left += 1

        return valid_count
        