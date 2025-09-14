#https://leetcode.com/problems/rectangle-area-ii/
#You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.
#Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.
#Return the total area. Since the answer may be too large, return it modulo 109 + 7.
# 
#Example 1:
#Input: rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
#Output: 6
#Explanation: A total area of 6 is covered by all three rectangles, as illustrated in the picture.
#From (1,1) to (2,2), the green and red rectangles overlap.
#From (1,0) to (2,3), all three rectangles overlap.
#Example 2:
#Input: rectangles = [[0,0,1000000000,1000000000]]
#Output: 49
#Explanation: The answer is 1018 modulo (109 + 7), which is 49.
# 
#Constraints:
#	1 <= rectangles.length <= 200
#	rectanges[i].length == 4
#	0 <= xi1, yi1, xi2, yi2 <= 109
#	xi1 <= xi2
#	yi1 <= yi2
class Solution(object):
    def rectangleArea(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        import bisect
        import itertools
        import operator
        xs = sorted(set(itertools.chain(*rectangles)))
        xs_map = {x: i for i, x in enumerate(xs)}
        ys = sorted(set(itertools.chain(*(rect[1:] for rect in rectangles))))
        ys_map = {y: i for i, y in enumerate(ys)}
        n = len(ys)
        grid = [[0] * n for _ in range(len(xs))]
        for x1, y1, x2, y2 in rectangles:
            for x in xrange(xs_map[x1], xs_map[x2]):
                for y in xrange(ys_map[y1], ys_map[y2]):
                    grid[x][y] = 1
        res = 0
        for x in xrange(len(xs) - 1):
            x1, x2 = xs[x], xs[x + 1]
            for y in xrange(n):
                y1, y2 = ys[y], ys[y + 1]
                res += (x2 - x1) * (y2 - y1) * grid[x][y]
        return res % (10 ** 9 + 7)