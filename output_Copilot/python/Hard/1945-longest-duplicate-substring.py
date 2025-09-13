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
        def search(length):
            seen = set()
            for i in range(len(s) - length + 1):
                substring = s[i:i + length]
                if substring in seen:
                    return i
                seen.add(substring)
            return -1

        left, right = 1, len(s)
        start = -1
        while left <= right:
            mid = (left + right) // 2
            if search(mid) != -1:
                start = search(mid)
                left = mid + 1
            else:
                right = mid - 1

        return s[start:start + left - 1] if start != -1 else ""        