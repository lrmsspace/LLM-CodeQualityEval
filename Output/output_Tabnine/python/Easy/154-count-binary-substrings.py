#https://leetcode.com/problems/count-binary-substrings/
#Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
#Substrings that occur multiple times are counted the number of times they occur.
# 
#Example 1:
#Input: s = "00110011"
#Output: 6
#Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
#Notice that some of these substrings repeat and are counted the number of times they occur.
#Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
#Example 2:
#Input: s = "10101"
#Output: 4
#Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
# 
#Constraints:
#	1 <= s.length <= 105
#	s[i] is either '0' or '1'.
class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize result and count variables
        result, count = 0, 1
        
        # Iterate through the string, comparing current character with the next one
        for i in range(1, len(s)):
            # If current character is same as next one, increment count
            if s[i] == s[i-1]:
                count += 1
            # If current character is different from next one, check if count is greater than 1
            else:
                # If count is greater than 1, add count to result and reset count to 2
                if count > 1:
                    result += count
                count = 2
        
        # After the last character, check if count is greater than 1
        if count > 1:
            result += count
        
        return result
        