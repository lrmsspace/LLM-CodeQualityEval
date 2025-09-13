#https://leetcode.com/problems/decode-string/
#Given an encoded string, return its decoded string.
#The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
#You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
#The test cases are generated so that the length of the output will never exceed 105.
# 
#Example 1:
#Input: s = "3[a]2[bc]"
#Output: "aaabcbc"
#Example 2:
#Input: s = "3[a2[c]]"
#Output: "accaccacc"
#Example 3:
#Input: s = "2[abc]3[cd]ef"
#Output: "abcabccdcdcdef"
# 
#Constraints:
#	1 <= s.length <= 30
#	s consists of lowercase English letters, digits, and square brackets '[]'.
#	s is guaranteed to be a valid input.
#	All the integers in s are in the range [1, 300].
class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        multi = 0
        
        # Iterate over the string s
        i, multi = 0, 0
        stack = []
        while i < len(s):
            # If the character is a digit, calculate the number
            if s[i].isdigit():
                multi = multi * 10 + int(s[i])
            # If the character is a letter, add it to the result
            elif s[i].isalpha():
                res += s[i]
            # If the character is a '[', push the current string and the number to the stack
            elif s[i] == '[':
                stack.append([multi, res])
                res, multi = "", 0
            # If the character is a ']', pop the top element from the stack and add the string to the result
            elif s[i] == ']':
                cur_multi, last_res = stack.pop()
                res = last_res + cur_multi*res
            i += 1
        return res
