# You are given a string word, and an integer numFriends.
# Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
# word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
# All the split words are put into a box.
# Find the lexicographically largest string from the box after all the rounds are finished.
# Example 1:
# Input: word = "dbca", numFriends = 2
# Output: "dbc"
# Explanation: 
# All possible splits are:
# "d" and "bca".
# "db" and "ca".
# "dbc" and "a".
# Example 2:
# Input: word = "gggg", numFriends = 4
# Output: "g"
# Explanation: 
# The only possible split is: "g", "g", "g", and "g".
# Constraints:
# 1 <= word.length <= 5 * 103
# word consists only of lowercase English letters.
# 1 <= numFriends <= word.length

class Solution(object):
    def answerString(self, word, numFriends):
        """
        :type word: str
        :type numFriends: int
        :rtype: str
        """
        # Sort the characters in descending order
        word = sorted(word, reverse=True)
        
        # Initialize the result string
        result = ""
        
        # Iterate over the characters in descending order
        for i in range(len(word)):
            # Add the current character to the result string
            result += word[i]
            
            # If the number of characters in the result string is equal to or greater than numFriends,
            # return the result string
            if len(result) >= numFriends:
                return result
        
        # Return the result string if it is not empty
        return result if result else word       
        