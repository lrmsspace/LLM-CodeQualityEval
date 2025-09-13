#https://leetcode.com/problems/longest-happy-string/
#A string s is called happy if it satisfies the following conditions:
#	s only contains the letters 'a', 'b', and 'c'.
#	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
#	s contains at most a occurrences of the letter 'a'.
#	s contains at most b occurrences of the letter 'b'.
#	s contains at most c occurrences of the letter 'c'.
#Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: a = 1, b = 1, c = 7
#Output: "ccaccbcc"
#Explanation: "ccbccacc" would also be a correct answer.
#Example 2:
#Input: a = 7, b = 1, c = 0
#Output: "aabaa"
#Explanation: It is the only correct answer in this case.
# 
#Constraints:
#	0 <= a, b, c <= 100
#	a + b + c > 0
class Solution(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """
        pq = []
        for count, char in ((a, 'a'), (b, 'b'), (c, 'c')):
            if count > 0:
                heapq.heappush(pq, (-count, char))
        res = []
        while len(pq) > 1:
            firstCount, firstChar = heapq.heappop(pq)
            secondCount, secondChar = heapq.heappop(pq)
            res.append(firstChar)
            if firstCount < -1:
                heapq.heappush(pq, (firstCount + 1, firstChar))
            if secondCount < -1:
                heapq.heappush(pq, (secondCount + 1, secondChar))
        if pq:
            res.append(pq[0][1])
        return ''.join(res)
