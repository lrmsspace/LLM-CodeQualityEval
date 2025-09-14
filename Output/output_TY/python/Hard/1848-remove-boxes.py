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
        n = len(boxes)
        dp = [[[0 for _ in range(n+1)] for _ in range(n+1)] for _ in range(n+1)]
        for i in range(n):
            dp[i][i][1] = (1+i)*(1+i)
        for l in range(2, n+1):
            for i in range(n-l+1):
                j = i+l-1
                for k in range(i, j+1):
                    dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][k][1] + dp[k+1][j][k+1])
        for i in range(n):
            for j in range(n):
                print(dp[i][j])
        return dp[0][n-1][1]