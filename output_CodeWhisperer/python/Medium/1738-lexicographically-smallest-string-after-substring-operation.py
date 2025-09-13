#https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/
#Given a string s consisting of lowercase English letters. Perform the following operation:
#	Select any non-empty substring then replace every letter of the substring with the preceding letter of the English alphabet. For example, 'b' is converted to 'a', and 'a' is converted to 'z'.
#Return the lexicographically smallest string after performing the operation.
# 
#Example 1:
#Input: s = "cbabc"
#Output: "baabc"
#Explanation:
#Perform the operation on the substring starting at index 0, and ending at index 1 inclusive.
#Example 2:
#Input: s = "aa"
#Output: "az"
#Explanation:
#Perform the operation on the last letter.
#Example 3:
#Input: s = "acbbc"
#Output: "abaab"
#Explanation:
#Perform the operation on the substring starting at index 1, and ending at index 4 inclusive.
#Example 4:
#Input: s = "leetcode"
#Output: "kddsbncd"
#Explanation:
#Perform the operation on the entire string.
# 
#Constraints:
#	1 <= s.length <= 3 * 105
#	s consists of lowercase English letters
class Solution(object):
    def smallestString(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        i = 0
        while i < len(s) and s[i] == 'a':
            i += 1
        while i < len(s) and s[i] != 'a':
            s[i] = chr(ord(s[i]) - 1)
            i += 1
        return ''.join(s)
        