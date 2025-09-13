#https://leetcode.com/problems/verbal-arithmetic-puzzle/
#Given an equation, represented by words on the left side and the result on the right side.
#You need to check if the equation is solvable under the following rules:
#	Each character is decoded as one digit (0 - 9).
#	No two characters can map to the same digit.
#	Each words[i] and result are decoded as one number without leading zeros.
#	Sum of numbers on the left side (words) will equal to the number on the right side (result).
#Return true if the equation is solvable, otherwise return false.
# 
#Example 1:
#Input: words = ["SEND","MORE"], result = "MONEY"
#Output: true
#Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
#Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
#Example 2:
#Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
#Output: true
#Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
#Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
#Example 3:
#Input: words = ["LEET","CODE"], result = "POINT"
#Output: false
#Explanation: There is no possible mapping to satisfy the equation, so we return false.
#Note that two different characters cannot map to the same digit.
# 
#Constraints:
#	2 <= words.length <= 5
#	1 <= words[i].length, result.length <= 7
#	words[i], result contain only uppercase English letters.
#	The number of different characters used in the expression is at most 10.
class Solution(object):
    def isSolvable(self, words, result):
        """
        :type words: List[str]
        :type result: str
        :rtype: bool
        """
        # 1. 统计所有字符
        chars = set()
        for word in words:
            chars.update(word)
        chars.update(result)

        # 2. 如果字符数大于10，返回False
        if len(chars) > 10:
            return False

        # 3. 构建字符到数字的映射
        char_to_digit = {}
        for i, char in enumerate(chars):
            char_to_digit[char] = i

        # 4. 检查是否有前导零
        for word in words + [result]:
            if len(word) > 1 and char_to_digit[word[0]] == 0:
                return False

        # 5. 计算左侧和右侧的值
        left_sum = sum(int(''.join(str(char_to_digit[char]) for char in word)) for word in words)
        right_sum = int(''.join(str(char_to_digit[char]) for char in result))

        return left_sum == right_sum        