# You are given an integer array nums containing positive integers. We define a function encrypt such that encrypt(x) replaces every digit in x with the largest digit in x. For example, encrypt(523) = 555 and encrypt(213) = 333.
# Return the sum of encrypted elements.
# Example 1:
# Input: nums = [1,2,3]
# Output: 6
# Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.
# Example 2:
# Input: nums = [10,21,31]
# Output: 66
# Explanation: The encrypted elements are [11,22,33]. The sum of encrypted elements is 11 + 22 + 33 == 66.
# Constraints:
# 1 <= nums.length <= 50
# 1 <= nums[i] <= 1000

class Solution(object):
    def sumOfEncryptedInt(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for num in nums:
            max_digit = 0
            n = num
            while n > 0:
                digit = n % 10
                if digit > max_digit:
                    max_digit = digit
                n //= 10
            encrypted_num = 0
            power = 1
            n = num
            while n > 0:
                encrypted_num += max_digit * power
                power *= 10
                n //= 10
            result += encrypted_num
        return result
