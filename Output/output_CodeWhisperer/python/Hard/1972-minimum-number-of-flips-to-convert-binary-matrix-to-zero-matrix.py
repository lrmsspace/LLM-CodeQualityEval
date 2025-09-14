#https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
#Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.
#Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.
#A binary matrix is a matrix with all cells equal to 0 or 1 only.
#A zero matrix is a matrix with all cells equal to 0.
# 
#Example 1:
#Input: mat = [[0,0],[0,1]]
#Output: 3
#Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
#Example 2:
#Input: mat = [[0]]
#Output: 0
#Explanation: Given matrix is a zero matrix. We do not need to change it.
#Example 3:
#Input: mat = [[1,0,0],[1,0,0]]
#Output: -1
#Explanation: Given matrix cannot be a zero matrix.
# 
#Constraints:
#	m == mat.length
#	n == mat[i].length
#	1 <= m, n <= 3
#	mat[i][j] is either 0 or 1.
class Solution(object):
    def minFlips(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        start = sum(val << (i*n + j) for i, row in enumerate(mat) for j, val in enumerate(row))
        queue = collections.deque([start])
        seen = {start}
        ans = 0
        while queue:
            for _ in range(len(queue)):
                cur = queue.popleft()
                if cur == 0:
                    return ans
                for i in range(m):
                    for j in range(n):
                        nxt = cur
                        for r, c in (i,j), (i+1,j), (i-1,j), (i,j+1), (i,j-1):
                            if 0 <= r < m and 0 <= c < n:
                                nxt ^= 1 << (r*n + c)
                        if nxt not in seen:
                            seen.add(nxt)
                            queue.append(nxt)
            ans += 1
        return -1
        