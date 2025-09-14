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
        n = len(s)
        i = 0
        
        # Find the first character that is not 'a' to start the operation
        while i < n and s[i] == 'a':
            i += 1
        
        # If all characters are 'a', change the last one to 'z'
        if i == n:
            return s[:n-1] + 'z'
        
        # Change characters from the first non-'a' to the next 'a' or end of string
        result = list(s)
        while i < n and s[i] != 'a':
            result[i] = chr(ord(s[i]) - 1)
            i += 1
        
        return ''.join(result)

