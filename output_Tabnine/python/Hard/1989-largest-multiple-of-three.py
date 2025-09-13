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
        # Sort the digits in descending order
        digits.sort(reverse=True)
        
        # Initialize the sum and the count of each digit
        total, count = 0, [0] * 10
        
        # Count the frequency of each digit
        for digit in digits:
            count[digit] += 1
        
        # Calculate the sum of the digits
        for i in range(1, 10):
            total += i * count[i]
        
        # Check if the sum is divisible by 3
        if total % 3 == 0:
            # Construct the largest multiple of three
            result = ""
            for i in range(9, -1, -1):
                while count[i] > 0 and total >= i:
                    result += str(i)
                    total -= i
                    count[i] -= 1
            
            # Remove unnecessary leading zeros
            while result and result[0] == '0':
                result = result[1:]
        
        return result
        