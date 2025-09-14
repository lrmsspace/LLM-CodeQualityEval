#https://leetcode.com/problems/optimal-partition-of-string/
#Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.
#Return the minimum number of substrings in such a partition.
#Note that each character should belong to exactly one substring in a partition.
# 
#Example 1:
#Input: s = "abacaba"
#Output: 4
#Explanation:
#Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
#It can be shown that 4 is the minimum number of substrings needed.
#Example 2:
#Input: s = "ssssss"
#Output: 6
#Explanation:
#The only valid partition is ("s","s","s","s","s","s").
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of only English lowercase letters.
class Solution(object):
    def partitionString(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 记录每个字符的出现次数
        char_count = {}
        # 初始化分割数为1
        partitions = 1

        for char in s:
            # 如果字符已经出现过，增加分割数，并重置字符计数
            if char in char_count:
                partitions += 1
                char_count.clear()
            # 更新字符计数
            char_count[char] = 1

        return partitions        