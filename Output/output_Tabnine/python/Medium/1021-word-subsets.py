#https://leetcode.com/problems/word-subsets/
#You are given two string arrays words1 and words2.
#A string b is a subset of string a if every letter in b occurs in a including multiplicity.
#	For example, "wrr" is a subset of "warrior" but is not a subset of "world".
#A string a from words1 is universal if for every string b in words2, b is a subset of a.
#Return an array of all the universal strings in words1. You may return the answer in any order.
# 
#Example 1:
#Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
#Output: ["facebook","google","leetcode"]
#Example 2:
#Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
#Output: ["apple","google","leetcode"]
# 
#Constraints:
#	1 <= words1.length, words2.length <= 104
#	1 <= words1[i].length, words2[i].length <= 10
#	words1[i] and words2[i] consist only of lowercase English letters.
#	All the strings of words1 are unique.
class Solution(object):
    def wordSubsets(self, words1, words2):
        """
        :type words1: List[str]
        :type words2: List[str]
        :rtype: List[str]
        """
        word_counts = {}
        for word in words2:
            word_count = {}
            for char in word:
                word_count[char] = word_count.get(char, 0) + 1
            for char, count in word_count.items():
                word_counts[char] = max(word_counts.get(char, 0), count)
        
        universal_strings = []
        for word in words1:
            word_count = {}
            for char in word:
                word_count[char] = word_count.get(char, 0) + 1
            is_universal = True
            for char, count in word_counts.items():
                if char not in word_count or word_count[char] < count:
                    is_universal = False
                    break
            if is_universal:
                universal_strings.append(word)
        
        return universal_strings
        