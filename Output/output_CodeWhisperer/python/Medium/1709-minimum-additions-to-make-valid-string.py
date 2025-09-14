#https://leetcode.com/problems/minimum-additions-to-make-valid-string/
#Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.
#A string is called valid if it can be formed by concatenating the string "abc" several times.
# 
#Example 1:
#Input: word = "b"
#Output: 2
#Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "b" to obtain the valid string "abc".
#Example 2:
#Input: word = "aaa"
#Output: 6
#Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".
#Example 3:
#Input: word = "abc"
#Output: 0
#Explanation: word is already valid. No modifications are needed. 
# 
#Constraints:
#	1 <= word.length <= 50
#	word consists of letters "a", "b" and "c" only. 
class Solution(object):
    def addMinimum(self, word):
        """
        :type word: str
        :rtype: int
        """
        count = 0
        i = 0
        while i < len(word):
            if word[i] == 'a':
                if i + 1 < len(word) and word[i + 1] == 'b':
                    if i + 2 < len(word) and word[i + 2] == 'c':
                        i += 3
                    else:
                        count += 1
                        i += 2
                elif i + 1 < len(word) and word[i + 1] == 'c':
                    count += 1
                    i += 2
                else:
                    count += 2
                    i += 1
            elif word[i] == 'b':
                count += 1
                if i + 1 < len(word) and word[i + 1] == 'c':
                    i += 2
                else:
                    count += 1
                    i += 1
            else:
                count += 2
                i += 1
        return count

        