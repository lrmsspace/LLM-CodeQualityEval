#https://leetcode.com/problems/find-in-mountain-array/
#(This problem is an interactive problem.)
#You may recall that an array arr is a mountain array if and only if:
#	arr.length >= 3
#	There exists some i with 0 < i < arr.length - 1 such that:
#	
#		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
#		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
#	
#	
#Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.
#You cannot access the mountain array directly. You may only access the array using a MountainArray interface:
#	MountainArray.get(k) returns the element of the array at index k (0-indexed).
#	MountainArray.length() returns the length of the array.
#Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.
# 
#Example 1:
#Input: mountainArr = [1,2,3,4,5,3,1], target = 3
#Output: 2
#Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
#Example 2:
#Input: mountainArr = [0,1,2,4,2,1], target = 3
#Output: -1
#Explanation: 3 does not exist in the array, so we return -1.
# 
#Constraints:
#	3 <= mountainArr.length() <= 104
#	0 <= target <= 109
#	0 <= mountainArr.get(index) <= 109
# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray(object):
#    def get(self, index):
#        """
#        :type index: int
#        :rtype int
#        """
#
#    def length(self):
#        """
#        :rtype int
#        """

class Solution(object):
    def findInMountainArray(self, target, mountainArr):
        """
        :type target: integer
        :type mountain_arr: MountainArray
        :rtype: integer
        """
        length = mountainArr.length()
        low, high = 0, length - 1
        while low < high:
            mid = (low + high) // 2
            if mountainArr.get(mid) < mountainArr.get(mid + 1):
                low = mid + 1
            else:
                high = mid
        peak = low
        low, high = 0, peak
        while low <= high:
            mid = (low + high) // 2
            if mountainArr.get(mid) < target:
                low = mid + 1
            elif mountainArr.get(mid) > target:
                high = mid - 1
            else:
                return mid
        low, high = peak, length - 1
        while low <= high:
            mid = (low + high) // 2
            if mountainArr.get(mid) > target:
                low = mid + 1
            elif mountainArr.get(mid) < target:
                high = mid - 1
            else:
                return mid
        return -1
        