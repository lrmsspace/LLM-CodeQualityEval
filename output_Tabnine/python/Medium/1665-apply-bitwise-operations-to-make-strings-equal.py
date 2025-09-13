#https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/
#You are given two 0-indexed binary strings s and target of the same length n. You can do the following operation on s any number of times:
#	Choose two different indices i and j where 0 <= i, j < n.
#	Simultaneously, replace s[i] with (s[i] OR s[j]) and s[j] with (s[i] XOR s[j]).
#For example, if s = "0110", you can choose i = 0 and j = 2, then simultaneously replace s[0] with (s[0] OR s[2] = 0 OR 1 = 1), and s[2] with (s[0] XOR s[2] = 0 XOR 1 = 1), so we will have s = "1110".
#Return true if you can make the string s equal to target, or false otherwise.
# 
#Example 1:
#Input: s = "1010", target = "0110"
#Output: true
#Explanation: We can do the following operations:
#- Choose i = 2 and j = 0. We have now s = "0010".
#- Choose i = 2 and j = 1. We have now s = "0110".
#Since we can make s equal to target, we return true.
#Example 2:
#Input: s = "11", target = "00"
#Output: false
#Explanation: It is not possible to make s equal to target with any number of operations.
# 
#Constraints:
#	n == s.length == target.length
#	2 <= n <= 105
#	s and target consist of only the digits 0 and 1.
class Solution(object):
    def makeStringsEqual(self, s, target):
        """
        :type s: str
        :type target: str
        :rtype: bool
        """
        # Count the frequency of each digit in s and target
        freq_s = [0] * 2
        freq_target = [0] * 2
        
        for i in range(len(s)):
            freq_s[int(s[i])] += 1
            freq_target[int(target[i])] += 1
        
        # If the frequencies are not equal, it's impossible to make s equal to target
        if freq_s!= freq_target:
            return False
        
        # Count the number of positions where s[i]!= target[i]
        diff_count = 0
        for i in range(len(s)):
            if s[i]!= target[i]:
                diff_count += 1
        
        # If there are more than half positions where s[i]!= target[i], it's impossible to make s equal to target
        return diff_count <= len(s) // 2
        