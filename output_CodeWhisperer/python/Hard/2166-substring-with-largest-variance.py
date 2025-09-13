#https://leetcode.com/problems/substring-with-largest-variance/
#The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
#Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: s = "aababbb"
#Output: 3
#Explanation:
#All possible variances along with their respective substrings are listed below:
#- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
#- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
#- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
#- Variance 3 for substring "babbb".
#Since the largest possible variance is 3, we return it.
#Example 2:
#Input: s = "abcde"
#Output: 0
#Explanation:
#No letter occurs more than once in s, so the variance of every substring is 0.
# 
#Constraints:
#	1 <= s.length <= 104
#	s consists of lowercase English letters.
class Solution(object):
    def largestVariance(self, s):
        """
        :type s: str
        :rtype: int
        """
        counter = collections.Counter(s)
        res = 0
        for a in counter.keys():
            for b in counter.keys():
                if a == b:
                    continue
                rem_a, rem_b = counter[a], counter[b]
                diff = 0
                diff_rev = float('-inf')
                for ch in s:
                    if ch == a:
                        diff += 1
                        rem_a -= 1
                    elif ch == b:
                        diff -= 1
                        rem_b -= 1
                    else:
                        continue
                    if diff < 0:
                        rem_a, rem_b = counter[a], counter[b]
                        diff = 0
                    elif rem_a == 0 or rem_b == 0:
                        break
                    diff_rev = max(diff_rev, diff)
                res = max(res, diff_rev)
        return res
        