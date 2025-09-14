#https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
#You are given a string s.
#A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.
#Return the number of good splits you can make in s.
# 
#Example 1:
#Input: s = "aacaba"
#Output: 2
#Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
#("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
#("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
#("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
#("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
#("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
#Example 2:
#Input: s = "abcd"
#Output: 1
#Explanation: Split the string as follows ("ab", "cd").
# 
#Constraints:
#	1 <= s.length <= 105
#	s consists of only lowercase English letters.
class Solution(object):
    def numSplits(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Initialize count for distinct letters in both sides
        left_count, right_count = [0] * 26, [0] * 26
        
        # Count distinct letters in the first half of the string
        for i in range(len(s) // 2):
            left_count[ord(s[i]) - ord('a')] += 1
        
        # Count distinct letters in the second half of the string
        for i in range(len(s) // 2, len(s)):
            right_count[ord(s[i]) - ord('a')] += 1
        
        # Initialize result count
        result = 0
        
        # Iterate over the second half of the string
        for i in range(len(s) // 2):
            # Decrement the count of the letter in the first half
            left_count[ord(s[i]) - ord('a')] -= 1
        
        # If the counts of distinct letters are equal for both halves, increment the result count
        if left_count == right_count:
            result += 1
        
        # Iterate over the remaining letters in the second half of the string
        for i in range(len(s) // 2, len(s) - 1):
            # Decrement the count of the letter in the first half
            left_count[ord(s[i - len(s) // 2]) - ord('a')] -= 1
            
            # Increment the count of the letter in the second half
            right_count[ord(s[i]) - ord('a')] += 1
            
            # If the counts of distinct letters are equal for both halves, increment the result count
            if left_count == right_count:
                result += 1
        
        return result
        