#https://leetcode.com/problems/longest-duplicate-substring/
#Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
#Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".
# 
#Example 1:
#Input: s = "banana"
#Output: "ana"
#Example 2:
#Input: s = "abcd"
#Output: ""
# 
#Constraints:
#	2 <= s.length <= 3 * 104
#	s consists of lowercase English letters.
class Solution(object):
    def longestDupSubstring(self, s):
        """
        :type s: str
        :rtype: str
        """
        def search(s, start, end):
            if start == end:
                return start
            mid = (start + end) // 2
            if check(s, mid):
                return search(s, mid + 1, end)
            else:
                return search(s, start, mid)
        
        def check(s, length):
            seen = set()
            for i in range(len(s) - length + 1):
                if s[i:i+length] in seen:
                    return True
                seen.add(s[i:i+length])
            return False
        
        return s[search(s, 0, len(s)):]