# There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:
# colors[i] == 0 means that tile i is red.
# colors[i] == 1 means that tile i is blue.
# An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).
# Return the number of alternating groups.
# Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.
# Example 1:
# Input: colors = [0,1,0,1,0], k = 3
# Output: 3
# Explanation:
# Alternating groups:
# Example 2:
# Input: colors = [0,1,0,0,1,0,1], k = 6
# Output: 2
# Explanation:
# Alternating groups:
# Example 3:
# Input: colors = [1,1,0,1], k = 4
# Output: 0
# Explanation:
# Constraints:
# 3 <= colors.length <= 105
# 0 <= colors[i] <= 1
# 3 <= k <= colors.length

class Solution(object):
    def numberOfAlternatingGroups(self, colors, k):
        """
        :type colors: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize count of alternating groups
        count = 0
        
        # Iterate over the given array
        for i in range(len(colors)):
            # Check if the current tile is red
            if colors[i] == 0:
                # Check if the left and right tiles have different colors
                if i > 0 and colors[i-1] == 1 or i < len(colors)-1 and colors[i+1] == 1:
                    # Check if the current group is of size k
                    if i+k <= len(colors) and colors[i:i+k] == [0]*k:
                        count += 1
        
        return count
        