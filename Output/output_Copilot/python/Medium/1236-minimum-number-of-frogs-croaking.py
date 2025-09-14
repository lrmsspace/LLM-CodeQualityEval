#https://leetcode.com/problems/minimum-number-of-frogs-croaking/
#You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
#Return the minimum number of different frogs to finish all the croaks in the given string.
#A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.
# 
#Example 1:
#Input: croakOfFrogs = "croakcroak"
#Output: 1 
#Explanation: One frog yelling "croak" twice.
#Example 2:
#Input: croakOfFrogs = "crcoakroak"
#Output: 2 
#Explanation: The minimum number of frogs is two. 
#The first frog could yell "crcoakroak".
#The second frog could yell later "crcoakroak".
#Example 3:
#Input: croakOfFrogs = "croakcrook"
#Output: -1
#Explanation: The given string is an invalid combination of "croak" from different frogs.
# 
#Constraints:
#	1 <= croakOfFrogs.length <= 105
#	croakOfFrogs is either 'c', 'r', 'o', 'a', or 'k'.
class Solution(object):
    def minNumberOfFrogs(self, croakOfFrogs):
        """
        :type croakOfFrogs: str
        :rtype: int
        """
        # 1. 使用 Counter 统计字符出现次数
        count = Counter(croakOfFrogs)

        # 2. 判断是否包含所有的字符
        if count['c'] != count['r'] or count['r'] != count['o'] or count['o'] != count['a'] or count['a'] != count['k']:
            return -1

        # 3. 计算最小的青蛙数量
        frogs = 0
        croak_count = 0
        for char in croakOfFrogs:
            if char == 'c':
                frogs += 1
            elif char == 'k':
                frogs -= 1
            croak_count += (char == 'c') - (char == 'k')

            # 4. 如果有负数，说明有多余的 k，返回 -1
            if frogs < 0:
                return -1

        return max(frogs, croak_count) if frogs == 0 else -1