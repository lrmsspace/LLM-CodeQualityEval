#https://leetcode.com/problems/prison-cells-after-n-days/
#There are 8 prison cells in a row and each cell is either occupied or vacant.
#Each day, whether the cell is occupied or vacant changes according to the following rules:
#	If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
#	Otherwise, it becomes vacant.
#Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
#You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
#Return the state of the prison after n days (i.e., n such changes described above).
# 
#Example 1:
#Input: cells = [0,1,0,1,1,0,0,1], n = 7
#Output: [0,0,1,1,0,0,0,0]
#Explanation: The following table summarizes the state of the prison on each day:
#Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
#Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
#Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
#Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
#Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
#Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
#Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
#Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
#Example 2:
#Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
#Output: [0,0,1,1,1,1,1,0]
# 
#Constraints:
#	cells.length == 8
#	cells[i] is either 0 or 1.
#	1 <= n <= 109
class Solution(object):
    def prisonAfterNDays(self, cells, n):
        """
        :type cells: List[int]
        :type n: int
        :rtype: List[int]
        """
        # 1. 先把cells的第一位和最后一位都置为0
        cells[0] = 0
        cells[-1] = 0

        # 2. 用一个临时数组来存储每一天的状态
        temp = [0] * 8

        # 3. 循环n天
        for i in range(n):
            # 4. 遍历cells的每个元素，判断是否符合条件
            for j in range(1, 7):
                if cells[j - 1] == cells[j + 1]:
                    temp[j] = 1
                else:
                    temp[j] = 0

            # 5. 把temp赋值给cells
            cells = temp[:]

        return cells        