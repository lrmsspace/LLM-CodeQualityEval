#https://leetcode.com/problems/reformat-the-string/
#You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
#You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
#Return the reformatted string or return an empty string if it is impossible to reformat the string.
# 
#Example 1:
#Input: s = "a0b1c2"
#Output: "0a1b2c"
#Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
#Example 2:
#Input: s = "leetcode"
#Output: ""
#Explanation: "leetcode" has only characters so we cannot separate them by digits.
#Example 3:
#Input: s = "1229857369"
#Output: ""
#Explanation: "1229857369" has only digits so we cannot separate them by characters.
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of only lowercase English letters and/or digits.
class Solution(object):
    def reformat(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 统计字母和数字的数量
        letter_count = sum(c.isalpha() for c in s)
        digit_count = len(s) - letter_count
        
        # 如果字母和数字的数量差超过1，则无法交替排列
        if abs(letter_count - digit_count) > 1:
            return ""
        
        # 根据字母和数字的数量决定先填充哪个类型
        if letter_count > digit_count:
            first, second = 'a', '0'
        else:
            first, second = '0', 'a'
        
        result = []
        for c in s:
            if c.isalpha():
                result.append(first)
                first = c
            else:
                result.append(second)
                second = c
        
        return ''.join(result) if len(result) == len(s) else ""        