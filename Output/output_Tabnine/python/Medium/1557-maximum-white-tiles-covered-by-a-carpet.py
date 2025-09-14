#https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/
#You are given a 2D integer array tiles where tiles[i] = [li, ri] represents that every tile j in the range li <= j <= ri is colored white.
#You are also given an integer carpetLen, the length of a single carpet that can be placed anywhere.
#Return the maximum number of white tiles that can be covered by the carpet.
# 
#Example 1:
#Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
#Output: 9
#Explanation: Place the carpet starting on tile 10. 
#It covers 9 white tiles, so we return 9.
#Note that there may be other places where the carpet covers 9 white tiles.
#It can be shown that the carpet cannot cover more than 9 white tiles.
#Example 2:
#Input: tiles = [[10,11],[1,1]], carpetLen = 2
#Output: 2
#Explanation: Place the carpet starting on tile 10. 
#It covers 2 white tiles, so we return 2.
# 
#Constraints:
#	1 <= tiles.length <= 5 * 104
#	tiles[i].length == 2
#	1 <= li <= ri <= 109
#	1 <= carpetLen <= 109
#	The tiles are non-overlapping.
class Solution(object):
    def maximumWhiteTiles(self, tiles, carpetLen):
        """
        :type tiles: List[List[int]]
        :type carpetLen: int
        :rtype: int
        """
        # Sort the tiles based on their rightmost end
        tiles.sort(key=lambda x: x[1])
        
        # Initialize the maximum number of white tiles covered by the carpet
        maxWhiteTiles = 0
        
        # Initialize the current leftmost end of the carpet
        left = tiles[0][0]
        
        # Iterate through the tiles
        for i in range(len(tiles)):
            # If the current tile's leftmost end is within the carpet's range, extend the carpet
            if left <= tiles[i][0]:
                left = tiles[i][0]
            # If the current tile's rightmost end is beyond the carpet's range, break the loop
            elif tiles[i][1] > left + carpetLen - 1:
                break
            # Update the maximum number of white tiles covered by the carpet
            maxWhiteTiles = max(maxWhiteTiles, (tiles[i][1] - left) // carpetLen)
        
        return maxWhiteTiles
        