#https://leetcode.com/problems/car-pooling/
#There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
#You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
#Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
# 
#Example 1:
#Input: trips = [[2,1,5],[3,3,7]], capacity = 4
#Output: false
#Example 2:
#Input: trips = [[2,1,5],[3,3,7]], capacity = 5
#Output: true
# 
#Constraints:
#	1 <= trips.length <= 1000
#	trips[i].length == 3
#	1 <= numPassengersi <= 100
#	0 <= fromi < toi <= 1000
#	1 <= capacity <= 105
class Solution(object):
    def carPooling(self, trips, capacity):
        """
        :type trips: List[List[int]]
        :type capacity: int
        :rtype: bool
        """
        # 1. 使用差分数组记录每个位置的乘客变化
        # 2. 遍历 trips 数组，更新差分数组
        # 3. 遍历差分数组，计算当前乘客数量，判断是否超过容量
        # 4. 时间复杂度 O(n)，空间复杂度 O(1)
        diff = [0] * 1001
        
        for trip in trips:
            num_passengers, start, end = trip
            diff[start] += num_passengers
            diff[end] -= num_passengers
        
        current_passengers = 0
        
        for i in range(1001):
            current_passengers += diff[i]
            if current_passengers > capacity:
                return False
        
        return True