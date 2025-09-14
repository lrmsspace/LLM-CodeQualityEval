#https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
#The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
#	For example, the beauty of "abaacc" is 3 - 1 = 2.
#Given a string s, return the sum of beauty of all of its substrings.
# 
#Example 1:
#Input: s = "aabcb"
#Output: 5
#Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
#Example 2:
#Input: s = "aabcbaa"
#Output: 17
# 
#Constraints:
#	1 <= s.length <= 500
#	s consists of only lowercase English letters.
class Solution(object):
    def beautySum(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        
        for i in range(len(s)):
            freq = [0] * 26
            
            for j in range(i, len(s)):
                freq[ord(s[j]) - ord('a')] += 1
                
                max_freq = max(freq)
                min_freq = min(x for x in freq if x > 0)
                
                result += max_freq - min_freq
        
        return result
        