#https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
#Given a string s, return the maximum number of occurrences of any substring under the following rules:
#	The number of unique characters in the substring must be less than or equal to maxLetters.
#	The substring size must be between minSize and maxSize inclusive.
# 
#Example 1:
#Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
#Output: 2
#Explanation: Substring "aab" has 2 occurrences in the original string.
#It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
#Example 2:
#Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
#Output: 2
#Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
# 
#Constraints:
#	1 <= s.length <= 105
#	1 <= maxLetters <= 26
#	1 <= minSize <= maxSize <= min(26, s.length)
#	s consists of only lowercase English letters.
class Solution(object):
    def maxFreq(self, s, maxLetters, minSize, maxSize):
        """
        :type s: str
        :type maxLetters: int
        :type minSize: int
        :type maxSize: int
        :rtype: int
        """
        if len(s) < minSize:
            return 0
        
        freq = [0] * 26
        ans = 0
        left = 0
        
        for right in range(len(s)):
            freq[ord(s[right]) - ord('a')] += 1
            while right - left + 1 > maxSize or len(set(freq)) > maxLetters:
                freq[ord(s[left]) - ord('a')] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        
        return ans