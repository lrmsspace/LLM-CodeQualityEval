# Given a string s containing only digits, return the lexicographically smallest string that can be obtained after swapping adjacent digits in s with the same parity at most once.
# Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.
# Example 1:
# Input: s = "45320"
# Output: "43520"
# Explanation: 
# s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.
# Example 2:
# Input: s = "001"
# Output: "001"
# Explanation:
# There is no need to perform a swap because s is already the lexicographically smallest.
# Constraints:
# 2 <= s.length <= 100
# s consists only of digits.

class Solution(object):
    def getSmallestString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Convert the string to a list of digits
        digits = list(map(int, s))
        
        # Find the index of the first non-zero digit from the end
        i = len(digits) - 1
        while i >= 0 and digits[i] == 0:
            i -= 1
        
        # If there is no non-zero digit, return the original string
        if i == -1:
            return s
        
        # Find the smallest digit from the end that can be swapped with the digit at index i
        j = len(digits) - 1
        while j > i and (digits[j] % 2 == 0) == (digits[i] % 2 == 0):
            j -= 1
        
        # Swap the digits
        digits[i], digits[j] = digits[j], digits[i]
        
        # Convert the list of digits back to a string
        return ''.join(map(str, digits))
        