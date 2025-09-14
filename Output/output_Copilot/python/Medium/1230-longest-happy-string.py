#https://leetcode.com/problems/longest-happy-string/
#A string s is called happy if it satisfies the following conditions:
#	s only contains the letters 'a', 'b', and 'c'.
#	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
#	s contains at most a occurrences of the letter 'a'.
#	s contains at most b occurrences of the letter 'b'.
#	s contains at most c occurrences of the letter 'c'.
#Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
#A substring is a contiguous sequence of characters within a string.
# 
#Example 1:
#Input: a = 1, b = 1, c = 7
#Output: "ccaccbcc"
#Explanation: "ccbccacc" would also be a correct answer.
#Example 2:
#Input: a = 7, b = 1, c = 0
#Output: "aabaa"
#Explanation: It is the only correct answer in this case.
# 
#Constraints:
#	0 <= a, b, c <= 100
#	a + b + c > 0
class Solution(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """
        # Initialize an empty string to store the result
        result = ''
        # Create a list of tuples containing the counts and corresponding characters
        char_counts = [(a, 'a'), (b, 'b'), (c, 'c')]
        
        # While there are still characters left to add
        while True:
            # Sort the list of tuples in descending order based on the counts
            char_counts.sort(reverse=True, key=lambda x: x[0])
            # Get the character with the highest count and its count
            count, char = char_counts[0]
            
            # If the highest count is zero, break the loop as we can't add more characters
            if count == 0:
                break
            
            # If the last two characters in the result are the same as the current character,
            # we need to check if we can use the second character in the sorted list
            if len(result) >= 2 and result[-1] == result[-2] == char:
                # Check if we can use the second character in the sorted list
                if char_counts[1][0] > 0:
                    # Use the second character and decrement its count
                    result += char_counts[1][1]
                    char_counts[1] = (char_counts[1][0] - 1, char_counts[1][1])
                else:
                    break    
            else:
                # Add the character to the result and decrement its count
                result += char
                char_counts[0] = (count - 1, char)

    