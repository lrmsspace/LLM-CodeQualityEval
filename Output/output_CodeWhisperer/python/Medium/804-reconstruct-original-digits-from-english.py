#https://leetcode.com/problems/reconstruct-original-digits-from-english/
#Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
# 
#Example 1:
#Input: s = "owoztneoer"
#Output: "012"
#Example 2:
#Input: s = "fviefuro"
#Output: "45"
# 
#Constraints:
#	1 <= s.length <= 105
#	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
#	s is guaranteed to be valid.
class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        count = [0] * 10
        for c in s:
            if c == 'z': count[0] += 1
            if c == 'w': count[2] += 1
            if c == 'u': count[4] += 1
            if c == 'x': count[6] += 1
            if c == 'g': count[8] += 1
            if c == 'o': count[1] += 1
            if c == 'h': count[3] += 1
            if c == 'f': count[5] += 1
            if c == 's': count[7] += 1
            if c == 'i': count[9] += 1
        count[1] -= count[0] + count[2] + count[4]
        count[3] -= count[8]
        count[5] -= count[4]
        count[7] -= count[6]
        count[9] -= count[5] + count[6] + count[8]
        return ''.join(str(i) * count[i] for i in range(10))
        