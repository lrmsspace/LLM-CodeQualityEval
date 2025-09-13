#https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
#Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.
#It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.
#Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.
# 
#Example 1:
#Input: s = "?zs"
#Output: "azs"
#Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
#Example 2:
#Input: s = "ubv?w"
#Output: "ubvaw"
#Explanation: There are 24 solutions for this problem. Only "v" and "w" are invalid modifications as the strings will consist of consecutive repeating characters in "ubvvw" and "ubvww".
# 
#Constraints:
#	1 <= s.length <= 100
#	s consist of lowercase English letters and '?'.
class Solution(object):
    def modifyString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Initialize a list to store the final string
        result = list(s)
        
        # Iterate through the string
        for i in range(len(s)):
            # If the current character is '?', convert it to the next lowercase letter
            if result[i] == '?':
                for j in range(ord('a'), ord('z') + 1):
                    # Check if the next character is the same as the current one
                    if result[i + 1]!= chr(j):
                        result[i] = chr(j)
                        break
        
        # Convert the list back to a string and return it
        return ''.join(result)
        