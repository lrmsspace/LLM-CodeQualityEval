# Given an array nums, you can perform the following operation any number of times:
# Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
# Replace the pair with their sum.
# Return the minimum number of operations needed to make the array non-decreasing.
# An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
# Example 1:
# Input: nums = [5,2,3,1]
# Output: 2
# Explanation:
# The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
# The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
# The array nums became non-decreasing in two operations.
# Example 2:
# Input: nums = [1,2,2]
# Output: 0
# Explanation:
# The array nums is already sorted.
# Constraints:
# 1 <= nums.length <= 105
# -109 <= nums[i] <= 109

class Solution(object):
    def minimumPairRemoval(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import Counter
        from heapq import heappush, heappop

        count = Counter(nums)
        min_heap = []
        
        # Create a min-heap of pairs (count, value)
        for value, cnt in count.items():
            heappush(min_heap, (cnt, value))
        
        operations = 0
        
        while len(min_heap) > 1:
            # Pop the two smallest pairs
            cnt1, val1 = heappop(min_heap)
            cnt2, val2 = heappop(min_heap)
            
            # If they can be merged
            if val1 + val2 <= 0:
                operations += 1
                new_count = cnt1 + cnt2
                new_value = val1 + val2
                
                # Push the new pair back into the heap
                heappush(min_heap, (new_count, new_value))
            else:
                # If they cannot be merged, push them back and break
                heappush(min_heap, (cnt1, val1))
                heappush(min_heap, (cnt2, val2))
                break
        
        return operations
        