#https://leetcode.com/problems/count-square-sum-triples/
#A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
#Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
# 
#Example 1:
#Input: n = 5
#Output: 2
#Explanation: The square triples are (3,4,5) and (4,3,5).
#Example 2:
#Input: n = 10
#Output: 4
#Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
# 
#Constraints:
#	1 <= n <= 250
class Solution(object):
    def countTriples(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        for a in range(1, n + 1):
            for b in range(a, n + 1):
                c_square = a * a + b * b
                c = int(c_square ** 0.5)
                if c * c == c_square and c <= n:
                    count += 1 if a == b else 2  
        return count      