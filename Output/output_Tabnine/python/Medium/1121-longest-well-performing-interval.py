#https://leetcode.com/problems/longest-well-performing-interval/
#We are given hours, a list of the number of hours worked per day for a given employee.
#A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
#A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
#Return the length of the longest well-performing interval.
# 
#Example 1:
#Input: hours = [9,9,6,0,6,6,9]
#Output: 3
#Explanation: The longest well-performing interval is [9,9,6].
#Example 2:
#Input: hours = [6,6,6]
#Output: 0
# 
#Constraints:
#	1 <= hours.length <= 104
#	0 <= hours[i] <= 16
class Solution(object):
    def longestWPI(self, hours):
        """
        :type hours: List[int]
        :rtype: int
        """
        # Initialize a stack to store the indices of hours.
        stack = []
        
        # Initialize the count of tiring days and non-tiring days.
        tiring_days = 0
        non_tiring_days = 0
        
        # Iterate over the hours in reverse order.
        for i in range(len(hours) - 1, -1, -1):
            # If the current hour is greater than 8, increment the count of tiring days.
            if hours[i] > 8:
                tiring_days += 1
            
            # If the count of tiring days is greater than the count of non-tiring days,
            # push the current index onto the stack.
            elif tiring_days > non_tiring_days:
                stack.append(i)
            
            # Otherwise, update the count of non-tiring days.
            else:
                non_tiring_days += 1
        
        # Initialize the maximum length of the well-performing interval.
        max_length = 0
        
        # Iterate over the indices in the stack.
        for i in range(len(stack)):
            # Calculate the length of the well-performing interval.
            length = stack[i] - stack[i - 1] - 1
            
            # Update the maximum length if necessary.
            max_length = max(max_length, length)
        
        # Return the maximum length of the well-performing interval.
        return max_length
        