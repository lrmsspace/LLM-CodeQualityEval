#https://leetcode.com/problems/word-break/
#Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
#Note that the same word in the dictionary may be reused multiple times in the segmentation.
# 
#Example 1:
#Input: s = "leetcode", wordDict = ["leet","code"]
#Output: true
#Explanation: Return true because "leetcode" can be segmented as "leet code".
#Example 2:
#Input: s = "applepenapple", wordDict = ["apple","pen"]
#Output: true
#Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
#Note that you are allowed to reuse a dictionary word.
#Example 3:
#Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
#Output: false
# 
#Constraints:
#	1 <= s.length <= 300
#	1 <= wordDict.length <= 1000
#	1 <= wordDict[i].length <= 20
#	s and wordDict[i] consist of only lowercase English letters.
#	All the strings of wordDict are unique.
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        # Initialize a boolean list to track if the substring from index 0 to i can be segmented into a word in the dictionary
        dp = [False] * (len(s) + 1)
        
        # Set the initial value for the first index to True as an empty string can be segmented into an empty word
        dp[0] = True
        
        # Iterate through all possible substrings of s
        for i in range(1, len(s) + 1):
            # Iterate through all words in the dictionary
            for word in wordDict:
                # If the current substring matches the current word and the previous substring can be segmented into a word in the dictionary
                if i >= len(word) and s[i - len(word):i] == word and dp[i - len(word)]:
                    dp[i] = True
                    break
            # If no match is found for the current substring, set the value to False
            if not dp[i]:
                break
        return dp[-1]
        