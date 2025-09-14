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
        def rabin_karp(m):
            h = 0
            for i in range(m):
                h = (h * 26 + nums[i]) % mod
            seen = {h}
            a_l = pow(26, m - 1, mod)
            for i in range(1, len(nums) - m + 1):
                h = (h * 26 - nums[i - 1] * a_l + nums[i + m - 1]) % mod
                if h in seen:
                    return i
                seen.add(h)
            return -1
        
        nums = [ord(c) - ord('a') for c in s]
        mod = 2**63 - 1
        lo, hi = 0, len(s) - 1
        q = 26
        res = 0
        while lo <= hi:
            mi = (lo + hi) // 2
            cur = rabin_karp(mi)
            if cur != -1:
                lo = mi + 1
                res = cur
            else:
                hi = mi - 1
        return s[res:res + lo - 1]
        