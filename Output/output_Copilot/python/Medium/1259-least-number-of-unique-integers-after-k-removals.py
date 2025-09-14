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
        from collections import Counter

        count = Counter(arr)

        # Sort the counts in ascending order

        sorted_counts = sorted(count.values())

        # Remove k elements from the least frequent integers

        for c in sorted_counts:

            if k >= c:

                k -= c

            else:

                break

        return len(sorted_counts) - len(sorted_counts[:sorted_counts.index(c) + 1]) if k == 0 else len(sorted_counts)
# Test cases