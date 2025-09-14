#https://leetcode.com/problems/stamping-the-sequence/
#You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.
#In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.
#	For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
#	
#		place stamp at index 0 of s to obtain "abc??",
#		place stamp at index 1 of s to obtain "?abc?", or
#		place stamp at index 2 of s to obtain "??abc".
#	
#	Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
#We want to convert s to target using at most 10 * target.length turns.
#Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.
# 
#Example 1:
#Input: stamp = "abc", target = "ababc"
#Output: [0,2]
#Explanation: Initially s = "?????".
#- Place stamp at index 0 to get "abc??".
#- Place stamp at index 2 to get "ababc".
#[1,0,2] would also be accepted as an answer, as well as some other answers.
#Example 2:
#Input: stamp = "abca", target = "aabcaca"
#Output: [3,0,1]
#Explanation: Initially s = "???????".
#- Place stamp at index 3 to get "???abca".
#- Place stamp at index 0 to get "abcabca".
#- Place stamp at index 1 to get "aabcaca".
# 
#Constraints:
#	1 <= stamp.length <= target.length <= 1000
#	stamp and target consist of lowercase English letters.
class Solution(object):
    def movesToStamp(self, stamp, target):
        """
        :type stamp: str
        :type target: str
        :rtype: List[int]
        """
        # Check if the target string can be obtained by stamping
        if target.count('?') > len(stamp) * 10:
            return []
        
        # Create a set of all possible stamps
        stamps = set(stamp)
        
        # Create a dictionary to map each character in target to its index
        char_to_index = {c: i for i, c in enumerate(target)}
        
        # Create a list to store the indices of characters being stamped at each turn
        indices = []
        
        # Create a copy of the target string
        s = list(target)
        
        # Iterate until the target string is equal to the original stamp
        while s!= stamp:
            # Find the index of the first '?' in the target string
            first_question_index = s.index('?')
            
            # Find the possible characters that can be stamped at the current index
            possible_chars = []
            for char in stamps:
                if s[first_question_index:first_question_index + len(char)] == char:
                    possible_chars.append(char)
            
            # If no possible characters are found, return an empty array
            if not possible_chars:
                return []
            
            # Choose the character that minimizes the number of swaps needed to make the target string equal to the stamp
            min_swaps = float('inf')
            best_char = None
            for char in possible_chars:
                num_swaps = sum(s[i]!= char for i in range(first_question_index, first_question_index + len(char)))
                if num_swaps < min_swaps:
                    min_swaps = num_swaps
                    best_char = char
            
            # Replace the '?' with the chosen character and update the indices list
            for i in range(first_question_index, first_question_index + len(best_char)):
                s[i] = best_char
            indices.append(char_to_index[best_char])
            # Update the set of stamps
            stamps.remove(best_char)
        
        return indices
        