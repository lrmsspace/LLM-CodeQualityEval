#https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
#You are given a string text. You can swap two of the characters in the text.
#Return the length of the longest substring with repeated characters.
# 
#Example 1:
#Input: text = "ababa"
#Output: 3
#Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
#Example 2:
#Input: text = "aaabaaa"
#Output: 6
#Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
#Example 3:
#Input: text = "aaaaa"
#Output: 5
#Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
# 
#Constraints:
#	1 <= text.length <= 2 * 104
#	text consist of lowercase English characters only.
class Solution(object):
    def maxRepOpt1(self, text):
        """
        :type text: str
        :rtype: int
        """
        count = collections.Counter(text)
        res = max(count.values())
        for i in xrange(26):
            ch = chr(ord('a') + i)
            i, j, count = 0, 0, 0
            while j < len(text):
                if text[j] == ch:
                    count += 1
                if j - i + 1 - count > 1:
                    count -= 1 if text[i] == ch else 0
                    i += 1
                res = max(res, count)
                j += 1
        return res

        