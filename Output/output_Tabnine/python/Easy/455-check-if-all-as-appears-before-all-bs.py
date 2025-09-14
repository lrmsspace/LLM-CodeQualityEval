#https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
#Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.
# 
#Example 1:
#Input: s = "aaabbb"
#Output: true
#Explanation:
#The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
#Hence, every 'a' appears before every 'b' and we return true.
#Example 2:
#Input: s = "abab"
#Output: false
#Explanation:
#There is an 'a' at index 2 and a 'b' at index 1.
#Hence, not every 'a' appears before every 'b' and we return false.
#Example 3:
#Input: s = "bbb"
#Output: true
#Explanation:
#There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
# 
#Constraints:
#	1 <= s.length <= 100
#	s[i] is either 'a' or 'b'.
class Solution(object):
    def checkString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Initialize a list to keep track of the indices of 'a' and 'b'
        a_indices = []
        b_indices = []
        
        # Iterate over the string
        for i in range(len(s)):
            if s[i] == 'a':
                a_indices.append(i)
            elif s[i] == 'b':
                b_indices.append(i)
        
        # Check if every 'a' appears before every 'b'
        for i in range(len(a_indices)):
            if a_indices[i] >= b_indices[i]:
                return False
        
        return True
        