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
        # 计算 s1 中每个字符在 s2 中出现的次数
        count = [0] * 26
        for char in s2:
            count[ord(char) - ord('a')] += 1

        # 计算 s1 中每个字符在 s2 中出现的次数
        total_count = [0] * 26
        for char in s1:
            total_count[ord(char) - ord('a')] += 1

        # 计算可以重复多少次
        result = float('inf')
        for i in range(26):
            if total_count[i] > 0:
                result = min(result, count[i] // total_count[i])

        return result * n1 // n2 if result != float('inf') else 0        