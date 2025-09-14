#https://leetcode.com/problems/keyboard-row/
#Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
#Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.
#In the American keyboard:
#	the first row consists of the characters "qwertyuiop",
#	the second row consists of the characters "asdfghjkl", and
#	the third row consists of the characters "zxcvbnm".
# 
#Example 1:
#Input: words = ["Hello","Alaska","Dad","Peace"]
#Output: ["Alaska","Dad"]
#Explanation:
#Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.
#Example 2:
#Input: words = ["omk"]
#Output: []
#Example 3:
#Input: words = ["adsdf","sfd"]
#Output: ["adsdf","sfd"]
# 
#Constraints:
#	1 <= words.length <= 20
#	1 <= words[i].length <= 100
#	words[i] consists of English letters (both lowercase and uppercase). 
class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row1 = set("qwertyuiop")
        row2 = set("asdfghjkl")
        row3 = set("zxcvbnm")
        res = []
        for word in words:
            word_set = set(word.lower())
            if word_set.issubset(row1) or word_set.issubset(row2) or word_set.issubset(row3):
                res.append(word)
        return res
        