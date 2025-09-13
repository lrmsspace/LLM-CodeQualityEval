#https://leetcode.com/problems/can-place-flowers/
#You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
#Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
# 
#Example 1:
#Input: flowerbed = [1,0,0,0,1], n = 1
#Output: true
#Example 2:
#Input: flowerbed = [1,0,0,0,1], n = 2
#Output: false
# 
#Constraints:
#	1 <= flowerbed.length <= 2 * 104
#	flowerbed[i] is 0 or 1.
#	There are no two adjacent flowers in flowerbed.
#	0 <= n <= flowerbed.length
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        # Initialize a counter for the number of available spaces
        count = 0
        
        # Iterate over the flowerbed, considering both the current and next positions
        for i in range(len(flowerbed)):
            # If the current position is 0 (empty), check if there are enough spaces to plant a flower
            if flowerbed[i] == 0:
                # If there are enough spaces to plant a flower (either current or next position is 0), increment the counter
                if i == 0 or flowerbed[i-1] == 0:
                    if i == len(flowerbed) - 1 or flowerbed[i+1] == 0:
                        count += 1
                        # If we've reached the required number of flowers, return True
                        if count == n:
                            return True
        # If we've checked all positions and haven't reached the required number of flowers, return False
        return count >= n
        