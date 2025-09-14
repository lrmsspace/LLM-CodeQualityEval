#https://leetcode.com/problems/grid-illumination/
#There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
#You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.
#When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.
#You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
#Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.
# 
#Example 1:
#Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
#Output: [1,0]
#Explanation: We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
#The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.
#The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0. Then, we turn off all lamps in the red rectangle.
#Example 2:
#Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
#Output: [1,1]
#Example 3:
#Input: n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
#Output: [1,1,0]
# 
#Constraints:
#	1 <= n <= 109
#	0 <= lamps.length <= 20000
#	0 <= queries.length <= 20000
#	lamps[i].length == 2
#	0 <= rowi, coli < n
#	queries[j].length == 2
#	0 <= rowj, colj < n
class Solution(object):
    def gridIllumination(self, n, lamps, queries):
        """
        :type n: int
        :type lamps: List[List[int]]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        res = []
        lampSet = set()
        rowMap = collections.defaultdict(set)
        colMap = collections.defaultdict(set)
        diaMap = collections.defaultdict(set)
        antiDiaMap = collections.defaultdict(set)
        for lamp in lamps:
            lampSet.add(tuple(lamp))
            rowMap[lamp[0]].add(lamp[1])
            colMap[lamp[1]].add(lamp[0])
            diaMap[lamp[0] + lamp[1]].add(lamp[0])
            antiDiaMap[lamp[0] - lamp[1]].add(lamp[0])
        for query in queries:
            if (query[0] in rowMap and query[1] in rowMap[query[0]]) or (query[1] in colMap and query[0] in colMap[query[1]]) or (query[0] + query[1] in diaMap and query[0] in diaMap[query[0] + query[1]]) or (query[0] - query[1] in antiDiaMap and query[0] in antiDiaMap[query[0] - query[1]]):
                res.append(1)
            else:
                res.append(0)
            for r in range(query[0] - 1, query[0] + 2):
                for c in range(query[1] - 1, query[1] + 2):
                    if (r, c) in lampSet:
                        lampSet.remove((r, c))
                        rowMap[r].remove(c)
                        colMap[c].remove(r)
                        diaMap[r + c].remove(r)
                        antiDiaMap[r - c].remove(r)
        return res
