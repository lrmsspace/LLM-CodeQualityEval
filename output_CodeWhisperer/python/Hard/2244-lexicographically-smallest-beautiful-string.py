#https://leetcode.com/problems/lexicographically-smallest-beautiful-string/
#A string is beautiful if:
#	It consists of the first k letters of the English lowercase alphabet.
#	It does not contain any substring of length 2 or more which is a palindrome.
#You are given a beautiful string s of length n and a positive integer k.
#Return the lexicographically smallest string of length n, which is larger than s and is beautiful. If there is no such string, return an empty string.
#A string a is lexicographically larger than a string b (of the same length) if in the first position where a and b differ, a has a character strictly larger than the corresponding character in b.
#	For example, "abcd" is lexicographically larger than "abcc" because the first position they differ is at the fourth character, and d is greater than c.
# 
#Example 1:
#Input: s = "abcz", k = 26
#Output: "abda"
#Explanation: The string "abda" is beautiful and lexicographically larger than the string "abcz".
#It can be proven that there is no string that is lexicographically larger than the string "abcz", beautiful, and lexicographically smaller than the string "abda".
#Example 2:
#Input: s = "dc", k = 4
#Output: ""
#Explanation: It can be proven that there is no string that is lexicographically larger than the string "dc" and is beautiful.
# 
#Constraints:
#	1 <= n == s.length <= 105
#	4 <= k <= 26
#	s is a beautiful string.
class Solution(object):
    def smallestBeautifulString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        n = len(s)
        for i in range(n - 1, -1, -1):
            for c in range(ord(s[i]) + 1, ord('a') + k):
                if (i - 1 < 0 or ord(s[i - 1]) != c) and (i - 2 < 0 or ord(s[i - 2]) != c):
                    s = s[:i] + chr(c) + 'a' * (n - i - 1)
                    for j in range(i + 1, n):
                        for d in range(ord(s[j - 1]) + 1, ord('a') + k):
                            if (j - 1 < 0 or ord(s[j - 1]) != d) and (j - 2 < 0 or ord(s[j - 2]) != d):
                                s = s[:j] + chr(d) + s[j + 1:]
                                return s
                    return s
        return ""

        