# You are given an array of integers nums of size n and a positive integer threshold.
# There is a graph consisting of n nodes with the ith node having a value of nums[i]. Two nodes i and j in the graph are connected via an undirected edge if lcm(nums[i], nums[j]) <= threshold.
# Return the number of connected components in this graph.
# A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
# The term lcm(a, b) denotes the least common multiple of a and b.
# Example 1:
# Input: nums = [2,4,8,3,9], threshold = 5
# Output: 4
# Explanation: 
# The four connected components are (2, 4), (3), (8), (9).
# Example 2:
# Input: nums = [2,4,8,3,9,12], threshold = 10
# Output: 2
# Explanation: 
# The two connected components are (2, 3, 4, 8, 9), and (12).
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 109
# All elements of nums are unique.
# 1 <= threshold <= 2 * 105
class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px != py:
            self.parent[py] = px

class Solution(object):
    def countComponents(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        num_set = set(nums)
        max_num = max(num_set)
        
        # 初始化并查集
        uf = UnionFind(max_num + 1)
        
        # 对于每个数x，找出所有能与它形成有效边的因数
        for i in range(len(nums)):
            x = nums[i]
            if x > threshold:
                continue
                
            for j in range(i+1, len(nums)):
                y = nums[j]
                lcm_val = self.lcm(x, y)
                if lcm_val <= threshold:
                    uf.union(x, y)
        
        # 计算连通分量的数量
        components = set()
        for num in nums:
            components.add(uf.find(num))
        
        return len(components)
    
    def gcd(self, a, b):
        while b:
            a, b = b, a % b
        return a
    
    def lcm(self, a, b):
        return a * b // self.gcd(a, b)