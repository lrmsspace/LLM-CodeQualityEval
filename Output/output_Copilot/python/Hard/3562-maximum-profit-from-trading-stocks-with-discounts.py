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
        from collections import defaultdict, deque

        # Build the hierarchy as an adjacency list
        graph = defaultdict(list)
        for u, v in hierarchy:
            graph[u - 1].append(v - 1)
            graph[v - 1].append(u - 1)
        visited = [False] * n
        profits = [0] * n
        costs = [0] * n
        queue = deque([0])
        visited[0] = True
        while queue:
            node = queue.popleft()
            # Calculate profit and cost for the current employee
            profits[node] = future[node] - present[node]
            costs[node] = present[node]
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
                    # If the neighbor is a direct subordinate, apply discount
                    if node == 0 or (node in graph and neighbor in graph[node]):
                        costs[neighbor] = present[neighbor] // 2
                    else:
                        costs[neighbor] = present[neighbor]
            # If the current node is the CEO, apply discount to its own stock
            if node == 0:
                costs[node] = present[node] // 2
        # Sort employees by profit in descending order
        employees = sorted(range(n), key=lambda x: profits[x], reverse=True)
        total_profit = 0
        total_cost = 0
        for emp in employees:
            if total_cost + costs[emp] <= budget:
                total_cost += costs[emp]
                total_profit += profits[emp]
            else:
                break
        return total_profit
        