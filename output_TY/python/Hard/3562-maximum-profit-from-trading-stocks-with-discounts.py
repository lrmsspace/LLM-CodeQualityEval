# You are given an integer n, representing the number of employees in a company. Each employee is assigned a unique ID from 1 to n, and employee 1 is the CEO. You are given two 1-based integer arrays, present and future, each of length n, where:
# present[i] represents the current price at which the ith employee can buy a stock today.
# future[i] represents the expected price at which the ith employee can sell the stock tomorrow.
# The company's hierarchy is represented by a 2D integer array hierarchy, where hierarchy[i] = [ui, vi] means that employee ui is the direct boss of employee vi.
# Additionally, you have an integer budget representing the total funds available for investment.
# However, the company has a discount policy: if an employee's direct boss purchases their own stock, then the employee can buy their stock at half the original price (floor(present[v] / 2)).
# Return the maximum profit that can be achieved without exceeding the given budget.
# Note:
# You may buy each stock at most once.
# You cannot use any profit earned from future stock prices to fund additional investments and must buy only from budget.
# Example 1:
# Input: n = 2, present = [1,2], future = [4,3], hierarchy = [[1,2]], budget = 3
# Output: 5
# Explanation:
# Employee 1 buys the stock at price 1 and earns a profit of 4 - 1 = 3.
# Since Employee 1 is the direct boss of Employee 2, Employee 2 gets a discounted price of floor(2 / 2) = 1.
# Employee 2 buys the stock at price 1 and earns a profit of 3 - 1 = 2.
# The total buying cost is 1 + 1 = 2 <= budget. Thus, the maximum total profit achieved is 3 + 2 = 5.
# Example 2:
# Input: n = 2, present = [3,4], future = [5,8], hierarchy = [[1,2]], budget = 4
# Output: 4
# Explanation:
# Employee 2 buys the stock at price 4 and earns a profit of 8 - 4 = 4.
# Since both employees cannot buy together, the maximum profit is 4.
# Example 3:
# Input: n = 3, present = [4,6,8], future = [7,9,11], hierarchy = [[1,2],[1,3]], budget = 10
# Output: 10
# Explanation:
# Employee 1 buys the stock at price 4 and earns a profit of 7 - 4 = 3.
# Employee 3 would get a discounted price of floor(8 / 2) = 4 and earns a profit of 11 - 4 = 7.
# Employee 1 and Employee 3 buy their stocks at a total cost of 4 + 4 = 8 <= budget. Thus, the maximum total profit achieved is 3 + 7 = 10.
# Example 4:
# Input: n = 3, present = [5,2,3], future = [8,5,6], hierarchy = [[1,2],[2,3]], budget = 7
# Output: 12
# Explanation:
# Employee 1 buys the stock at price 5 and earns a profit of 8 - 5 = 3.
# Employee 2 would get a discounted price of floor(2 / 2) = 1 and earns a profit of 5 - 1 = 4.
# Employee 3 would get a discounted price of floor(3 / 2) = 1 and earns a profit of 6 - 1 = 5.
# The total cost becomes 5 + 1 + 1 = 7 <= budget. Thus, the maximum total profit achieved is 3 + 4 + 5 = 12.
# Constraints:
# 1 <= n <= 160
# present.length, future.length == n
# 1 <= present[i], future[i] <= 50
# hierarchy.length == n - 1
# hierarchy[i] == [ui, vi]
# 1 <= ui, vi <= n
# ui != vi
# 1 <= budget <= 160
# There are no duplicate edges.
# Employee 1 is the direct or indirect boss of every employee.
# The input graph hierarchy is guaranteed to have no cycles.
from typing import List

class Solution(object):
    def maxProfit(self, n, present, future, hierarchy, budget):
        """
        :type n: int
        :type present: List[int]
        :type future: List[int]
        :type hierarchy: List[List[int]]
        :type budget: int
        :rtype: int
        """
        from collections import defaultdict
        
        # 构建树结构
        tree = defaultdict(list)
        for u, v in hierarchy:
            tree[u - 1].append(v - 1)  # 转换为 0-based index

        # dp[u][0/1][b]: 节点u不买/买股票，在预算b下的最大利润
        # 初始值为 -inf，表示不可达
        dp = [[[-1] * (budget + 1) for _ in range(2)] for _ in range(n)]

        def dfs(u: int) -> None:
            # 当前节点自己购买的情况
            cost = present[u]
            profit = future[u] - cost

            # 初始化：不买 / 买
            dp[u][0] = [0] * (budget + 1)
            dp[u][1] = [-1] * (budget + 1)
            if cost <= budget:
                dp[u][1][cost] = profit

            # 遍历子节点
            for v in tree[u]:
                dfs(v)

                # 创建临时数组保存合并后的结果
                new_dp0 = [-1] * (budget + 1)
                new_dp1 = [-1] * (budget + 1)

                # 合并当前 dp[u] 和 dp[v]

                # Case 1: u 不买股票（v 可以买原价或不买）
                for b1 in range(budget + 1):
                    if dp[u][0][b1] == -1:
                        continue
                    for b2 in range(budget - b1 + 1):
                        if dp[v][0][b2] != -1:
                            new_dp0[b1 + b2] = max(new_dp0[b1 + b2], dp[u][0][b1] + dp[v][0][b2])
                        if dp[v][1][b2] != -1:
                            new_dp0[b1 + b2] = max(new_dp0[b1 + b2], dp[u][0][b1] + dp[v][1][b2])

                # Case 2: u 买股票（v 可以买折后价或不买）
                for b1 in range(budget + 1):
                    if dp[u][1][b1] == -1:
                        continue
                    for b2 in range(budget - b1 + 1):
                        discounted_cost = present[v] // 2
                        if discounted_cost > b2:
                            # 折扣价超过预算，无法购买
                            new_dp1[b1 + b2] = max(new_dp1[b1 + b2], dp[u][1][b1] + dp[v][0][b2])
                        else:
                            new_dp1[b1 + b2] = max(
                                new_dp1[b1 + b2],
                                dp[u][1][b1] + max(dp[v][0][b2], dp[v][1][discounted_cost] + (future[v] - discounted_cost))
                            )

                # 更新 dp[u]
                dp[u][0] = new_dp0
                dp[u][1] = new_dp1

        dfs(0)  # 从 CEO 开始 DFS

        # 最终结果是 max(CEO 买 or 不买 中的最大利润)
        return max(max(dp[0][0]), max(dp[0][1]))