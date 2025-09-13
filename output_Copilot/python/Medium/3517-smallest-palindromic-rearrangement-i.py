# You are given a palindromic string s.
# Return the lexicographically smallest palindromic permutation of s.
# Example 1:
# Input: s = "z"
# Output: "z"
# Explanation:
# A string of only one character is already the lexicographically smallest palindrome.
# Example 2:
# Input: s = "babab"
# Output: "abbba"
# Explanation:
# Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
# Example 3:
# Input: s = "daccad"
# Output: "acddca"
# Explanation:
# Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
# Constraints:
# 1 <= s.length <= 105
# s consists of lowercase English letters.
# s is guaranteed to be palindromic.

class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        # Count the frequency of each character
        char_count = Counter(s)

        # Create a list for the left half of the palindrome
        left_half = []

        # Find the middle character (if any)
        middle_char = ""
        for char in sorted(char_count.keys()):
            count = char_count[char]
            # If the count is odd, we can use one occurrence as the middle character
            if count % 2 == 1 and middle_char == "":
                middle_char = char
            # Add half of the even occurrences to the left half
            left_half.append(char * (count // 2))

        # Form the smallest palindrome
        left_half = "".join(left_half)
        right_half = left_half[::-1]
        return left_half + middle_char + right_half
