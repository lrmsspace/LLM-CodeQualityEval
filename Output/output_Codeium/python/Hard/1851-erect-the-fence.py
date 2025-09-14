#https://leetcode.com/problems/erect-the-fence/
#You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.
#Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if all the trees are enclosed.
#Return the coordinates of trees that are exactly located on the fence perimeter. You may return the answer in any order.
# 
#Example 1:
#Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
#Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
#Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
#Example 2:
#Input: trees = [[1,2],[2,2],[4,2]]
#Output: [[4,2],[2,2],[1,2]]
#Explanation: The fence forms a line that passes through all the trees.
# 
#Constraints:
#	1 <= trees.length <= 3000
#	trees[i].length == 2
#	0 <= xi, yi <= 100
#	All the given positions are unique.
class Solution(object):
    def outerTrees(self, trees):
        """
        :type trees: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(trees)
        if n <= 2:
            return trees
        
        hull = []
        trees.sort()
        for t in trees:
            while len(hull) >= 2 and self.cross(hull[-2], hull[-1], t) <= 0:
                hull.pop()
            hull.append(t)
        
        t = trees[0]
        for i in range(1, n):
            if trees[i] != t:
                break
            t = trees[i]
        for i in range(n-1, 0, -1):
            if trees[i] != t:
                break
            t = trees[i]
        while len(hull) >= 2 and self.cross(hull[-2], hull[-1], t) <= 0:
            hull.pop()
        hull.append(t)
        
        return hull
    
    def cross(self, p, q, r):
        return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0])
