# You are given two strings, s and t.
# You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.
# Return the length of the longest palindrome that can be formed this way.
# Example 1:
# Input: s = "a", t = "a"
# Output: 2
# Explanation:
# Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.
# Example 2:
# Input: s = "abc", t = "def"
# Output: 1
# Explanation:
# Since all characters are different, the longest palindrome is any single character, so the answer is 1.
# Example 3:
# Input: s = "b", t = "aaaa"
# Output: 4
# Explanation:
# Selecting "aaaa" from t is the longest palindrome, so the answer is 4.
# Example 4:
# Input: s = "abcde", t = "ecdba"
# Output: 5
# Explanation:
# Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.
# Constraints:
# 1 <= s.length, t.length <= 1000
# s and t consist of lowercase English letters.

class Solution(object):
    def longestPalindrome(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        from collections import Counter

        # Count frequency of characters in both strings
        count_s = Counter(s)
        count_t = Counter(t)

        # Calculate the maximum length of palindrome
        max_length = 0
        odd_found = False

        for char in set(count_s.keys()).union(set(count_t.keys())):
            total_count = count_s[char] + count_t[char]
            if total_count % 2 == 0:
                max_length += total_count
            else:
                max_length += total_count - 1
                odd_found = True

        # If there's at least one odd character, we can add one more to the palindrome
        if odd_found:
            max_length += 1

        return max_length
        