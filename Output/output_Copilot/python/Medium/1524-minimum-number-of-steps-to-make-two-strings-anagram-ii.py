#https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/
#You are given two strings s and t. In one step, you can append any character to either s or t.
#Return the minimum number of steps to make s and t anagrams of each other.
#An anagram of a string is a string that contains the same characters with a different (or the same) ordering.
# 
#Example 1:
#Input: s = "leetcode", t = "coats"
#Output: 7
#Explanation: 
#- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcodeas".
#- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coatsleede".
#"leetcodeas" and "coatsleede" are now anagrams of each other.
#We used a total of 2 + 5 = 7 steps.
#It can be shown that there is no way to make them anagrams of each other with less than 7 steps.
#Example 2:
#Input: s = "night", t = "thing"
#Output: 0
#Explanation: The given strings are already anagrams of each other. Thus, we do not need any further steps.
# 
#Constraints:
#	1 <= s.length, t.length <= 2 * 105
#	s and t consist of lowercase English letters.
class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        from collections import Counter
        count_s = Counter(s)
        count_t = Counter(t)
        steps = 0
        for char in count_s:
            if char not in count_t:
                steps += count_s[char]
            else:
                steps += max(0, count_s[char] - count_t[char])
        for char in count_t:
            if char not in count_s:
                steps += count_t[char]
            else:
                steps += max(0, count_t[char] - count_s[char])
        return steps        