#https://leetcode.com/problems/set-intersection-size-at-least-two/
#You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.
#A containing set is an array nums where each interval from intervals has at least two integers in nums.
#	For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
#Return the minimum possible size of a containing set.
# 
#Example 1:
#Input: intervals = [[1,3],[3,7],[8,9]]
#Output: 5
#Explanation: let nums = [2, 3, 4, 8, 9].
#It can be shown that there cannot be any containing array of size 4.
#Example 2:
#Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
#Output: 3
#Explanation: let nums = [2, 3, 4].
#It can be shown that there cannot be any containing array of size 2.
#Example 3:
#Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
#Output: 5
#Explanation: let nums = [1, 2, 3, 4, 5].
#It can be shown that there cannot be any containing array of size 4.
# 
#Constraints:
#	1 <= intervals.length <= 3000
#	intervals[i].length == 2
#	0 <= starti < endi <= 108
class Solution(object):
    def intersectionSizeTwo(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        # Sort the intervals based on the start of each interval
        intervals.sort(key=lambda x: x[0])
        
        # Initialize the minimum size of a containing set
        min_size = 2
        
        # Initialize the two pointers to the first and second intervals
        left, right = 0, 1
        
        # Iterate through the sorted intervals
        while right < len(intervals):
            # If the current interval overlaps with the previous interval, merge them
            if intervals[right][0] <= intervals[left][1]:
                intervals[left][1] = max(intervals[left][1], intervals[right][1])
                right += 1
            else:
                # If the current interval does not overlap with the previous interval, move the left pointer to the next interval
                left += 1
                right += 1
                # Update the minimum size of a containing set
                min_size = max(min_size, intervals[left][1] - intervals[left][0] + 1)
        
        return min_size
        