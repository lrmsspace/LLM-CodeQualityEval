#https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
#Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
# 
#Example 1:
#Input: s = "eleetminicoworoep"
#Output: 13
#Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
#Example 2:
#Input: s = "leetcodeisgreat"
#Output: 5
#Explanation: The longest substring is "leetc" which contains two e's.
#Example 3:
#Input: s = "bcbcbc"
#Output: 6
#Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
# 
#Constraints:
#	1 <= s.length <= 5 x 10^5
#	s contains only lowercase English letters.
class Solution(object):
    def findTheLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        vowels = {'a', 'e', 'i', 'o', 'u'}
        left, right, max_len, count = 0, 0, 0, 0
        
        while right < len(s):
            if s[right] in vowels:
                count += 1
            if count == 2:
                while s[left] not in vowels:
                    left += 1
                    count -= 1
                left += 1
            max_len = max(max_len, right - left + 1)
            right += 1
        
        return max_len
        