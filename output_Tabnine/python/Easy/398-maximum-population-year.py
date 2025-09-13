#https://leetcode.com/problems/maximum-population-year/
#You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.
#The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.
#Return the earliest year with the maximum population.
# 
#Example 1:
#Input: logs = [[1993,1999],[2000,2010]]
#Output: 1993
#Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
#Example 2:
#Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
#Output: 1960
#Explanation: 
#The maximum population is 2, and it had happened in years 1960 and 1970.
#The earlier year between them is 1960.
# 
#Constraints:
#	1 <= logs.length <= 100
#	1950 <= birthi < deathi <= 2050
class Solution(object):
    def maximumPopulation(self, logs):
        """
        :type logs: List[List[int]]
        :rtype: int
        """
        # Initialize a list to store the population counts for each year
        populations = [0] * (2051 - 1950)
        
        # Iterate through the logs and update the population counts
        for birth, death in logs:
            populations[birth - 1950] += 1
            populations[death - 1950] -= 1
        
        # Initialize the maximum population and the earliest year
        max_population = 0
        earliest_year = 0
        
        # Iterate through the population counts and update the maximum population and earliest year
        for year, population in enumerate(populations):
            max_population = max(max_population, population)
            if population == max_population:
                earliest_year = year + 1950
        
        return earliest_year
        