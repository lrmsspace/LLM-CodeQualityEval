#https://leetcode.com/problems/most-common-word/
#Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
#The words in paragraph are case-insensitive and the answer should be returned in lowercase.
# 
#Example 1:
#Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
#Output: "ball"
#Explanation: 
#"hit" occurs 3 times, but it is a banned word.
#"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
#Note that words in the paragraph are not case sensitive,
#that punctuation is ignored (even if adjacent to words, such as "ball,"), 
#and that "hit" isn't the answer even though it occurs more because it is banned.
#Example 2:
#Input: paragraph = "a.", banned = []
#Output: "a"
# 
#Constraints:
#	1 <= paragraph.length <= 1000
#	paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
#	0 <= banned.length <= 100
#	1 <= banned[i].length <= 10
#	banned[i] consists of only lowercase English letters.
class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        # Remove punctuation and convert to lowercase
        paragraph = ''.join(c.lower() if c.isalpha() or c =='' else'' for c in paragraph)
        
        # Split the paragraph into words
        words = paragraph.split()
        
        # Create a dictionary to count the frequency of each word
        word_count = {}
        
        # Iterate through the words
        for word in words:
            # Check if the word is not banned
            if word not in banned:
                # Increment the count for the word
                word_count[word] = word_count.get(word, 0) + 1
        
        # Find the most frequent non-banned word
        max_count = 0
        most_common_word = ''
        
        for word, count in word_count.items():
            if count > max_count:
                max_count = count
                most_common_word = word
        
        return most_common_word
        