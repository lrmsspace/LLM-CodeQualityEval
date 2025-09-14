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
        # Count the frequency of each digit
        count = [0] * 10
        total_sum = 0
        for digit in digits:
            count[digit] += 1
            total_sum += digit

        # Helper function to remove digits
        def remove_digits(remainder, count):
            for i in range(1, 10):
                if count[i] > 0 and i % 3 == remainder:
                    count[i] -= 1
                    return True
            return False

        # Remove digits to make the sum a multiple of 3
        if total_sum % 3 == 1:
            if not remove_digits(1, count):
                remove_digits(2, count)
                remove_digits(2, count)
        elif total_sum % 3 == 2:
            if not remove_digits(2, count):
                remove_digits(1, count)
                remove_digits(1, count)

        # Construct the largest number
        result = []
        for i in range(9, -1, -1):
            result.extend([str(i)] * count[i])

        # Remove leading zeros and return the result
        if result and result[0] == '0':
            return '0'
        return ''.join(result)

