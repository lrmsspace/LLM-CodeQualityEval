#https://leetcode.com/problems/minimize-deviation-in-array/
#You are given an array nums of n positive integers.
#You can perform two types of operations on any element of the array any number of times:
#	If the element is even, divide it by 2.
#	
#		For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
#	
#	
#	If the element is odd, multiply it by 2.
#	
#		For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
#	
#	
#The deviation of the array is the maximum difference between any two elements in the array.
#Return the minimum deviation the array can have after performing some number of operations.
# 
#Example 1:
#Input: nums = [1,2,3,4]
#Output: 1
#Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
#Example 2:
#Input: nums = [4,1,5,20,3]
#Output: 3
#Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
#Example 3:
#Input: nums = [2,10,8]
#Output: 3
# 
#Constraints:
#	n == nums.length
#	2 <= n <= 5 * 104
#	1 <= nums[i] <= 109
class Solution(object):
    def minimumDeviation(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        import heapq

        # Step 1: Initialize the max heap and find the minimum value in the array
        max_heap = []
        min_value = float('inf')
        for num in nums:
            if num % 2 == 0:
                # If the number is even, push it into the max heap and update min_value
                heapq.heappush(max_heap, -num)      
                min_value = min(min_value, num)
            else:
                # If the number is odd, push its double into the max heap and update min_value
                heapq.heappush(max_heap, -num * 2)
                min_value = min(min_value, num * 2)
        # Step 2: Initialize the minimum deviation to a large value
        # min_deviation = float('inf')
        min_deviation = float('inf')
        # Step 3: Calculate the deviation while the max heap is not empty
        # while max_heap:
        while max_heap:
            # Step 4: Get the maximum value from the max heap and calculate the deviation
            max_value = -heapq.heappop(max_heap)
            min_deviation = min(min_deviation, max_value - min_value)
            # Step 5: If the maximum value is even, divide it by 2 and push it back into the max heap
            if max_value % 2 == 0:
                heapq.heappush(max_heap, -max_value // 2)
                min_value = min(min_value, max_value // 2)
            else:
                # If the maximum value is odd, break the loop as we cannot reduce it further
                break
        # Step 6: Return the minimum deviation found
        return min_deviation     