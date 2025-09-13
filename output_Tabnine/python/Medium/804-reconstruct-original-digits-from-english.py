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
        count = [0] * 26
        for char in s:
            count[ord(char) - ord('a')] += 1
        
        result = ""
        for i in range(ord('z') - ord('a') + 1):
            if count[i] > 0:
                if i == ord('e') - ord('a'):
                    result += '0' * count[i]
                    count[ord('z') - ord('a')] -= count[i]
                    count[ord('n') - ord('a')] -= count[i]
                    count[ord('o') - ord('a')] -= count[i]
                elif i == ord('f') - ord('a'):
                    result += '1' * count[i]
                    count[ord('i') - ord('a')] -= count[i]
                    count[ord('v') - ord('a')] -= count[i]
                elif i == ord('i') - ord('a'):
                    result += '2' * count[i]
                    count[ord('s') - ord('a')] -= count[i]
                    count[ord('e') - ord('a')] -= count[i]
                    count[ord('v') - ord('a')] -= count[i]
                elif i == ord('o') - ord('a'):
                    result += '4' * count[i]
                    count[ord('t') - ord('a')] -= count[i]
                    count[ord('w') - ord('a')] -= count[i]
                    count[ord('o') - ord('a')] -= count[i]
                elif i == ord('s') - ord('a'):
                    result += '5' * count[i]
                    count[ord('s') - ord('a')] -= count[i]
                    count[ord('e') - ord('a')] -= count[i] * 2
                    count[ord('v') - ord('a')] -= count[i]
                    count[ord('n') - ord('a')] -= count[i]
                elif i == ord('t') - ord('a'):
                    result += '6' * count[i]
                    count[ord('s') - ord('a')] -= count[i]
                    count[ord('e') - ord('a')] -= count[i] * 2
                    count[ord('n') - ord('a')] -= count[i] * 2
                elif i == ord('u') - ord('a'):
                    result += '8' * count[i]
                    count[ord('e') - ord('a')] -= count[i] * 2
                    count[ord('v') - ord('a')] -= count[i]
                    count[ord('n') - ord('a')] -= count[i] * 2
                elif i == ord('v') - ord('a'):
                    result += '7' * count[i]
                    count[ord('s') - ord('a')] -= count[i]
                    count[ord('e') - ord('a')] -= count[i] * 2
                    count[ord('n') - ord('a')] -= count[i] * 3
                elif i == ord('w') - ord('a'):
                    result += '9' * count[i]
                    count[ord('t') - ord('a')] -= count[i] * 2
                    count[ord('e') - ord('a')] -= count[i] * 3
                    count[ord('n') - ord('a')] -= count[i] * 3
                elif i == ord('x') - ord('a'):
                    result += '3' * count[i]
                    count[ord('t') - ord('a')] -= count[i]
                    count[ord('h') - ord('a')] -= count[i]
                    count[ord('e') - ord('a')] -= count[i] * 3
                    count[ord('n') - ord('a')] -= count[i] * 3
                elif i == ord('z') - ord('a'):
                    result += '2' * count[i]
                    count[ord('t') - ord('a')] -= count[i]
                    count[ord('h') - ord('a')] -= count[i]
                    count[ord('e') - ord('a')] -= count[i] * 2
                    count[ord('n') - ord('a')] -= count[i] * 4
        return result

        