#https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/
#You are given a 0-indexed integer array forts of length n representing the positions of several forts. forts[i] can be -1, 0, or 1 where:
#	-1 represents there is no fort at the ith position.
#	0 indicates there is an enemy fort at the ith position.
#	1 indicates the fort at the ith the position is under your command.
#Now you have decided to move your army from one of your forts at position i to an empty position j such that:
#	0 <= i, j <= n - 1
#	The army travels over enemy forts only. Formally, for all k where min(i,j) < k < max(i,j), forts[k] == 0.
#While moving the army, all the enemy forts that come in the way are captured.
#Return the maximum number of enemy forts that can be captured. In case it is impossible to move your army, or you do not have any fort under your command, return 0.
# 
#Example 1:
#Input: forts = [1,0,0,-1,0,0,0,0,1]
#Output: 4
#Explanation:
#- Moving the army from position 0 to position 3 captures 2 enemy forts, at 1 and 2.
#- Moving the army from position 8 to position 3 captures 4 enemy forts.
#Since 4 is the maximum number of enemy forts that can be captured, we return 4.
#Example 2:
#Input: forts = [0,0,1,-1]
#Output: 0
#Explanation: Since no enemy fort can be captured, 0 is returned.
# 
#Constraints:
#	1 <= forts.length <= 1000
#	-1 <= forts[i] <= 1
class Solution(object):
    def captureForts(self, forts):
        """
        :type forts: List[int]
        :rtype: int
        """
        max_captured = 0
        for i in range(len(forts)):
            if forts[i] == 1:
                captured = 0
                for j in range(i+1, len(forts)):
                    if forts[j] == 0:
                        captured += 1
                    else:
                        break
                for j in range(i-1, -1, -1):
                    if forts[j] == 0:
                        captured += 1
                    else:
                        break
                max_captured = max(max_captured, captured)
        return max_captured

