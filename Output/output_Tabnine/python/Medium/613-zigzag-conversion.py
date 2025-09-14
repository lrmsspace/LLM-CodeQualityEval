#https://leetcode.com/problems/zigzag-conversion/
#The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
#P   A   H   N
#A P L S I I G
#Y   I   R
#And then read line by line: "PAHNAPLSIIGYIR"
#Write the code that will take a string and make this conversion given a number of rows:
#string convert(string s, int numRows);
# 
#Example 1:
#Input: s = "PAYPALISHIRING", numRows = 3
#Output: "PAHNAPLSIIGYIR"
#Example 2:
#Input: s = "PAYPALISHIRING", numRows = 4
#Output: "PINALSIGYAHRPI"
#Explanation:
#P     I    N
#A   L S  I G
#Y A   H R
#P     I
#Example 3:
#Input: s = "A", numRows = 1
#Output: "A"
# 
#Constraints:
#	1 <= s.length <= 1000
#	s consists of English letters (lower-case and upper-case), ',' and '.'.
#	1 <= numRows <= 1000
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        # Check if the number of rows is 1 or the string is empty
        if numRows == 1 or not s:
            return s
        
        # Initialize the result string and the current row index
        result = ""
        row = 0
        
        # Determine the direction of the zigzag pattern
        direction = 1
        
        # Iterate through each character in the input string
        for char in s:
            # Append the character to the current row
            result += char
            
            # Check if the current row is at the top or bottom of the zigzag pattern
            if row == 0 or row == numRows - 1:
                # Change the direction of the zigzag pattern
                direction *= -1
            
            # Move to the next row
            row += direction
        
        return result
        