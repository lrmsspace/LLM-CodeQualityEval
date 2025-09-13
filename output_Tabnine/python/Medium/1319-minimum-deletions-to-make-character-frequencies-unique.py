#https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
#A string s is called good if there are no two different characters in s that have the same frequency.
#Given a string s, return the minimum number of characters you need to delete to make s good.
#The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.
# 
#Example 1:
#Input: s = "aab"
#Output: 0
#Explanation: s is already good.
#Example 2:
#Input: s = "aaabbbcc"
#Output: 2
#Explanation: You can delete two 'b's resulting in the good string "aaabcc".
#Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
#Example 3:
#Input: s = "ceabaacb"
#Output: 2
#Explanation: You can delete both 'c's resulting in the good string "eabaab".
#Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
# 
#Constraints:
#	1 <= s.length <= 105
#	s contains only lowercase English letters.
class Solution(object):
    def minDeletions(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Create a frequency map
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1
        
        # Sort the frequency map in descending order
        freq_sorted = sorted(freq.items(), key=lambda x: x[1], reverse=True)
        
        # Initialize the total deletions
        deletions = 0
        
        # Iterate over the sorted frequency map
        for char, count in freq_sorted:
            # If the current character's frequency is greater than 1,
            # then we need to delete at least one character of the same frequency
            if count > 1:
                deletions += count - 1
        
        return deletions
        