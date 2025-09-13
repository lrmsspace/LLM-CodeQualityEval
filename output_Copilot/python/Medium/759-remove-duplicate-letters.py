#https://leetcode.com/problems/remove-duplicate-letters/
#Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
# 
#Example 1:
#Input: s = "bcabc"
#Output: "abc"
#Example 2:
#Input: s = "cbacdcbc"
#Output: "acdb"
# 
#Constraints:
#	1 <= s.length <= 104
#	s consists of lowercase English letters.
# 
#Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 记录每个字符最后出现的位置
        last_occurrence = {char: i for i, char in enumerate(s)}
        stack = [] 
        seen = set()
        for i, char in enumerate(s):
            # 如果字符已经在栈中，跳过
            if char in seen:
                continue
            # 如果当前字符比栈顶字符小，并且栈顶字符在后面还会出现，则弹出栈顶字符
            while stack and char < stack[-1] and i < last_occurrence[stack[-1]]:
                seen.remove(stack.pop())
            # 添加当前字符到栈中和已见集合中
            stack.append(char)
            seen.add(char)
        # 将栈中的字符连接成字符串并返回
        return ''.join(stack)       