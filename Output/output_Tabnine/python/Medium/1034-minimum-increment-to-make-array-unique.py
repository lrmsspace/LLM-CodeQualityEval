#https://leetcode.com/problems/minimum-increment-to-make-array-unique/
#You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
#Return the minimum number of moves to make every value in nums unique.
#The test cases are generated so that the answer fits in a 32-bit integer.
# 
#Example 1:
#Input: nums = [1,2,2]
#Output: 1
#Explanation: After 1 move, the array could be [1, 2, 3].
#Example 2:
#Input: nums = [3,2,1,2,1,7]
#Output: 6
#Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
#It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
# 
#Constraints:
#	1 <= nums.length <= 105
#	0 <= nums[i] <= 105
class Solution(object):
    def minIncrementForUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Sort the array
        nums.sort()
        
        # Initialize the minimum number of moves
        min_moves = 0
        
        # Initialize the last unique number
        last_unique = nums[0]
        
        # Iterate through the array
        for num in nums:
            # If the current number is equal to the last unique number, increment it
            if num == last_unique:
                min_moves += last_unique - num + 1
                last_unique += 1
            else:
                last_unique = num
        
        return min_moves
        