#https://leetcode.com/problems/second-largest-digit-in-a-string/
#Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
#An alphanumeric string is a string consisting of lowercase English letters and digits.
# 
#Example 1:
#Input: s = "dfa12321afd"
#Output: 2
#Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
#Example 2:
#Input: s = "abc1111"
#Output: -1
#Explanation: The digits that appear in s are [1]. There is no second largest digit. 
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of only lowercase English letters and digits.
class Solution(object):
    def secondHighest(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize variables
        max_num = -1
        second_max_num = -1
        
        # Iterate over each character in the string
        for char in s:
            # Check if the character is a digit
            if char.isdigit():
                num = int(char)
                
                # Update max_num and second_max_num
                if num > max_num:
                    second_max_num = max_num
                    max_num = num
                elif num > second_max_num and num < max_num:
                    second_max_num = num
        
        # Return the second largest digit
        return second_max_num
        