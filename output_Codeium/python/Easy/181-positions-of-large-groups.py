#https://leetcode.com/problems/positions-of-large-groups/
#In a string s of lowercase letters, these letters form consecutive groups of the same character.
#For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".
#A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].
#A group is considered large if it has 3 or more characters.
#Return the intervals of every large group sorted in increasing order by start index.
# 
#Example 1:
#Input: s = "abbxxxxzzy"
#Output: [[3,6]]
#Explanation: "xxxx" is the only large group with start index 3 and end index 6.
#Example 2:
#Input: s = "abc"
#Output: []
#Explanation: We have groups "a", "b", and "c", none of which are large groups.
#Example 3:
#Input: s = "abcdddeeeeaabbbcd"
#Output: [[3,5],[6,9],[12,14]]
#Explanation: The large groups are "ddd", "eeee", and "bbb".
# 
#Constraints:
#	1 <= s.length <= 1000
#	s contains lowercase English letters only.
class Solution(object):
    def largeGroupPositions(self, s):
        """
        :type s: str
        :rtype: List[List[int]]
        """
        result = []
        start = 0
        for end in range(1, len(s)):
            if s[end] != s[end - 1]:
                if end - start >= 3:
                    result.append([start, end - 1])
                start = end
        if len(s) - start >= 3:
            result.append([start, len(s) - 1])
        return result
