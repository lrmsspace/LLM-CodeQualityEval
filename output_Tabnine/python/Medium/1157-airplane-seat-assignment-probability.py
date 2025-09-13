#https://leetcode.com/problems/airplane-seat-assignment-probability/
#n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of the passengers will:
#	Take their own seat if it is still available, and
#	Pick other seats randomly when they find their seat occupied
#Return the probability that the nth person gets his own seat.
# 
#Example 1:
#Input: n = 1
#Output: 1.00000
#Explanation: The first person can only get the first seat.
#Example 2:
#Input: n = 2
#Output: 0.50000
#Explanation: The second person has a probability of 0.5 to get the second seat (when first person gets the first seat).
# 
#Constraints:
#	1 <= n <= 105
class Solution(object):
    def nthPersonGetsNthSeat(self, n):
        """
        :type n: int
        :rtype: float
        """
        # If the nth seat is taken, the probability is 0.
        if n == 1:
            return 1.0
        
        # If the nth seat is available, the probability is the probability of the (n-1)th seat being taken.
        # So, the probability is (n-1) / n.
        return (n-1) / n
        