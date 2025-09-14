#https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
#Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.
# 
#Example 1:
#Input: s = "1001"
#Output: false
#Explanation: The ones do not form a contiguous segment.
#Example 2:
#Input: s = "110"
#Output: true
# 
#Constraints:
#	1 <= s.length <= 100
#	s[i]​​​​ is either '0' or '1'.
#	s[0] is '1'.
class Solution(object):
    def checkOnesSegment(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Initialize count of ones and flag to indicate the presence of a segment of ones
        count, has_segment = 0, False
        
        # Iterate through the binary string
        for char in s:
            # If the current character is '1', increment the count
            if char == '1':
                count += 1
            # If the count exceeds 1, set the flag to True
            else:
                if count > 1:
                    has_segment = True
                count = 0
        
        # Check if the last segment of ones has more than one '1'
        if count > 1:
            has_segment = True
        
        # Return the result
        return not has_segment
        