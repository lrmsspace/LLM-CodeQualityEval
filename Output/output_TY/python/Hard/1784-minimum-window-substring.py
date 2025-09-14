#https://leetcode.com/problems/minimum-window-substring/
#Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
#The testcases will be generated such that the answer is unique.
# 
#Example 1:
#Input: s = "ADOBECODEBANC", t = "ABC"
#Output: "BANC"
#Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
#Example 2:
#Input: s = "a", t = "a"
#Output: "a"
#Explanation: The entire string s is the minimum window.
#Example 3:
#Input: s = "a", t = "aa"
#Output: ""
#Explanation: Both 'a's from t must be included in the window.
#Since the largest window of s only has one 'a', return empty string.
# 
#Constraints:
#	m == s.length
#	n == t.length
#	1 <= m, n <= 105
#	s and t consist of uppercase and lowercase English letters.
# 
#Follow up: Could you find an algorithm that runs in O(m + n) time?
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        t_map = {}
        for c in t:
            t_map[c] = t_map.get(c, 0) + 1
        t_count = len(t_map)
        s_map = {}
        left = 0
        right = 0
        ans = ""
        while right < len(s):
            c = s[right]
            s_map[c] = s_map.get(c, 0) + 1
            if c in t_map and s_map[c] == t_map[c]:
                t_count -= 1
            while t_count == 0:
                if ans == "" or right - left + 1 < len(ans):
                    ans = s[left:right+1]
                c = s[left]
                s_map[c] -= 1
                if c in t_map and s_map[c] < t_map[c]:
                    t_count += 1
                left +=1
        return ans
    
