#https://leetcode.com/problems/the-skyline-problem/
#A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
#The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:
#	lefti is the x coordinate of the left edge of the ith building.
#	righti is the x coordinate of the right edge of the ith building.
#	heighti is the height of the ith building.
#You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
#The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.
#Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]
# 
#Example 1:
#Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
#Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
#Explanation:
#Figure A shows the buildings of the input.
#Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
#Example 2:
#Input: buildings = [[0,2,3],[2,5,3]]
#Output: [[0,3],[5,0]]
# 
#Constraints:
#	1 <= buildings.length <= 104
#	0 <= lefti < righti <= 231 - 1
#	1 <= heighti <= 231 - 1
#	buildings is sorted by lefti in non-decreasing order.
class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        # 1. 生成所有的关键点
        points = []
        for b in buildings:
            points.append((b[0], -b[2]))  
            points.append((b[1], b[2]))
        points.sort()
        # 2. 初始化结果和堆
        result = []
        heap = [(0, float('inf'))]
        # 3. 遍历所有的关键点
        for x, h in points:
            if h < 0:
                heapq.heappush(heap, (h, x))
            else:
                heap.remove((-h, x))
                heapq.heapify(heap)
            # 4. 获取当前的最大高度
            max_height = -heap[0][0]
            # 5. 如果最大高度发生变化，更新结果
            if not result or max_height != result[-1][1]:
                result.append([x, max_height])
        return result
#         # 1. 生成所有的关键点