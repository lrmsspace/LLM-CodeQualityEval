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
        # Sort the jobs in descending order
        jobs.sort(reverse=True)
        
        # Initialize the minimum time required to finish all jobs
        min_time = 0
        
        # Initialize the maximum number of completed jobs
        max_jobs = 0
        
        # Initialize a heap to keep track of the maximum time required for each worker
        heap = []
        
        # Assign each worker a job
        for job in jobs:
            # If the heap is empty or the maximum time required for the current worker is less than or equal to the maximum time required for the worker with the smallest time, assign the current job to the current worker
            if not heap or heap[0] <= job:
                heapq.heappush(heap, job)
                max_jobs += 1
                # Update the minimum time required to finish all jobs
                min_time = max(min_time, job)
        
        # If the number of assigned workers is less than k, assign the remaining jobs to the workers with the smallest time

        while max_jobs < k:
            min_time += heapq.heappop(heap)
            max_jobs += 1
        
        return min_time
        