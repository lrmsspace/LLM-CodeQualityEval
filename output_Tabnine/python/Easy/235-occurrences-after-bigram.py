#https://leetcode.com/problems/occurrences-after-bigram/
#Given two strings first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.
#Return an array of all the words third for each occurrence of "first second third".
# 
#Example 1:
#Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
#Output: ["girl","student"]
#Example 2:
#Input: text = "we will we will rock you", first = "we", second = "will"
#Output: ["we","rock"]
# 
#Constraints:
#	1 <= text.length <= 1000
#	text consists of lowercase English letters and spaces.
#	All the words in text are separated by a single space.
#	1 <= first.length, second.length <= 10
#	first and second consist of lowercase English letters.
#	text will not have any leading or trailing spaces.
class Solution(object):
    def findOcurrences(self, text, first, second):
        """
        :type text: str
        :type first: str
        :type second: str
        :rtype: List[str]
        """
        # Split the text into words
        words = text.split()
        
        # Initialize an empty list to store the occurrences
        occurrences = []
        
        # Iterate through the words list
        for i in range(len(words) - 2):
            # Check if the current word is equal to the first and the next two words are equal to the second
            if words[i] == first and words[i+1] == second and words[i+2] == second:
                # Append the third word to the occurrences list
                occurrences.append(words[i+2])
        
        return occurrences
        