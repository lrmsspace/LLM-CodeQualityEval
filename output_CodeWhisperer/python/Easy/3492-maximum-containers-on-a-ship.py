# You are given a positive integer n representing an n x n cargo deck on a ship. Each cell on the deck can hold one container with a weight of exactly w.
# However, the total weight of all containers, if loaded onto the deck, must not exceed the ship's maximum weight capacity, maxWeight.
# Return the maximum number of containers that can be loaded onto the ship.
# Example 1:
# Input: n = 2, w = 3, maxWeight = 15
# Output: 4
# Explanation: 
# The deck has 4 cells, and each container weighs 3. The total weight of loading all containers is 12, which does not exceed maxWeight.
# Example 2:
# Input: n = 3, w = 5, maxWeight = 20
# Output: 4
# Explanation: 
# The deck has 9 cells, and each container weighs 5. The maximum number of containers that can be loaded without exceeding maxWeight is 4.
# Constraints:
# 1 <= n <= 1000
# 1 <= w <= 1000
# 1 <= maxWeight <= 109

class Solution(object):
    def maxContainers(self, n, w, maxWeight):
        """
        :type n: int
        :type w: int
        :type maxWeight: int
        :rtype: int
        """
        # 1. 从 1 开始枚举所有可能的容器数
        # 2. 检查每个容器数是否符合条件
        # 3. 返回最大的容器数
        for i in range(1, n * n + 1):
            if i * w > maxWeight:
                return i - 1
        return n * n        