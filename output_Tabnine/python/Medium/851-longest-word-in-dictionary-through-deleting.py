#https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
#Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
# 
#Example 1:
#Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
#Output: "apple"
#Example 2:
#Input: s = "abpcplea", dictionary = ["a","b","c"]
#Output: "a"
# 
#Constraints:
#	1 <= s.length <= 1000
#	1 <= dictionary.length <= 1000
#	1 <= dictionary[i].length <= 1000
#	s and dictionary[i] consist of lowercase English letters.
class Solution(object):
    def findLongestWord(self, s, dictionary):
        """
        :type s: str
        :type dictionary: List[str]
        :rtype: str
        """
        # Sort dictionary in descending order by length and lexicographical order
        dictionary.sort(key=lambda x: (-len(x), x))
        
        # Iterate over each word in dictionary
        for word in dictionary:
            # If the word can be formed by deleting characters from s
            if self.is_subsequence(s, word):
                return word
        
        # No possible result found
        return ""
        