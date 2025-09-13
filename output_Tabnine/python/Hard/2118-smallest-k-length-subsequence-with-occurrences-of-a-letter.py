#https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/
#You are given a string s, an integer k, a letter letter, and an integer repetition.
#Return the lexicographically smallest subsequence of s of length k that has the letter letter appear at least repetition times. The test cases are generated so that the letter appears in s at least repetition times.
#A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
#A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
# 
#Example 1:
#Input: s = "leet", k = 3, letter = "e", repetition = 1
#Output: "eet"
#Explanation: There are four subsequences of length 3 that have the letter 'e' appear at least 1 time:
#- "lee" (from "leet")
#- "let" (from "leet")
#- "let" (from "leet")
#- "eet" (from "leet")
#The lexicographically smallest subsequence among them is "eet".
#Example 2:
#Input: s = "leetcode", k = 4, letter = "e", repetition = 2
#Output: "ecde"
#Explanation: "ecde" is the lexicographically smallest subsequence of length 4 that has the letter "e" appear at least 2 times.
#Example 3:
#Input: s = "bb", k = 2, letter = "b", repetition = 2
#Output: "bb"
#Explanation: "bb" is the only subsequence of length 2 that has the letter "b" appear at least 2 times.
# 
#Constraints:
#	1 <= repetition <= k <= s.length <= 5 * 104
#	s consists of lowercase English letters.
#	letter is a lowercase English letter, and appears in s at least repetition times.
class Solution(object):
    def smallestSubsequence(self, s, k, letter, repetition):
        """
        :type s: str
        :type k: int
        :type letter: str
        :type repetition: int
        :rtype: str
        """
        # Initialize a dictionary to store the count of each letter in s
        letter_count = {}
        for c in s:
            letter_count[c] = letter_count.get(c, 0) + 1
        
        # Initialize a list to store the indices of letters in s
        indices = []
        for i, c in enumerate(s):
            if c == letter:
                indices.append(i)
        
        # Initialize a list to store the subsequences
        subsequences = []
        
        # Iterate through the indices in reverse order
        for i in range(len(indices) - 1, -1, -1):
            # Get the current index
            index = indices[i]
            
            # Check if the current subsequence has enough length
            if len(subsequences) < k:
                # Check if the current subsequence has the required letter repetition
                if letter_count[letter] >= repetition:
                    # Check if the current subsequence has the required letter at the required position
                    if index == 0 or s[index - 1] < letter:
                        # Add the current subsequence to the subsequences list
                        subsequences.append(s[index - k + 1:index + 1])
                        # Decrement the letter repetition
                        letter_count[letter] -= 1
        
        # Sort the subsequences lexicographically
        subsequences.sort()
        
        # Return the lexicographically smallest subsequence
        return subsequences[0] if subsequences else ""
        