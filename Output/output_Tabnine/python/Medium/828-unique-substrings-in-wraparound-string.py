#https://leetcode.com/problems/unique-substrings-in-wraparound-string/
#We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:
#	"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
#Given a string s, return the number of unique non-empty substrings of s are present in base.
# 
#Example 1:
#Input: s = "a"
#Output: 1
#Explanation: Only the substring "a" of s is in base.
#Example 2:
#Input: s = "cac"
#Output: 2
#Explanation: There are two substrings ("a", "c") of s in base.
#Example 3:
#Input: s = "zab"
#Output: 6
#Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of s in base.
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of lowercase English letters.
class Solution(object):
    def findSubstringInWraproundString(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize the count of substrings and the last index of the current substring
        count, last = 0, -1
        
        # Iterate through the string, updating the count and last index as we go
        for i, c in enumerate(s):
            # If the current character is the next letter in the alphabet after the last character,
            # increment the count and update the last index
            if (c - s[(i - 1) % len(s)]) % 26 == 1:
                count += i - last
                last = i
        
        # Return the total count of substrings
        return count
        