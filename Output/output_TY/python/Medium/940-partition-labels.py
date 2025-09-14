#https://leetcode.com/problems/partition-labels/
#You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
#Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
#Return a list of integers representing the size of these parts.
# 
#Example 1:
#Input: s = "ababcbacadefegdehijhklij"
#Output: [9,7,8]
#Explanation:
#The partition is "ababcbaca", "defegde", "hijhklij".
#This is a partition so that each letter appears in at most one part.
#A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
#Example 2:
#Input: s = "eccbbbbdec"
#Output: [10]
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of lowercase English letters.
class Solution(object):
    def partitionLabels(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        n = len(s)
        last_occ = [0] * 26
        for i in range(n):
            last_occ[ord(s[i]) - ord('a')] = i
        res = []
        start = end = 0
        for i in range(n):
            end = max(end, last_occ[ord(s[i]) - ord('a')])
            if i == end:
                res.append(end - start + 1)
                start = end + 1
        return res