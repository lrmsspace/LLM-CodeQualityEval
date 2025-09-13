# You are given a string caption representing the caption for a video.
# The following actions must be performed in order to generate a valid tag for the video:
# Combine all words in the string into a single camelCase string prefixed with '#'. A camelCase string is one where the first letter of all words except the first one is capitalized. All characters after the first character in each word must be lowercase.
# Remove all characters that are not an English letter, except the first '#'.
# Truncate the result to a maximum of 100 characters.
# Return the tag after performing the actions on caption.
# Example 1:
# Input: caption = "Leetcode daily streak achieved"
# Output: "#leetcodeDailyStreakAchieved"
# Explanation:
# The first letter for all words except "leetcode" should be capitalized.
# Example 2:
# Input: caption = "can I Go There"
# Output: "#canIGoThere"
# Explanation:
# The first letter for all words except "can" should be capitalized.
# Example 3:
# Input: caption = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
# Output: "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
# Explanation:
# Since the first word has length 101, we need to truncate the last two letters from the word.
# Constraints:
# 1 <= caption.length <= 150
# caption consists only of English letters and ' '.

class Solution(object):
    def generateTag(self, caption):
        """
        :type caption: str
        :rtype: str
        """
        # Split the caption into words
        words = caption.split()
        
        # Process each word: first letter lowercase, rest lowercase except non-letters
        processed_words = []
        for i, word in enumerate(words):
            # Remove non-letter characters from each word
            filtered_word = ''.join(c for c in word if c.isalpha())
            if not filtered_word:
                continue
            if i == 0:
                # First word is fully lowercase
                processed_words.append(filtered_word[0].lower() + filtered_word[1:].lower())
            else:
                # Other words: capitalize the first letter, rest lowercase
                processed_words.append(filtered_word[0].upper() + filtered_word[1:].lower())
        
        # Combine into a single string with camelCase and prefix '#'
        result = '#' + ''.join(processed_words)
        
        # Truncate to maximum 100 characters
        return result[:100]
