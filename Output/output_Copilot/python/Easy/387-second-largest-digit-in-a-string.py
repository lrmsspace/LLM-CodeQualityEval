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
        # Initialize a set to store unique digits
        digits = set()
        
        # Iterate through each character in the string
        for char in s:
            # If the character is a digit, add it to the set
            if char.isdigit():
                digits.add(int(char))
        
        # Convert the set to a sorted list in descending order
        sorted_digits = sorted(digits, reverse=True)
        
        # If there are at least two unique digits, return the second largest
        if len(sorted_digits) >= 2:
            return sorted_digits[1]
        
        # Otherwise, return -1
        return -1        