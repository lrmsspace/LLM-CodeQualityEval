#https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/
#You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.
#You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built.
#Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 109 + 7.
# 
#Example 1:
#Input: prevRoom = [-1,0,1]
#Output: 1
#Explanation: There is only one way to build the additional rooms: 0 → 1 → 2
#Example 2:
#Input: prevRoom = [-1,0,0,1,2]
#Output: 6
#Explanation:
#The 6 ways are:
#0 → 1 → 3 → 2 → 4
#0 → 2 → 4 → 1 → 3
#0 → 1 → 2 → 3 → 4
#0 → 1 → 2 → 4 → 3
#0 → 2 → 1 → 3 → 4
#0 → 2 → 1 → 4 → 3
# 
#Constraints:
#	n == prevRoom.length
#	2 <= n <= 105
#	prevRoom[0] == -1
#	0 <= prevRoom[i] < n for all 1 <= i < n
#	Every room is reachable from room 0 once all the rooms are built.
class Solution(object):

    def waysToBuildRooms(self, prevRoom):
        """
        :type prevRoom: List[int]
        :rtype: int
        """
        MOD = 1000000007
        n = len(prevRoom)   
        
        # Build adjacency list
        graph = [[] for _ in range(n)]
        for i in range(1, n):
            graph[prevRoom[i]].append(i)
        
        # Calculate factorials and inverse factorials for later use
        fact = [1] * (n + 1)
        inv_fact = [1] * (n + 1)
        for i in range(1, n + 1):
            fact[i] = (fact[i - 1] * i) % MOD
        
        # Calculate modular multiplicative inverse for n!
        def mod_pow(x, y):
            if y == 0:
                return 1
            temp = mod_pow(x, y // 2)
            temp = (temp * temp) % MOD
            if y % 2 == 1:
                temp = (temp * x) % MOD
            return temp
        
        inv_fact[n] = mod_pow(fact[n], MOD - 2)
        for i in range(n - 1, -1, -1):
            inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD
        
        # DFS to calculate subtree sizes and ways
        def dfs(node):
            if not graph[node]:
                return 1, 1  # size, ways
            
            total_size = 1
            total_ways = 1
            
            # Process all children
            for child in graph[node]:
                size, ways = dfs(child)
                # Multiply by ways to arrange current subtree
                total_ways = (total_ways * ways) % MOD
                # Multiply by combination of positions
                total_ways = (total_ways * inv_fact[size]) % MOD
                total_size += size
                
            # Multiply by total arrangements possible
            total_ways = (total_ways * fact[total_size - 1]) % MOD
            return total_size, total_ways
        
        return dfs(0)[1]
