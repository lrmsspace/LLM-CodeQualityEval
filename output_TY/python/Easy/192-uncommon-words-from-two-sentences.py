#https://leetcode.com/problems/uncommon-words-from-two-sentences/
#A sentence is a string of single-space separated words where each word consists only of lowercase letters.
#A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
#Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.
# 
#Example 1:
#Input: s1 = "this apple is sweet", s2 = "this apple is sour"
#Output: ["sweet","sour"]
#Explanation:
#The word "sweet" appears only in s1, while the word "sour" appears only in s2.
#Example 2:
#Input: s1 = "apple apple", s2 = "banana"
#Output: ["banana"]
# 
#Constraints:
#	1 <= s1.length, s2.length <= 200
#	s1 and s2 consist of lowercase English letters and spaces.
#	s1 and s2 do not have leading or trailing spaces.
#	All the words in s1 and s2 are separated by a single space.
class Solution(object):
    def uncommonFromSentences(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: List[str]
        """
        s1 = s1.split(" ")
        s2 = s2.split(" ")
        s1_dict = {}
        s2_dict = {}
        for i in s1:
            if i in s1_dict:
                s1_dict[i] += 1
            else:
                s1_dict[i] = 1
        for i in s2:
            if i in s2_dict:
                s2_dict[i] += 1
            else:
                s2_dict[i] = 1
        result = []
        for i in s1_dict:
            if s1_dict[i] == 1 and i not in s2_dict:
                result.append(i)
        for i in s2_dict:
            if s2_dict[i] == 1 and i not in s1_dict:
                result.append(i)
        return result