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
        if numRows == 1: return s
        n = len(s)
        k = 2 * (numRows - 1)
        res = [''] * numRows
        for i in range(n):
            rem = i % k
            if rem < numRows:
                res[rem] += s[i]
            else:
                res[k - rem] += s[i]
        return ''.join(res)