#https://leetcode.com/problems/reorganize-string/
#Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
#Return any possible rearrangement of s or return "" if not possible.
# 
#Example 1:
#Input: s = "aab"
#Output: "aba"
#Example 2:
#Input: s = "aaab"
#Output: ""
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of lowercase English letters.
class Solution(object):
    def reorganizeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        from collections import Counter
        cnt = Counter(s)
        heap = [(-v, k) for k, v in cnt.items()]
        heapq.heapify(heap)
        while len(heap) > 1:
            a, b = heapq.heappop(heap), heapq.heappop(heap)
            if -a[0] > -b[0] + 1: return ""
            heapq.heappush(heap, (a[0] + 1, a[1]))
        return "".join(map(lambda x: x[1] * (-x[0]), heap))
          