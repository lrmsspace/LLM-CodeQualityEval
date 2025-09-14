#https://leetcode.com/problems/validate-binary-tree-nodes/
#You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
#If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
#Note that the nodes have no values and that we only use the node numbers in this problem.
# 
#Example 1:
#Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
#Output: true
#Example 2:
#Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
#Output: false
#Example 3:
#Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
#Output: false
# 
#Constraints:
#	n == leftChild.length == rightChild.length
#	1 <= n <= 104
#	-1 <= leftChild[i], rightChild[i] <= n - 1
class Solution(object):
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        """
        :type n: int
        :type leftChild: List[int]
        :type rightChild: List[int]
        :rtype: bool
        """
        def dfs(node):
            if node == -1:
                return True
            if visited[node]:
                return False
            visited[node] = True
            return dfs(leftChild[node]) and dfs(rightChild[node])
        visited = [False] * n
        root = -1
        for i in range(n):
            if leftChild[i] != -1 and visited[leftChild[i]]:
                return False
            if rightChild[i] != -1 and visited[rightChild[i]]:
                return False
            if leftChild[i] == -1 and rightChild[i] == -1:
                if root != -1:
                    return False
                root = i
        return dfs(root)
