#https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
#You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.
#Your goal is to satisfy one of the following three conditions:
#	Every letter in a is strictly less than every letter in b in the alphabet.
#	Every letter in b is strictly less than every letter in a in the alphabet.
#	Both a and b consist of only one distinct letter.
#Return the minimum number of operations needed to achieve your goal.
# 
#Example 1:
#Input: a = "aba", b = "caa"
#Output: 2
#Explanation: Consider the best way to make each condition true:
#1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
#2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
#3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
#The best way was done in 2 operations (either condition 1 or condition 3).
#Example 2:
#Input: a = "dabadd", b = "cda"
#Output: 3
#Explanation: The best way is to make condition 1 true by changing b to "eee".
# 
#Constraints:
#	1 <= a.length, b.length <= 105
#	a and b consist only of lowercase letters.
class Solution(object):
    def minCharacters(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        count_a = [0] * 26
        count_b = [0] * 26
        
        for char in a:
            count_a[ord(char) - ord('a')] += 1
            
        for char in b:
            count_b[ord(char) - ord('a')] += 1
        
        min_operations = float('inf')
        
        # Case 1: Make all characters in a less than all characters in b
        for i in range(25):
            operations = sum(count_a[i + 1:]) + sum(count_b[:i + 1])
            min_operations = min(min_operations, operations)
        
        # Case 2: Make all characters in b less than all characters in a
        for i in range(25):
            operations = sum(count_b[i + 1:]) + sum(count_a[:i + 1])
            min_operations = min(min_operations, operations)
        
        # Case 3: Make both strings consist of one distinct letter
        max_count_a = max(count_a)
        max_count_b = max(count_b)
        
        operations_to_make_same_char = len(a) - max_count_a + len(b) - max_count_b
        
        return min(min_operations, operations_to_make_same_char)        