#https://leetcode.com/problems/maximum-number-of-balloons/
#Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
#You can use each character in text at most once. Return the maximum number of instances that can be formed.
# 
#Example 1:
#Input: text = "nlaebolko"
#Output: 1
#Example 2:
#Input: text = "loonbalxballpoon"
#Output: 2
#Example 3:
#Input: text = "leetcode"
#Output: 0
# 
#Constraints:
#	1 <= text.length <= 104
#	text consists of lower case English letters only.
# 
#Note: This question is the same as  2287: Rearrange Characters to Make Target String.
class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        b, a, l, o, n = 0, 0, 0, 0, 0
        for c in text:
            if c == 'b':
                b += 1
            elif c == 'a':
                a += 1
            elif c == 'l':
                l += 1
            elif c == 'o':
                o += 1
            elif c == 'n':
                n += 1
        return min(b, a, l//2, o//2, n)
