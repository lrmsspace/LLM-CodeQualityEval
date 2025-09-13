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
        max_len = 0
        last = {text[0]: 0}
        curr = 1
        for i in range(1, len(text)):
            if text[i] == text[i - 1]:
                curr += 1
            else:
                max_len = max(max_len, curr)
                curr = 1
                if text[i] in last:
                    max_len = max(max_len, i - last[text[i]] - 1)
                last[text[i - 1]] = i - 1
        return max(max_len, curr)
