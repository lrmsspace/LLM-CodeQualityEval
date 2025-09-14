#https://leetcode.com/problems/letter-tile-possibilities/
#You have n  tiles, where each tile has one letter tiles[i] printed on it.
#Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
# 
#Example 1:
#Input: tiles = "AAB"
#Output: 8
#Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
#Example 2:
#Input: tiles = "AAABBC"
#Output: 188
#Example 3:
#Input: tiles = "V"
#Output: 1
# 
#Constraints:
#	1 <= tiles.length <= 7
#	tiles consists of uppercase English letters.
class Solution(object):
    def numTilePossibilities(self, tiles):
        """
        :type tiles: str
        :rtype: int
        """
        count = [0] * 26
        for t in tiles:
            count[ord(t) - ord('A')] += 1
        def dfs():
            sum = 0
            for i in xrange(26):
                if count[i] == 0: continue
                sum += 1
                count[i] -= 1
                sum += dfs()
                count[i] += 1
            return sum
        return dfs()

        