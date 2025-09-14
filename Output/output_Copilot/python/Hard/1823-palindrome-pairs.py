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
        def is_palindrome(word):
            return word == word[::-1]

        def add_word_to_dict(word, index):
            if word not in word_dict:
                word_dict[word] = []
            word_dict[word].append(index)

        def find_palindrome_pairs(word, index):
            pairs = []
            for i in range(len(word) + 1):
                prefix = word[:i]
                suffix = word[i:]
                if is_palindrome(prefix):
                    reversed_suffix = suffix[::-1]
                    if reversed_suffix in word_dict:
                        for j in word_dict[reversed_suffix]:
                            if j != index:
                                pairs.append([j, index])
                if i != len(word) and is_palindrome(suffix):  
                    reversed_prefix = prefix[::-1]
                    if reversed_prefix in word_dict:
                        for j in word_dict[reversed_prefix]:
                            if j != index:
                                pairs.append([index, j])
            return pairs

        word_dict = {}
        for i, word in enumerate(words):
            add_word_to_dict(word, i)
        result = []
        for i, word in enumerate(words):
            result.extend(find_palindrome_pairs(word, i))
        return result      