#https://leetcode.com/problems/concatenated-words/
#Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
#A concatenated word is defined as a string that is comprised entirely of at least two shorter words (not necessarily distinct) in the given array.
# 
#Example 1:
#Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
#Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
#Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
#"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
#"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
#Example 2:
#Input: words = ["cat","dog","catdog"]
#Output: ["catdog"]
# 
#Constraints:
#	1 <= words.length <= 104
#	1 <= words[i].length <= 30
#	words[i] consists of only lowercase English letters.
#	All the strings of words are unique.
#	1 <= sum(words[i].length) <= 105
class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        words_set = set(words)
        result = []

        def can_form(word):
            if word in words_set:
                return True
            for i in range(1, len(word)):
                prefix = word[:i]
                suffix = word[i:]
                if prefix in words_set and can_form(suffix):
                    return True
            return False

        for word in words:
            if can_form(word):
                result.append(word)

        return result        