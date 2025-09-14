#https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/
#You are given a string s consisting only of lowercase English letters.
#In one move, you can select any two adjacent characters of s and swap them.
#Return the minimum number of moves needed to make s a palindrome.
#Note that the input will be generated such that s can always be converted to a palindrome.
# 
#Example 1:
#Input: s = "aabb"
#Output: 2
#Explanation:
#We can obtain two palindromes from s, "abba" and "baab". 
#- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
#- We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
#Thus, the minimum number of moves needed to make s a palindrome is 2.
#Example 2:
#Input: s = "letelt"
#Output: 2
#Explanation:
#One of the palindromes we can obtain from s in 2 moves is "lettel".
#One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
#Other palindromes such as "tleelt" can also be obtained in 2 moves.
#It can be shown that it is not possible to obtain a palindrome in less than 2 moves.
# 
#Constraints:
#	1 <= s.length <= 2000
#	s consists only of lowercase English letters.
#	s can be converted to a palindrome using a finite number of moves.
class Solution(object):
    def minMovesToMakePalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Count the frequency of each character in the string
        freq = [0] * 26
        
        for c in s:
            freq[ord(c) - ord('a')] += 1
        
        # Initialize the minimum number of moves
        moves = 0
        
        # Count the number of characters with odd frequency
        odd_count = sum(1 for f in freq if f % 2 == 1)
        
        # If the string is already a palindrome, return 0
        if odd_count == 0:
            return 0
        
        # For each character with odd frequency, we can make it even by swapping with its adjacent character
        # This reduces the odd count by 1 and adds 1 to the total number of moves
        for i in range(26):
            if freq[i] % 2 == 1:
                moves += freq[i] // 2
        
        return moves
        