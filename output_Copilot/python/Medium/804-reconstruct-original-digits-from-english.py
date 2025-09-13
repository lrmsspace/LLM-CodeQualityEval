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
        for c in s:
            count[ord(c) - ord('a')] += 1
        # print(count)
        ans = [0] * 10
        ans[0] = count[ord('z') - ord('a')]
        ans[2] = count[ord('w') - ord('a')]
        ans[4] = count[ord('u') - ord('a')]
        ans[6] = count[ord('x') - ord('a')]
        ans[8] = count[ord('g') - ord('a')]

        ans[3] = count[ord('h') - ord('a')] - ans[8]
        ans[5] = count[ord('f') - ord('a')] - ans[4]
        ans[7] = count[ord('s') - ord('a')] - ans[6]
        ans[1] = count[ord('o') - ord('a')] - ans[0] - ans[2] - ans[4]
        ans[9] = count[ord('i') - ord('a')] - ans[5] - ans[6] - ans[8]

        result = ''
        for i in range(10):
            result += str(i) * ans[i]
        return result        