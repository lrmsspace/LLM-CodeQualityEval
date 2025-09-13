#https://leetcode.com/problems/construct-string-with-repeat-limit/
#You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
#Return the lexicographically largest repeatLimitedString possible.
#A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.
# 
#Example 1:
#Input: s = "cczazcc", repeatLimit = 3
#Output: "zzcccac"
#Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
#The letter 'a' appears at most 1 time in a row.
#The letter 'c' appears at most 3 times in a row.
#The letter 'z' appears at most 2 times in a row.
#Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
#The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
#Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
#Example 2:
#Input: s = "aababab", repeatLimit = 2
#Output: "bbabaa"
#Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
#The letter 'a' appears at most 2 times in a row.
#The letter 'b' appears at most 2 times in a row.
#Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
#The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
#Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
# 
#Constraints:
#	1 <= repeatLimit <= s.length <= 105
#	s consists of lowercase English letters.
class Solution(object):
    def repeatLimitedString(self, s, repeatLimit):
        """
        :type s: str
        :type repeatLimit: int
        :rtype: str
        """
        from collections import Counter
        count = Counter(s)
        result = []
        prev_char = ''
        prev_count = 0
        
        while count:
            # Get the largest character available
            char = max(count.keys())
            
            # If the previous character is the same, we need to handle the repeat limit
            if char == prev_char:
                if len(count) == 1:        
                    break
                # Get the second largest character
                next_char = max(count.keys() - {char})
                result.append(next_char)
                count[next_char] -= 1
                if count[next_char] == 0:
                    del count[next_char]
                result.append(char)
                prev_count = 1
            else:
                # Add the current character to the result
                add_count = min(count[char], repeatLimit)
                result.append(char * add_count)
                count[char] -= add_count
                if count[char] == 0:
                    del count[char]
                prev_char = char
                prev_count = add_count

            # If the character count is exhausted, remove it from the count dictionary
            if count[char] == 0:
                del count[char]
            # If we have reached the repeat limit, we need to reset the previous character
            if prev_count == repeatLimit:
                prev_char = ''
                prev_count = 0

        return ''.join(result)