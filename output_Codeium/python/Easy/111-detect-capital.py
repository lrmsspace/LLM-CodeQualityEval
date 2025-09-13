#https://leetcode.com/problems/detect-capital/
#We define the usage of capitals in a word to be right when one of the following cases holds:
#	All letters in this word are capitals, like "USA".
#	All letters in this word are not capitals, like "leetcode".
#	Only the first letter in this word is capital, like "Google".
#Given a string word, return true if the usage of capitals in it is right.
# 
#Example 1:
#Input: word = "USA"
#Output: true
#Example 2:
#Input: word = "FlaG"
#Output: false
# 
#Constraints:
#	1 <= word.length <= 100
#	word consists of lowercase and uppercase English letters.
class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if len(word) == 1:
            return True
        if word[0].islower():
            for c in word:
                if c.isupper():
                    return False
            return True
        if word[1].isupper():
            for c in word[1:]:
                if c.islower():
                    return False
            return True
        for c in word[1:]:
            if c.isupper():
                return False
        return True
