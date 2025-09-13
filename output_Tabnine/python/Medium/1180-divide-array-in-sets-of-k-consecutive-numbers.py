#https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
#Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
#Return true if it is possible. Otherwise, return false.
# 
#Example 1:
#Input: nums = [1,2,3,3,4,4,5,6], k = 4
#Output: true
#Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
#Example 2:
#Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
#Output: true
#Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
#Example 3:
#Input: nums = [1,2,3,4], k = 3
#Output: false
#Explanation: Each array should be divided in subarrays of size 3.
# 
#Constraints:
#	1 <= k <= nums.length <= 105
#	1 <= nums[i] <= 109
# 
#Note: This question is the same as 846: https://leetcode.com/problems/hand-of-straights/
class Solution(object):
    def isPossibleDivide(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        # Count the frequency of each number
        freq = collections.Counter(nums)
        
        # Sort the numbers in ascending order
        nums.sort()
        
        # Iterate over the sorted numbers
        for num in nums:
            # If the frequency of the current number is less than k, return False
            if freq[num] < k:
                return False
            
            # Remove k occurrences of the current number from the frequency
            for _ in range(k):
                freq[num] -= 1
        
        # If all numbers can be divided into sets of k consecutive numbers, return True
        return True
        