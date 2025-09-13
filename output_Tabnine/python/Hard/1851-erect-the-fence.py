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
        def cross_product(p1, p2, p3):
            return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0])
        
        def orientation(p1, p2, p3):
            return cross_product(p1, p2, p3)
        
        def graham_scan(points):
            n = len(points)
            if n <= 3:
                return points
            
            points.sort(key=lambda x: (x[1], x[0]))
            p0 = points[0]
            points[0], points[n//2] = points[n//2], points[0]
            points[n//2], points[n-1] = points[n-1], points[n//2]
        
            stack = [p0, points[1], points[2]]
            for i in range(3, n):
                while len(stack) >= 2 and orientation(stack[-2], stack[-1], points[i]) <= 0:
                    stack.pop()
                stack.append(points[i])
        
            return stack
        