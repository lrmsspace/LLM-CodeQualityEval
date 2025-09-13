#https://leetcode.com/problems/shortest-palindrome/
#You are given a string s. You can convert s to a palindrome by adding characters in front of it.
#Return the shortest palindrome you can find by performing this transformation.
# 
#Example 1:
#Input: s = "aacecaaa"
#Output: "aaacecaaa"
#Example 2:
#Input: s = "abcd"
#Output: "dcbabcd"
# 
#Constraints:
#	0 <= s.length <= 5 * 104
#	s consists of lowercase English letters only.
class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 1. Reverse the string s
        rev_s = s[::-1]

        # 2. Concatenate s and rev_s with a separator
        combined = s + "#" + rev_s

        # 3. Compute the prefix function (KMP algorithm)
        n = len(combined)
        lps = [0] * n
        j = 0
        for i in range(1, n):
            while j > 0 and combined[i] != combined[j]:
                j = lps[j - 1]
            if combined[i] == combined[j]:
                j += 1
            lps[i] = j

        # 4. The length of the longest palindromic prefix
        longest_palindrome_length = lps[-1]
        # 5. Append the remaining characters from rev_s to s
        remaining = rev_s[:len(s) - longest_palindrome_length]
        # 6. Return the shortest palindrome
        return remaining + s    