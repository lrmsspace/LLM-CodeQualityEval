#https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
#Given a string s consisting only of characters a, b and c.
#Return the number of substrings containing at least one occurrence of all these characters a, b and c.
# 
#Example 1:
#Input: s = "abcabc"
#Output: 10
#Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
#Example 2:
#Input: s = "aaacb"
#Output: 3
#Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
#Example 3:
#Input: s = "abc"
#Output: 1
# 
#Constraints:
#	3 <= s.length <= 5 x 10^4
#	s only consists of a, b or c characters.
class Solution(object):
    def numberOfSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        ans = n*(n+1)//2
        for i in range(n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    if s[i] in s[j:k+1] and s[j] in s[i:k+1] and s[k] in s[i:j+1]:
                        ans -= 1
        return ans
    
