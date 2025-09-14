#https://leetcode.com/problems/remove-boxes/
#You are given several boxes with different colors represented by different positive numbers.
#You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
#Return the maximum points you can get.
# 
#Example 1:
#Input: boxes = [1,3,2,2,2,3,4,3,1]
#Output: 23
#Explanation:
#[1, 3, 2, 2, 2, 3, 4, 3, 1] 
#----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
#----> [1, 3, 3, 3, 1] (1*1=1 points) 
#----> [1, 1] (3*3=9 points) 
#----> [] (2*2=4 points)
#Example 2:
#Input: boxes = [1,1,1]
#Output: 9
#Example 3:
#Input: boxes = [1]
#Output: 1
# 
#Constraints:
#	1 <= boxes.length <= 100
#	1 <= boxes[i] <= 100
class Solution(object):
    def removeBoxes(self, boxes):
        """
        :type boxes: List[int]
        :rtype: int
        """
        memo = {}
        def dp(l, r, k):
            if (l, r, k) in memo:
                return memo[(l, r, k)]
            if l > r:
                return 0
            if l == r:
                return (k + 1) * (k + 1)
            m = -1
            for i in range(l, r + 1):
                if boxes[i] == boxes[l]:
                    m = i
                else:
                    break
            res = (k + m - l + 1) * (k + m - l + 1) + dp(m + 1, r, 0)
            for i in range(l, r):
                if boxes[i] != boxes[l]:
                    res = max(res, dp(l, i, 0) + dp(i + 1, r, k + m - l))
            memo[(l, r, k)] = res
            return res
        return dp(0, len(boxes) - 1, 0)
