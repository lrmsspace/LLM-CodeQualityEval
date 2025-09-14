#https://leetcode.com/problems/kth-missing-positive-number/
#Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
#Return the kth positive integer that is missing from this array.
# 
#Example 1:
#Input: arr = [2,3,4,7,11], k = 5
#Output: 9
#Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
#Example 2:
#Input: arr = [1,2,3,4], k = 2
#Output: 6
#Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
# 
#Constraints:
#	1 <= arr.length <= 1000
#	1 <= arr[i] <= 1000
#	1 <= k <= 1000
#	arr[i] < arr[j] for 1 <= i < j <= arr.length
# 
#Follow up:
#Could you solve this problem in less than O(n) complexity?
class Solution(object):
    def findKthPositive(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        # 1. 先找到 arr 中的最大值 max_num
        max_num = arr[-1] if arr else 0
        
        # 2. 创建一个布尔数组，长度为 max_num + k + 1，初始值为 False
        #    用于标记 arr 中存在的正整数
        exists = [False] * (max_num + k + 1)
        
        # 3. 标记 arr 中存在的正整数
        for num in arr:
            exists[num] = True
        
        # 4. 遍历布尔数组，找到第 k 个缺失的正整数
        missing_count = 0
        for i in range(1, len(exists)):
            if not exists[i]:
                missing_count += 1
                if missing_count == k:
                    return i
        
        return -1        