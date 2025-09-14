#https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
#Let's define a function countUniqueChars(s) that returns the number of unique characters in s.
#	For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
#Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.
#Notice that some substrings can be repeated so in this case you have to count the repeated ones too.
# 
#Example 1:
#Input: s = "ABC"
#Output: 10
#Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
#Every substring is composed with only unique letters.
#Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
#Example 2:
#Input: s = "ABA"
#Output: 8
#Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
#Example 3:
#Input: s = "LEETCODE"
#Output: 92
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of uppercase English letters only.
class Solution(object):
    def uniqueLetterString(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize the count array with zeros
        count = [0] * 26
        result = 0
        
        # Initialize two pointers, left and right, pointing to the first and last character of the string, respectively
        left = 0
        right = 0
        
        # Iterate through the string
        while right < len(s):
            # Increment the count of the current character at the right pointer
            count[ord(s[right]) - ord('A')] += 1
            
            # If the count of the current character is 1, it means we have found a unique character
            if count[ord(s[right]) - ord('A')] == 1:
                # Add the length of the substring between the previous unique character and the current character to the result
                result += right - left
            
            # Move the left pointer to the right
            left += 1
            
            # Move the right pointer to the right
            right += 1
        
        # Return the result
        return result
        