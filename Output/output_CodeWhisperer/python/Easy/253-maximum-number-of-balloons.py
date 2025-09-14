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
import collections
class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        count = collections.Counter(text)
        return min(count['b'], count['a'], count['l'] // 2, count['o'] // 2, count['n'])    
        