#https://leetcode.com/problems/check-if-the-sentence-is-pangram/
#A pangram is a sentence where every letter of the English alphabet appears at least once.
#Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
# 
#Example 1:
#Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
#Output: true
#Explanation: sentence contains at least one of every letter of the English alphabet.
#Example 2:
#Input: sentence = "leetcode"
#Output: false
# 
#Constraints:
#	1 <= sentence.length <= 1000
#	sentence consists of lowercase English letters.
class Solution(object):
    def checkIfPangram(self, sentence):
        """
        :type sentence: str
        :rtype: bool
        """
        # Create a set of all lowercase English letters
        letters = set('abcdefghijklmnopqrstuvwxyz')
        
        # Convert the sentence to lowercase and remove non-alphabetic characters
        cleaned_sentence = ''.join(filter(str.isalpha, sentence.lower()))
        
        # Check if all letters in the set are present in the cleaned sentence
        return letters.issubset(cleaned_sentence)
        