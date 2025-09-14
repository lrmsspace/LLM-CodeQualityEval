#https://leetcode.com/problems/construct-target-array-with-multiple-sums/
#You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :
#	let x be the sum of all elements currently in your array.
#	choose index i, such that 0 <= i < n and set the value of arr at index i to x.
#	You may repeat this procedure as many times as needed.
#Return true if it is possible to construct the target array from arr, otherwise, return false.
# 
#Example 1:
#Input: target = [9,3,5]
#Output: true
#Explanation: Start with arr = [1, 1, 1] 
#[1, 1, 1], sum = 3 choose index 1
#[1, 3, 1], sum = 5 choose index 2
#[1, 3, 5], sum = 9 choose index 0
#[9, 3, 5] Done
#Example 2:
#Input: target = [1,1,1,2]
#Output: false
#Explanation: Impossible to create target array from [1,1,1,1].
#Example 3:
#Input: target = [8,5]
#Output: true
# 
#Constraints:
#	n == target.length
#	1 <= n <= 5 * 104
#	1 <= target[i] <= 109
class Solution(object):
    def isPossible(self, target):
        """
        :type target: List[int]
        :rtype: bool
        """
        # Initialize variables
        count = [0] * 10**9
        prefix_sum = 0
        
        # Count the frequency of each target number
        for num in target:
            count[num] += 1
        
        # Iterate through the count array from largest to smallest
        for num in range(10**9, 0, -1):
            # If the current number is not in the count array, continue to the next number
            if count[num] == 0:
                continue
            
            # If the current number is greater than the prefix sum, it is impossible to construct the target array
            if num > prefix_sum:
                return False
            
            # Reduce the frequency of the current number and add it to the prefix sum
            count[num] -= 1
            prefix_sum += num
        
        # If the prefix sum is equal to the sum of all target numbers, it is possible to construct the target array
        return prefix_sum == sum(target)
        