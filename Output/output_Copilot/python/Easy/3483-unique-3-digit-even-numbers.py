# You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.
# Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
# Example 1:
# Input: digits = [1,2,3,4]
# Output: 12
# Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.
# Example 2:
# Input: digits = [0,2,2]
# Output: 2
# Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.
# Example 3:
# Input: digits = [6,6,6]
# Output: 1
# Explanation: Only 666 can be formed.
# Example 4:
# Input: digits = [1,3,5]
# Output: 0
# Explanation: No even 3-digit numbers can be formed.
# Constraints:
# 3 <= digits.length <= 10
# 0 <= digits[i] <= 9

class Solution(object):
    def totalNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: int
        """
        from itertools import permutations
        
        # Filter out digits that can be used as the last digit (even digits)
        even_digits = [d for d in digits if d % 2 == 0]
        
        if not even_digits:
            return 0
        count = 0
        # Generate all permutations of length 3
        for perm in permutations(digits, 3):
            # Check if the last digit is even and the first digit is not zero
            if perm[2] in even_digits and perm[0] != 0:
                count += 1
        # Since permutations generates all arrangements, we need to divide by 6 (3!) to get distinct numbers
        return count // 6
        