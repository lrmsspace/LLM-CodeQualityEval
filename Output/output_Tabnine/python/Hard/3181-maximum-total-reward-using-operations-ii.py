# You are given an integer array rewardValues of length n, representing the values of rewards.
# Initially, your total reward x is 0, and all indices are unmarked. You are allowed to perform the following operation any number of times:
# Choose an unmarked index i from the range [0, n - 1].
# If rewardValues[i] is greater than your current total reward x, then add rewardValues[i] to x (i.e., x = x + rewardValues[i]), and mark the index i.
# Return an integer denoting the maximum total reward you can collect by performing the operations optimally.
# Example 1:
# Input: rewardValues = [1,1,3,3]
# Output: 4
# Explanation:
# During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.
# Example 2:
# Input: rewardValues = [1,6,4,3,2]
# Output: 11
# Explanation:
# Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.
# Constraints:
# 1 <= rewardValues.length <= 5 * 104
# 1 <= rewardValues[i] <= 5 * 104

class Solution(object):
    def maxTotalReward(self, rewardValues):
        """
        :type rewardValues: List[int]
        :rtype: int
        """
        n = len(rewardValues)
        left = [0] * n
        right = [0] * n
        
        max_left = max_right = 0
        
        for i in range(n - 1, -1, -1):
            max_left = max(max_left, rewardValues[i])
            left[i] = max_left
        
        for i in range(n):
            max_right = max(max_right, rewardValues[i])
            right[i] = max_right
        
        total_reward = 0
        for i in range(n):
            total_reward = max(total_reward, left[i] + right[i] - rewardValues[i])
        
        return total_reward 
        