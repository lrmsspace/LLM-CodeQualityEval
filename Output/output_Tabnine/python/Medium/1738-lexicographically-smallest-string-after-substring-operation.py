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
        # Find the last index of each letter
        last_index = {c: i for i, c in enumerate(s)}
        
        # Iterate from the last character to the first character
        for i in range(len(s)-1, 0, -1):
            # If the current character is 'a', replace it with 'z'
            if s[i] == 'a':
                s = s[:i] + 'z' + s[i+1:]
                break
            # If the current character is not 'a', find the previous 'a'
            else:
                prev_a_index = last_index[s[i-1]]
                # Swap the current character with the previous 'a'
                s = s[:prev_a_index] + s[i] + s[prev_a_index+1:i] + s[prev_a_index] + s[i+1:]
                break
        return s
        