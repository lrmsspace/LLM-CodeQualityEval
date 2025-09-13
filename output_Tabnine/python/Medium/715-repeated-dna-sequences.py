#https://leetcode.com/problems/repeated-dna-sequences/
#The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
#	For example, "ACGAATTCCG" is a DNA sequence.
#When studying DNA, it is useful to identify repeated sequences within the DNA.
#Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
# 
#Example 1:
#Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
#Output: ["AAAAACCCCC","CCCCCAAAAA"]
#Example 2:
#Input: s = "AAAAAAAAAAAAA"
#Output: ["AAAAAAAAAA"]
# 
#Constraints:
#	1 <= s.length <= 105
#	s[i] is either 'A', 'C', 'G', or 'T'.
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # Create a dictionary to store the count of each 10-letter sequence
        count = {}
        
        # Iterate over the string from start to end with a window size of 10
        for i in range(len(s) - 9):
            # Get the current 10-letter sequence
            subsequence = s[i:i+10]
            
            # If the sequence is already in the dictionary, add it to the result list
            if subsequence in count:
                count[subsequence] += 1
            else:
                # If the sequence is not in the dictionary, add it with a count of 1
                count[subsequence] = 1
        
        # Create a list to store the repeated sequences
        result = []
        
        # Iterate over the count dictionary and add the sequences with a count greater than 1 to the result list
        for sequence, count in count.items():
            if count > 1:
                result.append(sequence)
        
        # Return the list of repeated sequences
        return result
        