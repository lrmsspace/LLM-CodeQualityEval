#https://leetcode.com/problems/find-unique-binary-string/
#Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
# 
#Example 1:
#Input: nums = ["01","10"]
#Output: "11"
#Explanation: "11" does not appear in nums. "00" would also be correct.
#Example 2:
#Input: nums = ["00","01"]
#Output: "11"
#Explanation: "11" does not appear in nums. "10" would also be correct.
#Example 3:
#Input: nums = ["111","011","001"]
#Output: "101"
#Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
# 
#Constraints:
#	n == nums.length
#	1 <= n <= 16
#	nums[i].length == n
#	nums[i] is either '0' or '1'.
#	All the strings of nums are unique.
class Solution(object):
    def findDifferentBinaryString(self, nums):
        """
        :type nums: List[str]
        :rtype: str
        """
        n = len(nums)
        # Initialize a set to store the binary strings in nums
        num_set = set(nums)
        
        # Iterate through all possible binary strings of length n
        for i in range(2**n):
            # Convert the integer i to a binary string of length n
            binary_string = bin(i)[2:].zfill(n)
            
            # If the binary string is not in the set, return it
            if binary_string not in num_set:
                return binary_string
        
        # If all binary strings are in the set, return an empty string (this case should not happen)
        return ""        