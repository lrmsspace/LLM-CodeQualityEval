#https://leetcode.com/problems/maximum-length-of-pair-chain/
#You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
#A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
#Return the length longest chain which can be formed.
#You do not need to use up all the given intervals. You can select pairs in any order.
# 
#Example 1:
#Input: pairs = [[1,2],[2,3],[3,4]]
#Output: 2
#Explanation: The longest chain is [1,2] -> [3,4].
#Example 2:
#Input: pairs = [[1,2],[7,8],[4,5]]
#Output: 3
#Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
# 
#Constraints:
#	n == pairs.length
#	1 <= n <= 1000
#	-1000 <= lefti < righti <= 1000
class Solution(object):
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        # Sort the pairs by their right values
        pairs.sort(key=lambda x: x[1])
        
        # Initialize the maximum length of the chain to 0
        max_length = 0
        
        # Iterate through the sorted pairs
        for pair in pairs:
            # If the current pair's left value is greater than or equal to the previous pair's right value,
            # it means the current pair can be added to the chain without violating the pairwise order
            if pair[0] >= max_length:
                max_length += 1
        
        return max_length
        