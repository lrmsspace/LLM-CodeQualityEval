#https://leetcode.com/problems/remove-letter-to-equalize-frequency/
#You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.
#Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.
#Note:
#	The frequency of a letter x is the number of times it occurs in the string.
#	You must remove exactly one letter and cannot choose to do nothing.
# 
#Example 1:
#Input: word = "abcc"
#Output: true
#Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
#Example 2:
#Input: word = "aazz"
#Output: false
#Explanation: We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.
# 
#Constraints:
#	2 <= word.length <= 100
#	word consists of lowercase English letters only.
class Solution(object):
    def equalFrequency(self, word):
        """
        :type word: str
        :rtype: bool
        """
        from collections import Counter

        # Count the frequency of each character in the word
        freq = Counter(word)

        # Get the frequency counts of the characters
        freq_counts = Counter(freq.values())

        # If there's only one unique frequency, we can remove one character to equalize
        if len(freq_counts) == 1:
            return True

        # If there are two unique frequencies, we can check if we can equalize them
        if len(freq_counts) == 2:
            freq1, count1 = freq_counts.most_common(1)[0]
            freq2, count2 = freq_counts.most_common(2)[1]

            # Check if we can remove one character to equalize frequencies
            if (freq1 == 1 and count1 == 1) or (freq2 == freq1 + 1 and count2 == 1):
                return True

        return False        