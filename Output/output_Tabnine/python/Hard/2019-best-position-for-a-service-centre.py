#https://leetcode.com/problems/best-position-for-a-service-centre/
#A delivery company wants to build a new service center in a new city. The company knows the positions of all the customers in this city on a 2D-Map and wants to build the new center in a position such that the sum of the euclidean distances to all customers is minimum.
#Given an array positions where positions[i] = [xi, yi] is the position of the ith customer on the map, return the minimum sum of the euclidean distances to all customers.
#In other words, you need to choose the position of the service center [xcentre, ycentre] such that the following formula is minimized:
#Answers within 10-5 of the actual value will be accepted.
# 
#Example 1:
#Input: positions = [[0,1],[1,0],[1,2],[2,1]]
#Output: 4.00000
#Explanation: As shown, you can see that choosing [xcentre, ycentre] = [1, 1] will make the distance to each customer = 1, the sum of all distances is 4 which is the minimum possible we can achieve.
#Example 2:
#Input: positions = [[1,1],[3,3]]
#Output: 2.82843
#Explanation: The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843
# 
#Constraints:
#	1 <= positions.length <= 50
#	positions[i].length == 2
#	0 <= xi, yi <= 100
class Solution(object):
    def getMinDistSum(self, positions):
        """
        :type positions: List[List[int]]
        :rtype: float
        """
        def dist(p1, p2):
            return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5
        
        n = len(positions)
        best = float('inf')
        
        for i in range(n):
            for j in range(i + 1, n):
                x, y = (positions[i][0] + positions[j][0]) / 2, (positions[i][1] + positions[j][1]) / 2
                d = sum(dist(p, [x, y]) for p in positions)
                best = min(best, d)
        
        return best
        