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
        vowels = {'a': 1, 'e': 2, 'i': 4, 'o': 8, 'u': 16}
        mask_map = {0: -1}
        mask = 0
        res = 0
        for i, c in enumerate(s):
            if c in vowels:
                mask ^= vowels[c]
            if mask in mask_map:
                res = max(res, i - mask_map[mask])
            else:
                mask_map[mask] = i
        return res