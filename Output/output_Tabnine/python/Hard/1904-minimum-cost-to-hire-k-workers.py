#https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
#There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
#We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
#	Every worker in the paid group must be paid at least their minimum wage expectation.
#	In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.
#Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
# 
#Example 1:
#Input: quality = [10,20,5], wage = [70,50,30], k = 2
#Output: 105.00000
#Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
#Example 2:
#Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
#Output: 30.66667
#Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
# 
#Constraints:
#	n == quality.length == wage.length
#	1 <= k <= n <= 104
#	1 <= quality[i], wage[i] <= 104
class Solution(object):
    def mincostToHireWorkers(self, quality, wage, k):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type k: int
        :rtype: float
        """
        # Sort workers based on quality to ensure higher quality workers are paid first
        workers = sorted(zip(quality, wage), key=lambda x: x[0] / x[1])
        
        # Initialize variables for two pointers and the result
        left, right, min_cost = 0, len(workers) - 1, float('inf')
        
        # Use two pointers to find the minimum cost to hire k workers
        while left <= right:
            cost = sum(w * workers[right][1] for w in workers[left:right+1]) / sum(workers[right][0] for _ in workers[left:right+1])
            if cost < min_cost:
                min_cost = cost
            if workers[left][0] * (right - left + 1) < workers[right][0] * (len(workers) - right - 1):
                left += 1
            else:
                right -= 1
        return min_cost
        