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
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        result = []
        i = 25
        while i >= 0:
            if count[i] == 0:
                i -= 1
                continue
            j = min(repeatLimit, count[i])
            result.extend([chr(ord('a') + i)] * j)
            count[i] -= j
            if count[i] == 0:
                i -= 1
                continue
            k = i - 1
            while k >= 0 and count[k] == 0:
                k -= 1
            if k < 0:
                break
            result.append(chr(ord('a') + k))
            count[k] -= 1
        return ''.join(result)
        