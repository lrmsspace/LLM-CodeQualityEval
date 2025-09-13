#https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
#You are given a string text. You can swap two of the characters in the text.
#Return the length of the longest substring with repeated characters.
# 
#Example 1:
#Input: text = "ababa"
#Output: 3
#Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
#Example 2:
#Input: text = "aaabaaa"
#Output: 6
#Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
#Example 3:
#Input: text = "aaaaa"
#Output: 5
#Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
# 
#Constraints:
#	1 <= text.length <= 2 * 104
#	text consist of lowercase English characters only.
class Solution(object):
    def maxRepOpt1(self, text):
        """
        :type text: str
        :rtype: int
        """
        # Initialize variables
        max_length = 0
        current_length = 1
        char_count = {}
        
        # Iterate through the text
        for i in range(1, len(text)):
            # If the current character is the same as the previous character
            if text[i] == text[i-1]:
                # If the current character is already in the dictionary, increment its count
                if text[i] in char_count:
                    char_count[text[i]] += 1
                # Otherwise, add the current character to the dictionary with count 1
                else:
                    char_count[text[i]] = 1
                # Update the current length
                current_length += 1
            # If the current character is different from the previous character
            else:
                # If the current character is in the dictionary and its count is greater than 1
                if text[i] in char_count and char_count[text[i]] > 1:
                    # Swap the current character with the previous character
                    text = text[:i-1] + text[i] + text[i-1] + text[i+1:]
                    # Update the dictionary
                    char_count[text[i-1]] -= 1
                    char_count[text[i]] += 1
                    # Update the current length
                    current_length = 2
                else:
                    # Reset the current length
                    current_length = 1
                # Reset the dictionary
                char_count = {}
        # Return the maximum length
        return max(max_length, current_length)
        