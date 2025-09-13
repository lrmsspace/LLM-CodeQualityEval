#https://leetcode.com/problems/heaters/
#Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
#Every house can be warmed, as long as the house is within the heater's warm radius range. 
#Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
#Notice that all the heaters follow your radius standard, and the warm radius will the same.
# 
#Example 1:
#Input: houses = [1,2,3], heaters = [2]
#Output: 1
#Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
#Example 2:
#Input: houses = [1,2,3,4], heaters = [1,4]
#Output: 1
#Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.
#Example 3:
#Input: houses = [1,5], heaters = [2]
#Output: 3
# 
#Constraints:
#	1 <= houses.length, heaters.length <= 3 * 104
#	1 <= houses[i], heaters[i] <= 109
class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        heaters.sort()
        ans = 0
        for house in houses:
            idx = bisect.bisect_right(heaters, house)
            if idx == 0:
                ans = max(ans, heaters[0] - house)
            elif idx == len(heaters):
                ans = max(ans, house - heaters[-1])
            else:
                ans = max(ans, min(house - heaters[idx - 1], heaters[idx] - house))
        return ans