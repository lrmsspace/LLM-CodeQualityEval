#https://leetcode.com/problems/make-number-of-distinct-characters-equal/
#You are given two 0-indexed strings word1 and word2.
#A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
#Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.
# 
#Example 1:
#Input: word1 = "ac", word2 = "b"
#Output: false
#Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
#Example 2:
#Input: word1 = "abcc", word2 = "aab"
#Output: true
#Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.
#Example 3:
#Input: word1 = "abcde", word2 = "fghij"
#Output: true
#Explanation: Both resulting strings will have 5 distinct characters, regardless of which indices we swap.
# 
#Constraints:
#	1 <= word1.length, word2.length <= 105
#	word1 and word2 consist of only lowercase English letters.
class Solution(object):
    def isItPossible(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: bool
        """
        cnt1 = [0] * 26
        cnt2 = [0] * 26
        for c in word1:
            cnt1[ord(c) - ord('a')] += 1
        for c in word2:
            cnt2[ord(c) - ord('a')] += 1
        for i in range(26):
            for j in range(26):
                if cnt1[i] > 0 and cnt2[j] > 0:
                    cnt1[i] -= 1
                    cnt2[j] -= 1
                    if i == j:
                        cnt1[i] += 1
                        cnt2[j] += 1
        elif cnt1[i] > 0 or cnt2[j] > 0:
            return True
        return False