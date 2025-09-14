#https://leetcode.com/problems/letter-case-permutation/
#Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
#Return a list of all possible strings we could create. Return the output in any order.
# 
#Example 1:
#Input: s = "a1b2"
#Output: ["a1b2","a1B2","A1b2","A1B2"]
#Example 2:
#Input: s = "3z4"
#Output: ["3z4","3Z4"]
# 
#Constraints:
#	1 <= s.length <= 12
#	s consists of lowercase English letters, uppercase English letters, and digits.
class Solution(object):
    def letterCasePermutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        def backtrack(index, path):
            if index == len(s):
                res.append(path)
                return
            if s[index].isdigit():
                backtrack(index + 1, path + s[index])
            else:
                backtrack(index + 1, path + s[index].upper())
                backtrack(index + 1, path + s[index].lower())

        res = []
        backtrack(0, "")
        return res