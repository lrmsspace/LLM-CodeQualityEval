#https://leetcode.com/problems/top-k-frequent-elements/
#Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
# 
#Example 1:
#Input: nums = [1,1,1,2,2,3], k = 2
#Output: [1,2]
#Example 2:
#Input: nums = [1], k = 1
#Output: [1]
# 
#Constraints:
#	1 <= nums.length <= 105
#	-104 <= nums[i] <= 104
#	k is in the range [1, the number of unique elements in the array].
#	It is guaranteed that the answer is unique.
# 
#Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # Create a dictionary to store the frequency of each number
        freq_dict = {}
        for num in nums:
            freq_dict[num] = freq_dict.get(num, 0) + 1
        
        # Create a max heap to store the k most frequent numbers
        max_heap = []
        for num, freq in freq_dict.items():
            heapq.heappush(max_heap, (-freq, num))
            
            # If the heap size exceeds k, remove the least frequent number
            if len(max_heap) > k:
                heapq.heappop(max_heap)
        
        # Extract the numbers from the max heap and return them in descending order
        return [-freq for freq, num in max_heap]
        