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
        ones = count[ord('o') - ord('a')]
        ones -= count[ord('z') - ord('a')]
        ones -= count[ord('u') - ord('a')]
        ones -= count[ord('x') - ord('a')]
        ones -= count[ord('g') - ord('a')]
        ones //= 2
        fives = count[ord('f') - ord('a')]
        fives -= count[ord('u') - ord('a')]
        fives -= count[ord('v') - ord('a')]
        fives -= count[ord('w') - ord('a')]
        fives //= 5
        sevens = count[ord('s') - ord('a')]
        sevens -= count[ord('e') - ord('a')]
        sevens -= count[ord('v') - ord('a')]
        sevens -= count[ord('n') - ord('a')]
        sevens //= 7
        threes = count[ord('t') - ord('a')]
        threes -= count[ord('h') - ord('a')]
        threes -= count[ord('r') - ord('a')]
        threes -= count[ord('w') - ord('a')]
        threes -= count[ord('u') - ord('a')]
        threes -= count[ord('f') - ord('a')]
        threes //= 3
        twos = count[ord('w') - ord('a')]
        twos -= count[ord('o') - ord('a')]
        twos //= 2
        sixs = count[ord('x') - ord('a')]
        sixs -= count[ord('s') - ord('a')]
        sixs -= count[ord('e') - ord('a')]
        sixs -= count[ord('v') - ord('a')]
        sixs -= count[ord('n') - ord('a')]
        sixs //= 6
        fours = count[ord('f') - ord('a')]
        fours -= count[ord('o') - ord('a')]
        fours -= count[ord('u') - ord('a')]
        fours -= count[ord('r') - ord('a')]
        fours -= count[ord('v') - ord('a')]
        fours //= 4
        eights = count[ord('e') - ord('a')]
        eights -= count[ord('i') - ord('a')]
        eights -= count[ord('g') - ord('a')]
        eights -= count[ord('h') - ord('a')]
        eights -= count[ord('t') - ord('a')]
        eights -= count[ord('n') - ord('a')]
        eights //= 8
        return "".join(["0" * ones, "1" * ones, "2" * twos, "3" * threes, "4" * fours, "5" * ones, "6" * sixs, "7" * sevens, "8" * eights, "9" * fives])
