#https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/
#You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.
#There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.
#Return the minimum possible maximum working time of any assignment. 
# 
#Example 1:
#Input: jobs = [3,2,3], k = 3
#Output: 3
#Explanation: By assigning each person one job, the maximum time is 3.
#Example 2:
#Input: jobs = [1,2,4,7,8], k = 2
#Output: 11
#Explanation: Assign the jobs the following way:
#Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
#Worker 2: 4, 7 (working time = 4 + 7 = 11)
#The maximum working time is 11.
# 
#Constraints:
#	1 <= k <= jobs.length <= 12
#	1 <= jobs[i] <= 107
class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        """
        :type jobs: List[int]
        :type k: int
        :rtype: int
        """
        def can_assign(jobs, k, max_time):
            workers = [0] * k
            return self.dfs(jobs, 0, workers, max_time)

        def dfs(jobs, index, workers, max_time):
            if index == len(jobs):
                return True
            for i in range(k):
                if workers[i] + jobs[index] <= max_time:
                    workers[i] += jobs[index]
                    if dfs(jobs, index + 1, workers, max_time):
                        return True
                    workers[i] -= jobs[index]
                if workers[i] == 0:        
                    break
            return False
        
        left, right = max(jobs), sum(jobs)
        while left < right:
            mid = (left + right) // 2
            if can_assign(jobs, k, mid):
                right = mid
            else:
                left = mid + 1
        return left 