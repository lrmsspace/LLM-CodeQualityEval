#https://leetcode.com/problems/palindrome-pairs/
#You are given a 0-indexed array of unique strings words.
#A palindrome pair is a pair of integers (i, j) such that:
#	0 <= i, j < words.length,
#	i != j, and
#	words[i] + words[j] (the concatenation of the two strings) is a palindrome.
#Return an array of all the palindrome pairs of words.
#You must write an algorithm with O(sum of words[i].length) runtime complexity.
# 
#Example 1:
#Input: words = ["abcd","dcba","lls","s","sssll"]
#Output: [[0,1],[1,0],[3,2],[2,4]]
#Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
#Example 2:
#Input: words = ["bat","tab","cat"]
#Output: [[0,1],[1,0]]
#Explanation: The palindromes are ["battab","tabbat"]
#Example 3:
#Input: words = ["a",""]
#Output: [[0,1],[1,0]]
#Explanation: The palindromes are ["a","a"]
# 
#Constraints:
#	1 <= words.length <= 5000
#	0 <= words[i].length <= 300
#	words[i] consists of lowercase English letters.
class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        lookup = {word: i for i, word in enumerate(words)}
        pairs = []
        for i, word1 in enumerate(words):
            for j in range(len(word1) + 1):
                prefix, suffix = word1[:j], word1[j:]
                if prefix == prefix[::-1]:
                    back = suffix[::-1]
                    if back != word1:
                        k = lookup.get(back, None)
                        if k != i:
                            pairs.append([i, k])
                if j != 0 and suffix == suffix[::-1]:
                    back = prefix[::-1]
                    k = lookup.get(back, None)
                    if k != i:
                        pairs.append([k, i])
        return pairs
