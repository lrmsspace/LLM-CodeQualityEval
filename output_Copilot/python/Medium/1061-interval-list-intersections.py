#https://leetcode.com/problems/interval-list-intersections/
#You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
#Return the intersection of these two interval lists.
#A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
#The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
# 
#Example 1:
#Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
#Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
#Example 2:
#Input: firstList = [[1,3],[5,9]], secondList = []
#Output: []
# 
#Constraints:
#	0 <= firstList.length, secondList.length <= 1000
#	firstList.length + secondList.length >= 1
#	0 <= starti < endi <= 109
#	endi < starti+1
#	0 <= startj < endj <= 109 
#	endj < startj+1
class Solution(object):
    def intervalIntersection(self, firstList, secondList):
        """
        :type firstList: List[List[int]]
        :type secondList: List[List[int]]
        :rtype: List[List[int]]
        """
        # 1. 初始化结果列表和指针
        # 2. 遍历两个列表，找到交集并添加到结果列表
        # 3. 返回结果列表
        # 4. 时间复杂度O(n)，空间复杂度O(n)
        result = []
        i, j = 0, 0
        
        while i < len(firstList) and j < len(secondList):
            start1, end1 = firstList[i]
            start2, end2 = secondList[j]
            
            # 找到交集的起始和结束位置
            start = max(start1, start2)
            end = min(end1, end2)
            
            if start <= end:
                result.append([start, end])
            
            # 移动指针
            if end1 < end2:
                i += 1
            else:
                j += 1
        
        return result       