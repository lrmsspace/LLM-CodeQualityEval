#https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
#There are n tasks assigned to you. The task times are represented as an integer array tasks of length n, where the ith task takes tasks[i] hours to finish. A work session is when you work for at most sessionTime consecutive hours and then take a break.
#You should finish the given tasks in a way that satisfies the following conditions:
#	If you start a task in a work session, you must complete it in the same work session.
#	You can start a new task immediately after finishing the previous one.
#	You may complete the tasks in any order.
#Given tasks and sessionTime, return the minimum number of work sessions needed to finish all the tasks following the conditions above.
#The tests are generated such that sessionTime is greater than or equal to the maximum element in tasks[i].
# 
#Example 1:
#Input: tasks = [1,2,3], sessionTime = 3
#Output: 2
#Explanation: You can finish the tasks in two work sessions.
#- First work session: finish the first and the second tasks in 1 + 2 = 3 hours.
#- Second work session: finish the third task in 3 hours.
#Example 2:
#Input: tasks = [3,1,3,1,1], sessionTime = 8
#Output: 2
#Explanation: You can finish the tasks in two work sessions.
#- First work session: finish all the tasks except the last one in 3 + 1 + 3 + 1 = 8 hours.
#- Second work session: finish the last task in 1 hour.
#Example 3:
#Input: tasks = [1,2,3,4,5], sessionTime = 15
#Output: 1
#Explanation: You can finish all the tasks in one work session.
# 
#Constraints:
#	n == tasks.length
#	1 <= n <= 14
#	1 <= tasks[i] <= 10
#	max(tasks[i]) <= sessionTime <= 15
class Solution(object):
    def minSessions(self, tasks, sessionTime):
        """
        :type tasks: List[int]
        :type sessionTime: int
        :rtype: int
        """
        # Sort the tasks in descending order
        tasks.sort(reverse=True)
        
        # Initialize the dp array to store the minimum number of sessions needed for each number of tasks
        dp = [float('inf')] * (sum(tasks) + 1)
        dp[0] = 0
        
        # Iterate from 1 to the sum of tasks
        for i in range(1, sum(tasks) + 1):
            # Iterate from the maximum number of tasks to the minimum number of tasks
            for j in range(len(tasks), 0, -1):
                # If the current task is smaller than or equal to the current number of tasks
                if i >= tasks[j - 1]:
                    # Update the minimum number of sessions needed for the current number of tasks
                    dp[i] = min(dp[i], dp[i - tasks[j - 1]] + 1)
            # If the minimum number of sessions needed for the current number of tasks is still infinity
            if dp[i] == float('inf'):
                # Return -1 since it is impossible to finish all the tasks in the given sessionTime
                return -1
        
        # Return the minimum number of sessions needed to finish all the tasks
        return dp[sum(tasks)]
        