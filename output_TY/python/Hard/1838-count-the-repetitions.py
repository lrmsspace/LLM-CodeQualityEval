#https://leetcode.com/problems/count-the-repetitions/
#We define str = [s, n] as the string str which consists of the string s concatenated n times.
#	For example, str == ["abc", 3] =="abcabcabc".
#We define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1.
#	For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our definition by removing the bolded underlined characters.
#You are given two strings s1 and s2 and two integers n1 and n2. You have the two strings str1 = [s1, n1] and str2 = [s2, n2].
#Return the maximum integer m such that str = [str2, m] can be obtained from str1.
# 
#Example 1:
#Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
#Output: 2
#Example 2:
#Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
#Output: 1
# 
#Constraints:
#	1 <= s1.length, s2.length <= 100
#	s1 and s2 consist of lowercase English letters.
#	1 <= n1, n2 <= 106
class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        """
        :type s1: str
        :type n1: int
        :type s2: str
        :type n2: int
        :rtype: int
        """
        s1_len = len(s1)
        s2_len = len(s2)
        s1_count = 0
        s2_count = 0
        s1_index = 0
        s2_index = 0
        s1_index_list = []
        s2_index_list = []
        for i in range(n1):
            if s1[s1_index] == s2[s2_index]:
                s2_index += 1
                if s2_index == s2_len:
                    s2_index = 0
                    s2_count += 1
            s1_index += 1
            if s1_index == s1_len:
                s1_index = 0
                s1_count += 1
                s1_index_list.append(s1_count)
                s2_index_list.append(s2_count)
        s1_cycle_count = s1_count - s1_index_list[0]
        s2_cycle_count = s2_count - s2_index_list[0]
        s1_cycle_len = s1_index_list[1] - s1_index_list[0]
        s2_cycle_len = s2_index_list[1] - s2_index_list[0]
        s1_cycle_num = (n1 - 1) / s1_cycle_len

        s1_count = s1_cycle_count * s1_cycle_num

        for i in range(s1_cycle_num):
            s1_index = 0
            for j in range(s1_cycle_len):
                if s1[s1_index] == s2[s2_index]:
                    s2_index += 1
                    if s2_index == s2_len:
                        s2_index = 0
                        s2_count += 1
                s1_index += 1
                if s1_index == s1_len:
                    s1_index = 0
                    s1_count += 1
        return (s2_count * s1_cycle_num + s2_cycle_count) / n2