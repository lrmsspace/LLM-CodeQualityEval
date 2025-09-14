#https://leetcode.com/problems/rank-transform-of-a-matrix/
#Given an m x n matrix, return a new matrix answer where answer[row][col] is the rank of matrix[row][col].
#The rank is an integer that represents how large an element is compared to other elements. It is calculated using the following rules:
#	The rank is an integer starting from 1.
#	If two elements p and q are in the same row or column, then:
#	
#		If p < q then rank(p) < rank(q)
#		If p == q then rank(p) == rank(q)
#		If p > q then rank(p) > rank(q)
#	
#	
#	The rank should be as small as possible.
#The test cases are generated so that answer is unique under the given rules.
# 
#Example 1:
#Input: matrix = [[1,2],[3,4]]
#Output: [[1,2],[2,3]]
#Explanation:
#The rank of matrix[0][0] is 1 because it is the smallest integer in its row and column.
#The rank of matrix[0][1] is 2 because matrix[0][1] > matrix[0][0] and matrix[0][0] is rank 1.
#The rank of matrix[1][0] is 2 because matrix[1][0] > matrix[0][0] and matrix[0][0] is rank 1.
#The rank of matrix[1][1] is 3 because matrix[1][1] > matrix[0][1], matrix[1][1] > matrix[1][0], and both matrix[0][1] and matrix[1][0] are rank 2.
#Example 2:
#Input: matrix = [[7,7],[7,7]]
#Output: [[1,1],[1,1]]
#Example 3:
#Input: matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
#Output: [[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
# 
#Constraints:
#	m == matrix.length
#	n == matrix[i].length
#	1 <= m, n <= 500
#	-109 <= matrix[row][col] <= 109
class Solution(object):
    def matrixRankTransform(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(matrix), len(matrix[0])
        rank = [[0] * n for _ in range(m)]
        d = {}
        for i in range(m):
            for j in range(n):
                if matrix[i][j] not in d:
                    d[matrix[i][j]] = []
                d[matrix[i][j]].append((i, j))
        for k in sorted(d.keys()):
            uf = UF(m + n)
            for i, j in d[k]:
                uf.union(i, j + m)
            max_rank = 0
            for i, j in d[k]:
                rank[i][j] = max(rank[i][j], uf.find(i) + 1)
                max_rank = max(max_rank, rank[i][j])
            for i, j in d[k]:
                rank[i][j] = max_rank
        return rank

class UF(object):
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
        
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            if self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1
