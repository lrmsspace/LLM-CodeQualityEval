#https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/
#You are given an integer array rolls of length n and an integer k. You roll a k sided dice numbered from 1 to k, n times, where the result of the ith roll is rolls[i].
#Return the length of the shortest sequence of rolls so that there's no such subsequence in rolls.
#A sequence of rolls of length len is the result of rolling a k sided dice len times.
# 
#Example 1:
#Input: rolls = [4,2,1,2,3,3,2,4,1], k = 4
#Output: 3
#Explanation: Every sequence of rolls of length 1, [1], [2], [3], [4], can be taken from rolls.
#Every sequence of rolls of length 2, [1, 1], [1, 2], ..., [4, 4], can be taken from rolls.
#The sequence [1, 4, 2] cannot be taken from rolls, so we return 3.
#Note that there are other sequences that cannot be taken from rolls.
#Example 2:
#Input: rolls = [1,1,2,2], k = 2
#Output: 2
#Explanation: Every sequence of rolls of length 1, [1], [2], can be taken from rolls.
#The sequence [2, 1] cannot be taken from rolls, so we return 2.
#Note that there are other sequences that cannot be taken from rolls but [2, 1] is the shortest.
#Example 3:
#Input: rolls = [1,1,3,2,2,2,3,3], k = 4
#Output: 1
#Explanation: The sequence [4] cannot be taken from rolls, so we return 1.
#Note that there are other sequences that cannot be taken from rolls but [4] is the shortest.
# 
#Constraints:
#	n == rolls.length
#	1 <= n <= 105
#	1 <= rolls[i] <= k <= 105
class Solution(object):
    def shortestSequence(self, rolls, k):
        """
        :type rolls: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize a set to keep track of the unique elements in rolls
        seen = set()
        # Initialize a variable to keep track of the length of the longest subsequence
        longest_subsequence_length = 0
        
        # Iterate through each roll in the rolls list
        for roll in rolls:
            # If the roll is not already in the seen set, add it
            if roll not in seen:
                seen.add(roll)
                # If the size of the seen set is equal to k, we have a complete subsequence
                if len(seen) == k:
                    # Increment the longest subsequence length
                    longest_subsequence_length += 1
                    # Clear the seen set for the next subsequence
                    seen.clear()
        
        # Return the length of the shortest impossible sequence
        return longest_subsequence_length + 1 if len(seen) > 0 else longest_subsequence_length        