#https://leetcode.com/problems/3sum-with-multiplicity/
#Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
#As the answer can be very large, return it modulo 109 + 7.
# 
#Example 1:
#Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
#Output: 20
#Explanation: 
#Enumerating by the values (arr[i], arr[j], arr[k]):
#(1, 2, 5) occurs 8 times;
#(1, 3, 4) occurs 8 times;
#(2, 2, 4) occurs 2 times;
#(2, 3, 3) occurs 2 times.
#Example 2:
#Input: arr = [1,1,2,2,2,2], target = 5
#Output: 12
#Explanation: 
#arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
#We choose one 1 from [1,1] in 2 ways,
#and two 2s from [2,2,2,2] in 6 ways.
#Example 3:
#Input: arr = [2,1,3], target = 6
#Output: 1
#Explanation: (1, 2, 3) occured one time in the array so we return 1.
# 
#Constraints:
#	3 <= arr.length <= 3000
#	0 <= arr[i] <= 100
#	0 <= target <= 300
class Solution(object):
    def threeSumMulti(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
        MOD = 10**9 + 7
        count = collections.Counter(arr)
        ans = 0
        for i in count:
            for j in count:
                if i + j > target:
                    break
                k = target - i - j
                ans += count[i] * count[j] * count[k]
                if i == j == k:
                    ans -= count[i] * (count[i] - 1) // 2
                elif i == j:
                    ans -= count[i] * (count[i] - 1) * (count[i] - 2) // 6
                elif j == k:
                    ans -= count[j] * (count[j] - 1) * (count[j] - 2) // 6
                else:
                    ans -= count[i] * count[j] * (count[k] - 1) // 2
        return ans % MOD    
        