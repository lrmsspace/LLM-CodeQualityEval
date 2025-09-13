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
        count = [0] * 3
        ans, left, right = 0, 0, 0
        while right < len(s):
            count[ord(s[right]) - ord('a')] += 1
            while count[0] > 0 and count[1] > 0 and count[2] > 0:
                ans += right - left + 1
                count[ord(s[left]) - ord('a')] -= 1
                left += 1
            right += 1
        return ans
        