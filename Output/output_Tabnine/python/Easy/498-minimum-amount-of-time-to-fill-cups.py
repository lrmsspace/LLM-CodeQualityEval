#https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
#You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.
#You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.
# 
#Example 1:
#Input: amount = [1,4,2]
#Output: 4
#Explanation: One way to fill up the cups is:
#Second 1: Fill up a cold cup and a warm cup.
#Second 2: Fill up a warm cup and a hot cup.
#Second 3: Fill up a warm cup and a hot cup.
#Second 4: Fill up a warm cup.
#It can be proven that 4 is the minimum number of seconds needed.
#Example 2:
#Input: amount = [5,4,4]
#Output: 7
#Explanation: One way to fill up the cups is:
#Second 1: Fill up a cold cup, and a hot cup.
#Second 2: Fill up a cold cup, and a warm cup.
#Second 3: Fill up a cold cup, and a warm cup.
#Second 4: Fill up a warm cup, and a hot cup.
#Second 5: Fill up a cold cup, and a hot cup.
#Second 6: Fill up a cold cup, and a warm cup.
#Second 7: Fill up a hot cup.
#Example 3:
#Input: amount = [5,0,0]
#Output: 5
#Explanation: Every second, we fill up a cold cup.
# 
#Constraints:
#	amount.length == 3
#	0 <= amount[i] <= 100
class Solution(object):
    def fillCups(self, amount):
        """
        :type amount: List[int]
        :rtype: int
        """
        # Initialize a heap to store the cups with their types and the time they will be used
        heap = []
        
        # Add the cups to the heap with their types and the time they will be used
        for i, a in enumerate(amount):
            heapq.heappush(heap, (a, i))
        
        # Initialize the time counter and the current type of water
        time = 0
        cur_type = 0
        
        while heap:
            # Get the number of cups of the current type and the time they will be used
            num, _ = heapq.heappop(heap)
            
            # If the current type of water is different from the type of the cups, increment the time counter
            if cur_type!= _:
                time += 1
                cur_type = _
            
            # If the current type of water has cups left, add them back to the heap
            if num > 0:
                heapq.heappush(heap, (num-1, _))
        
        return time
        
        