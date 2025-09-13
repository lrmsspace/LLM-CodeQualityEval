#https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/
#You are given an array nums consisting of positive integers.
#You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
#Return the number of distinct integers in the final array.
# 
#Example 1:
#Input: nums = [1,13,10,12,31]
#Output: 6
#Explanation: After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
#The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
#The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).
#Example 2:
#Input: nums = [2,2,2]
#Output: 1
#Explanation: After including the reverse of each number, the resulting array is [2,2,2,2,2,2].
#The number of distinct integers in this array is 1 (The number 2).
# 
#Constraints:
#	1 <= nums.length <= 105
#	1 <= nums[i] <= 106
class Solution(object):
    def countDistinctIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Create a set to store the distinct integers
        distinct_integers = set()
        
        # Iterate over each number in the input array
        for num in nums:
            # Reverse the digits of the number
            reversed_num = int(str(num)[::-1])
            
            # Add the original number and its reverse to the set
            distinct_integers.add(num)
            distinct_integers.add(reversed_num)
        
        # Return the number of distinct integers in the final array
        return len(distinct_integers)
        