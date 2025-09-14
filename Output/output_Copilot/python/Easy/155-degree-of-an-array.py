#https://leetcode.com/problems/degree-of-an-array/
#Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
#Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
# 
#Example 1:
#Input: nums = [1,2,2,3,1]
#Output: 2
#Explanation: 
#The input array has a degree of 2 because both elements 1 and 2 appear twice.
#Of the subarrays that have the same degree:
#[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
#The shortest length is 2. So return 2.
#Example 2:
#Input: nums = [1,2,2,3,1,4,2]
#Output: 6
#Explanation: 
#The degree is 3 because the element 2 is repeated 3 times.
#So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
# 
#Constraints:
#	nums.length will be between 1 and 50,000.
#	nums[i] will be an integer between 0 and 49,999.
class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import defaultdict

        # Step 1: Count the frequency of each element and store the first and last occurrence indices
        count = defaultdict(int)
        first_index = {}
        last_index = {}

        for i, num in enumerate(nums):
            count[num] += 1
            if num not in first_index:
                first_index[num] = i
            last_index[num] = i

        # Step 2: Find the maximum frequency (degree) and the minimum length of subarray with that degree
        max_degree = max(count.values())
        min_length = float('inf')

        for num, freq in count.items():
            if freq == max_degree:
                length = last_index[num] - first_index[num] + 1
                min_length = min(min_length, length)

        return min_length        