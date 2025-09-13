#https://leetcode.com/problems/construct-the-longest-new-string/
#You are given three integers x, y, and z.
#You have x strings equal to "AA", y strings equal to "BB", and z strings equal to "AB". You want to choose some (possibly all or none) of these strings and concatenate them in some order to form a new string. This new string must not contain "AAA" or "BBB" as a substring.
#Return the maximum possible length of the new string.
#A substring is a contiguous non-empty sequence of characters within a string.
# 
#Example 1:
#Input: x = 2, y = 5, z = 1
#Output: 12
#Explanation: We can concactenate the strings "BB", "AA", "BB", "AA", "BB", and "AB" in that order. Then, our new string is "BBAABBAABBAB". 
#That string has length 12, and we can show that it is impossible to construct a string of longer length.
#Example 2:
#Input: x = 3, y = 2, z = 2
#Output: 14
#Explanation: We can concactenate the strings "AB", "AB", "AA", "BB", "AA", "BB", and "AA" in that order. Then, our new string is "ABABAABBAABBAA". 
#That string has length 14, and we can show that it is impossible to construct a string of longer length.
# 
#Constraints:
#	1 <= x, y, z <= 50
class Solution(object):
    def longestString(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: int
        """
        if x > y:
            x, y = y, x
        if x == 0:
            return 2 * y if y < 3 else 2 * (y - 1) + 1
        if y == 0:
            return 2 * x if x < 3 else 2 * (x - 1) + 1
        if z == 0:
            return min(x, y) * 4 + (x + y) % 2
        return min(x, y) * 4 + (x + y) % 2 + min(z, abs(x - y)) * 2 + (z - min(z, abs(x - y)))        