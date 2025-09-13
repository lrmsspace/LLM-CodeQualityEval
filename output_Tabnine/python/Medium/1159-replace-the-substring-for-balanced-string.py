#https://leetcode.com/problems/replace-the-substring-for-balanced-string/
#You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
#A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
#Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
# 
#Example 1:
#Input: s = "QWER"
#Output: 0
#Explanation: s is already balanced.
#Example 2:
#Input: s = "QQWE"
#Output: 1
#Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
#Example 3:
#Input: s = "QQQW"
#Output: 2
#Explanation: We can replace the first "QQ" to "ER". 
# 
#Constraints:
#	n == s.length
#	4 <= n <= 105
#	n is a multiple of 4.
#	s contains only 'Q', 'W', 'E', and 'R'.
class Solution(object):
    def balancedString(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Count the frequency of each character
        count = [0] * 4
        for char in s:
            count[ord(char) - ord('Q')] += 1
        
        # Initialize the minimum length and the count of each character
        min_length = len(s)
        char_count = dict(count)
        
        # Use two pointers to find the minimum length
        left, right = 0, 0
        while right < len(s):
            # Replace the character at the right pointer if necessary
            char_count[ord(s[right]) - ord('Q')] -= 1
            if char_count[ord(s[right]) - ord('Q')] < 0:
                char_count[ord(s[left]) - ord('Q')] += 1
                left += 1
            
            # Update the minimum length
            min_length = min(min_length, right - left + 1)
        
        return min_length
        