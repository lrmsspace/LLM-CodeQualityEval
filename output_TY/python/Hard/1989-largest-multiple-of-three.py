#https://leetcode.com/problems/largest-multiple-of-three/
#Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
#Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.
# 
#Example 1:
#Input: digits = [8,1,9]
#Output: "981"
#Example 2:
#Input: digits = [8,6,7,1,0]
#Output: "8760"
#Example 3:
#Input: digits = [1]
#Output: ""
# 
#Constraints:
#	1 <= digits.length <= 104
#	0 <= digits[i] <= 9
class Solution(object):
    def largestMultipleOfThree(self, digits):
        """
        :type digits: List[int]
        :rtype: str
        """
        d = [0]*10
        for i in digits:
            d[i] += 1
            if i%3 == 0:
                d[i] -= 1
        for i in range(9,-1,-1):
            if i%3 == 1:
                for j in range(d[i]):
                    if d[i] > 0:
                        d[i] -= 1
                        d[i] += 1
            elif i%3 == 2:
                for j in range(d[i]):
                    if d[i] > 0:
                        d[i] -= 1
                        d[i] += 1
        ans = ""
        for i in range(9,-1,-1):
            for j in range(d[i]):
                ans += str(i)
        if ans == "":
            return ans
        else:
            return ans[0:len(ans)-1]
        return ans
