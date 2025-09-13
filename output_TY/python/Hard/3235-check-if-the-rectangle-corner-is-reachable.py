# You are given two positive integers xCorner and yCorner, and a 2D array circles, where circles[i] = [xi, yi, ri] denotes a circle with center at (xi, yi) and radius ri.
# There is a rectangle in the coordinate plane with its bottom left corner at the origin and top right corner at the coordinate (xCorner, yCorner). You need to check whether there is a path from the bottom left corner to the top right corner such that the entire path lies inside the rectangle, does not touch or lie inside any circle, and touches the rectangle only at the two corners.
# Return true if such a path exists, and false otherwise.
# Example 1:
# Input: xCorner = 3, yCorner = 4, circles = [[2,1,1]]
# Output: true
# Explanation:
# The black curve shows a possible path between (0, 0) and (3, 4).
# Example 2:
# Input: xCorner = 3, yCorner = 3, circles = [[1,1,2]]
# Output: false
# Explanation:
# No path exists from (0, 0) to (3, 3).
# Example 3:
# Input: xCorner = 3, yCorner = 3, circles = [[2,1,1],[1,2,1]]
# Output: false
# Explanation:
# No path exists from (0, 0) to (3, 3).
# Example 4:
# Input: xCorner = 4, yCorner = 4, circles = [[5,5,1]]
# Output: true
# Explanation:
# Constraints:
# 3 <= xCorner, yCorner <= 109
# 1 <= circles.length <= 1000
# circles[i].length == 3
# 1 <= xi, yi, ri <= 109

import math

class Solution(object):
    def canReachCorner(self, xCorner, yCorner, circles):
        """
        :type xCorner: int
        :type yCorner: int
        :type circles: List[List[int]]
        :rtype: bool
        """
        parent = {}

        def find(p):
            if parent[p] != p:
                parent[p] = find(parent[p])
            return parent[p]

        def union(p, q):
            pp, pq = find(p), find(q)
            if pp != pq:
                parent[pp] = pq

        # 初始化并查集
        n = len(circles)
        parent = {i: i for i in range(n)}

        # 预处理：检查是否有某个圆直接覆盖起点或终点
        for i, (x, y, r) in enumerate(circles):
            if x - r <= 0 and y - r <= 0 and x + r >= 0 and y + r >= 0:
                return False  # 圆包含 (0, 0)
            if x - r <= xCorner and y - r <= yCorner and x + r >= xCorner and y + r >= yCorner:
                return False  # 圆包含 (xCorner, yCorner)

        # 合并相交的圆
        for i in range(n):
            x1, y1, r1 = circles[i]
            for j in range(i + 1, n):
                x2, y2, r2 = circles[j]
                dx = x1 - x2
                dy = y1 - y2
                dist = math.sqrt(dx * dx + dy * dy)
                if dist <= r1 + r2:
                    union(i, j)

        # 检查哪些圆/连通块接触到矩形的四边
        top = set()
        bottom = set()
        left = set()
        right = set()

        for i, (x, y, r) in enumerate(circles):
            if y + r >= yCorner:
                top.add(find(i))
            if y - r <= 0:
                bottom.add(find(i))
            if x - r <= 0:
                left.add(find(i))
            if x + r >= xCorner:
                right.add(find(i))

        # 检查是否有连通区域同时碰到上下、或左右，形成隔离
        if top & bottom:
            return False
        if left & right:
            return False

        # 检查是否有连通区域同时碰到左+右+上 or 左+右+下 等组合，也构成隔离
        for i in range(n):
            root = find(i)
            xc, yc, rc = circles[i]
            touches_top = yc + rc >= yCorner
            touches_bottom = yc - rc <= 0
            touches_left = xc - rc <= 0
            touches_right = xc + rc >= xCorner

            # 是否形成包围路径起点和终点的屏障
            if (touches_left and touches_right) or (touches_top and touches_bottom) or \
               (touches_left and touches_top) or (touches_bottom and touches_right):
                # 检查是否该区域连接了左右或上下
                if root in left and root in right:
                    return False
                if root in top and root in bottom:
                    return False

        return True