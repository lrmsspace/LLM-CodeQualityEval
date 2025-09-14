#https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
#Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
#	The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
#	A substring that contains a certain character c must also contain all occurrences of c.
#Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
#Notice that you can return the substrings in any order.
# 
#Example 1:
#Input: s = "adefaddaccc"
#Output: ["e","f","ccc"]
#Explanation: The following are all the possible substrings that meet the conditions:
#[
#  "adefaddaccc"
#  "adefadda",
#  "ef",
#  "e",
#  "f",
#  "ccc",
#]
#If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
#Example 2:
#Input: s = "abbaccd"
#Output: ["d","bb","cc"]
#Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.
# 
#Constraints:
#	1 <= s.length <= 105
#	s contains only lowercase English letters.
class Solution(object):
    def maxNumOfSubstrings(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # Initialize variables
        count = [0] * 26
        start = 0
        max_length = 0
        result = []
        
        # Iterate through the string
        for end in range(len(s)):
            # Increment the count of the current character
            count[ord(s[end]) - ord('a')] += 1
            
            # While the count of a character is greater than 0
            while all(count[i] > 0 for i in range(26)):
                # Decrement the count of the character at the start index
                count[ord(s[start]) - ord('a')] -= 1
                
                # Update the maximum length and start index
                max_length = max(max_length, end - start + 1)
                start += 1
            
            # Add the current substring to the result
            result.append(s[start:end+1])
        
        return result
        