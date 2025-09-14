#https://leetcode.com/problems/find-common-characters/
#Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
# 
#Example 1:
#Input: words = ["bella","label","roller"]
#Output: ["e","l","l"]
#Example 2:
#Input: words = ["cool","lock","cook"]
#Output: ["c","o"]
# 
#Constraints:
#	1 <= words.length <= 100
#	1 <= words[i].length <= 100
#	words[i] consists of lowercase English letters.
class Solution(object):
    def commonChars(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        # Initialize an empty dictionary to store the count of each character
        char_count = {}
        
        # Iterate through each word in the list
        for word in words:
            # Iterate through each character in the word
            for char in word:
                # If the character is already in the dictionary, increment its count
                if char in char_count:
                    char_count[char] += 1
                # If the character is not in the dictionary, add it with a count of 1
                else:
                    char_count[char] = 1
        
        # Initialize an empty list to store the common characters
        common_chars = []
        
        # Iterate through each character in the dictionary
        for char, count in char_count.items():
            # If the count is equal to the number of words, add the character to the list
            if count == len(words):
                common_chars.append(char)
        
        # Return the list of common characters
        return common_chars
        