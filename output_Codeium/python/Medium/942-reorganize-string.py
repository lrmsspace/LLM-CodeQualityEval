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
        count = collections.Counter(s)
        maxFREQ = max(count.values())
        if maxFREQ > (len(s) + 1) // 2:
            return ""
        maxHeap = []
        for key, value in count.items():
            heapq.heappush(maxHeap, (-value, key))
        result = []
        while len(maxHeap) > 1:
            freq1, char1 = heapq.heappop(maxHeap)
            freq2, char2 = heapq.heappop(maxHeap)
            result.append(char1)
            result.append(char2)
            if freq1 < -1:
                heapq.heappush(maxHeap, (freq1 + 1, char1))
            if freq2 < -1:
                heapq.heappush(maxHeap, (freq2 + 1, char2))
        if maxHeap:
            result.append(maxHeap[0][1])
        return "".join(result)
