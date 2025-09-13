#https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
#Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
# 
#Example 1:
#Input: s = "00110110", k = 2
#Output: true
#Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
#Example 2:
#Input: s = "0110", k = 1
#Output: true
#Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
#Example 3:
#Input: s = "0110", k = 2
#Output: false
#Explanation: The binary code "00" is of length 2 and does not exist in the array.
# 
#Constraints:
#	1 <= s.length <= 5 * 105
#	s[i] is either '0' or '1'.
#	1 <= k <= 20
class Solution(object):
    def hasAllCodes(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        # Create a set to store all possible binary codes of length k
        codes = set()
        
        # Initialize a variable to store the current binary code
        current_code = ""
        
        # Iterate through the given binary string
        for char in s:
            # Append the current character to the current code
            current_code += char
            
            # If the current code has length k, add it to the set of codes
            if len(current_code) == k:
                codes.add(current_code)
        
        # Return True if all possible binary codes of length k exist in the given string, otherwise False
        return len(codes) == 2 ** k
        