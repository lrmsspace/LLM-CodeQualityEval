#https://leetcode.com/problems/array-of-doubled-pairs/
#Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
# 
#Example 1:
#Input: arr = [3,1,3,6]
#Output: false
#Example 2:
#Input: arr = [2,1,2,6]
#Output: false
#Example 3:
#Input: arr = [4,-2,2,-4]
#Output: true
#Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
# 
#Constraints:
#	2 <= arr.length <= 3 * 104
#	arr.length is even.
#	-105 <= arr[i] <= 105
class Solution(object):
    def canReorderDoubled(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        arr.sort()
        count = {}
        for num in arr:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1

        for num in arr:
            if count[num] == 0:
                continue
            if num < 0 and num % 2 != 0:
                return False
            if num < 0:
                half = num // 2
            else:
                half = num * 2
            if half not in count or count[half] == 0:
                return False
            count[num] -= 1
            count[half] -= 1

        return True        