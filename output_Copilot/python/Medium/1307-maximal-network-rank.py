#https://leetcode.com/problems/maximal-network-rank/
#There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
#The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
#The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
#Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
# 
#Example 1:
#Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
#Output: 4
#Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.
#Example 2:
#Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
#Output: 5
#Explanation: There are 5 roads that are connected to cities 1 or 2.
#Example 3:
#Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
#Output: 5
#Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
# 
#Constraints:
#	2 <= n <= 100
#	0 <= roads.length <= n * (n - 1) / 2
#	roads[i].length == 2
#	0 <= ai, bi <= n-1
#	ai != bi
#	Each pair of cities has at most one road connecting them.
class Solution(object):
    def maximalNetworkRank(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        # Create a set to store the roads for O(1) lookup
        road_set = set()
        for road in roads:
            road_set.add((road[0], road[1]))
            road_set.add((road[1], road[0]))

        # Create an array to count the number of roads for each city
        city_count = [0] * n
        for road in roads:
            city_count[road[0]] += 1
            city_count[road[1]] += 1

        max_rank = 0
        # Iterate through all pairs of cities to calculate the network rank
        for i in range(n):
            for j in range(i + 1, n):
                rank = city_count[i] + city_count[j]
                if (i, j) in road_set:
                    rank -= 1   
                max_rank = max(max_rank, rank)
        return max_rank     