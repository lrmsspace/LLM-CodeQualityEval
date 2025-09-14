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
        res = []
        count = collections.Counter(s)
        res.append(count['z'])
        res.append(count['w'])
        res.append(count['u'])
        res.append(count['x'])
        res.append(count['g'])
        res.append(count['o'] - count['z'] - count['w'] - count['u'])
        res.append(count['h'] - count['x'] - count['u'] - count['g'])
        res.append(count['f'] - count['u'])
        res.append(count['s'] - count['x'] - count['u'] - count['g'] - count['h'])
        res.append(count['i'] - count['x'] - count['u'] - count['g'] - count['h'] - count['f'] - count['s'])
        res.append(count['n'] - count['i'] - count['s'] - count['h'] - count['f'] - count['g'])
        res.append(count['v'] - count['f'] - count['s'] - count['i'] - count['h'] - count['n'])
        res.append(count['t'] - count['n'] - count['v'] - count['i'] - count['h'] - count['f'] - count['s'])
        return ''.join(str(x) for x in res)
