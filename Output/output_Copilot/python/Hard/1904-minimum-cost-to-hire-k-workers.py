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
        # 1. 计算每个工人的工资与质量的比值
        ratio = [(float(wage[i]) / quality[i], quality[i]) for i in range(len(quality))]

        # 2. 按照工资与质量的比值升序排序
        ratio.sort()

        # 3. 使用堆来维护当前选择的工人的质量总和
        import heapq

        heap = []        
        total_quality = 0
        min_cost = float('inf')
        for r, q in ratio:
            # 4. 将当前工人的质量加入堆中，并更新质量总和
            heapq.heappush(heap, -q)
            total_quality += q

            # 5. 如果堆中的工人数量超过k，则移除质量最大的工人
            if len(heap) > k:
                total_quality += heapq.heappop(heap)

            # 6. 如果堆中的工人数量等于k，则计算当前的最小成本
            if len(heap) == k:
                min_cost = min(min_cost, r * total_quality)
        return min_cost