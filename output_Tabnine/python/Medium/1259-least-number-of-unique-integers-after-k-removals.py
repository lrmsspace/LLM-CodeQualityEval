#https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
#Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
# 
#Example 1:
#Input: arr = [5,5,4], k = 1
#Output: 1
#Explanation: Remove the single 4, only 5 is left.
#Example 2:
#Input: arr = [4,3,1,1,3,3,2], k = 3
#Output: 2
#Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
# 
#Constraints:
#	1 <= arr.length <= 10^5
#	1 <= arr[i] <= 10^9
#	0 <= k <= arr.length
class Solution(object):

    def findLeastNumOfUniqueInts(self, arr, k):

        """

        :type arr: List[int]

        :type k: int

        :rtype: int

        """
        # Count the frequency of each integer in the array
        count = {}
        for num in arr:
            count[num] = count.get(num, 0) + 1
        
        # Sort the integers in descending order of their frequency
        arr.sort(key=lambda x: count[x], reverse=True)
        
        # Initialize variables
        unique_count = 0
        total_count = len(arr)
        i = 0
        
        # Iterate through the array and remove elements until k is reached
        while k > 0 and i < total_count:
            # If the current integer has a frequency greater than 1, remove it
            if count[arr[i]] > 1:
                count[arr[i]] -= 1
                total_count -= 1
                k -= 1
            # If the current integer has a frequency of 1, increment the unique count
            else:
                unique_count += 1
                i += 1
        
        return unique_count