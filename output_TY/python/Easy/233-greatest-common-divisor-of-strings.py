#https://leetcode.com/problems/greatest-common-divisor-of-strings/
#For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
#Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
# 
#Example 1:
#Input: str1 = "ABCABC", str2 = "ABC"
#Output: "ABC"
#Example 2:
#Input: str1 = "ABABAB", str2 = "ABAB"
#Output: "AB"
#Example 3:
#Input: str1 = "LEET", str2 = "CODE"
#Output: ""
# 
#Constraints:
#	1 <= str1.length, str2.length <= 1000
#	str1 and str2 consist of English uppercase letters.
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if str1 == str2:
            return str1
        elif str1 == "":
            return ""
        elif str2 == "":
            return ""
        elif str1[-1] == str2[-1]:
            return self.gcdOfStrings(str1[:-1], str2[:-1]) + str1[-1]
        else:
            return ""
        return ""