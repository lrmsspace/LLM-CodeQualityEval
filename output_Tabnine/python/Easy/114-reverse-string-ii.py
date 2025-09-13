#https://leetcode.com/problems/reverse-string-ii/
#Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
#If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
# 
#Example 1:
#Input: s = "abcdefg", k = 2
#Output: "bacdfeg"
#Example 2:
#Input: s = "abcd", k = 2
#Output: "bacd"
# 
#Constraints:
#	1 <= s.length <= 104
#	s consists of only lowercase English letters.
#	1 <= k <= 104
class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        # Convert the string to a list to make it mutable
        s_list = list(s)
        
        # Iterate over the list in steps of 2k
        for i in range(0, len(s_list), 2 * k):
            # Reverse the first k characters
            s_list[i:i+k] = s_list[i:i+k][::-1]
        
        # Join the list back into a string and return
        return ''.join(s_list)
        