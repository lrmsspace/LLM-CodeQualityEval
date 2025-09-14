#https://leetcode.com/problems/find-all-anagrams-in-a-string/
#Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
# 
#Example 1:
#Input: s = "cbaebabacd", p = "abc"
#Output: [0,6]
#Explanation:
#The substring with start index = 0 is "cba", which is an anagram of "abc".
#The substring with start index = 6 is "bac", which is an anagram of "abc".
#Example 2:
#Input: s = "abab", p = "ab"
#Output: [0,1,2]
#Explanation:
#The substring with start index = 0 is "ab", which is an anagram of "ab".
#The substring with start index = 1 is "ba", which is an anagram of "ab".
#The substring with start index = 2 is "ab", which is an anagram of "ab".
# 
#Constraints:
#	1 <= s.length, p.length <= 3 * 104
#	s and p consist of lowercase English letters.
class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        n, m = len(s), len(p)
        if n < m:
            return []
        res = []
        s_cnt = [0] * 26
        p_cnt = [0] * 26
        for i in range(m):
            s_cnt[ord(s[i]) - ord('a')] += 1
            p_cnt[ord(p[i]) - ord('a')] += 1
        if s_cnt == p_cnt:
            res.append(0)
        for i in range(m, n):
            s_cnt[ord(s[i]) - ord('a')] += 1
            s_cnt[ord(s[i - m]) - ord('a')] -= 1
            if s_cnt == p_cnt:
                res.append(i - m + 1)
        return res