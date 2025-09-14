#https://leetcode.com/problems/minimum-time-to-complete-trips/
#You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.
#Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.
#You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.
# 
#Example 1:
#Input: time = [1,2,3], totalTrips = 5
#Output: 3
#Explanation:
#- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
#  The total number of trips completed is 1 + 0 + 0 = 1.
#- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
#  The total number of trips completed is 2 + 1 + 0 = 3.
#- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
#  The total number of trips completed is 3 + 1 + 1 = 5.
#So the minimum time needed for all buses to complete at least 5 trips is 3.
#Example 2:
#Input: time = [2], totalTrips = 1
#Output: 2
#Explanation:
#There is only one bus, and it will complete its first trip at t = 2.
#So the minimum time needed to complete 1 trip is 2.
# 
#Constraints:
#	1 <= time.length <= 105
#	1 <= time[i], totalTrips <= 107
class Solution(object):
    def minimumTime(self, time, totalTrips):
        """
        :type time: List[int]
        :type totalTrips: int
        :rtype: int
        """
        # Initialize the prefix sum array
        prefix_sum = [0] * (len(time) + 1)
        for i in range(len(time)):
            prefix_sum[i + 1] = prefix_sum[i] + time[i]
        
        # Initialize the minimum time
        min_time = float('inf')
        
        # Iterate over the prefix sums
        for i in range(1, len(prefix_sum) + 1):
            # Calculate the number of trips completed by the buses at the current prefix sum
            trips_completed = sum(prefix_sum[i] // t for t in time)
            
            # Calculate the remaining trips
            remaining_trips = totalTrips - trips_completed
            
            # If the remaining trips are positive, update the minimum time
            if remaining_trips > 0:

                min_time = min(min_time, prefix_sum[i] * (remaining_trips + 1) // remaining_trips)
        
        return min_time
        