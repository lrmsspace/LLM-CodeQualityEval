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
        indegree = [0] * n
        for i in range(n):
            if leftChild[i] != -1:
                indegree[leftChild[i]] += 1
            if rightChild[i] != -1:
                indegree[rightChild[i]] += 1
        root = -1
        for i in range(n):
            if indegree[i] == 0:
                root = i
                break
        if root == -1:
            return False
        visited = [False] * n
        q = [root]
        visited[root] = True
        while q:
            node = q.pop(0)
            if leftChild[node] != -1 and not visited[leftChild[node]]:
                q.append(leftChild[node])
                visited[leftChild[node]] = True
            if rightChild[node] != -1 and not visited[rightChild[node]]:
                q.append(rightChild[node])
                visited[rightChild[node]] = True
        return sum(visited) == n
                    
        