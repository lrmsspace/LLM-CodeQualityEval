#https://leetcode.com/problems/building-boxes/
#You have a cubic storeroom where the width, length, and height of the room are all equal to n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:
#	You can place the boxes anywhere on the floor.
#	If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
#Given an integer n, return the minimum possible number of boxes touching the floor.
# 
#Example 1:
#Input: n = 3
#Output: 3
#Explanation: The figure above is for the placement of the three boxes.
#These boxes are placed in the corner of the room, where the corner is on the left side.
#Example 2:
#Input: n = 4
#Output: 3
#Explanation: The figure above is for the placement of the four boxes.
#These boxes are placed in the corner of the room, where the corner is on the left side.
#Example 3:
#Input: n = 10
#Output: 6
#Explanation: The figure above is for the placement of the ten boxes.
#These boxes are placed in the corner of the room, where the corner is on the back side.
# 
#Constraints:
#	1 <= n <= 109
class Solution(object):
    def minimumBoxes(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Initialize the number of boxes as 0
        boxes = 0
        
        # Iterate from 1 to n
        for i in range(1, n+1):
            # For each number i, calculate the number of layers (l)
            # The number of layers is equal to the square root of i
            l = int(i**0.5)
            
            # Calculate the number of boxes in each layer
            # The number of boxes in each layer is equal to the square of the layer number
            # The number of boxes in the layer is also equal to the layer number minus 1
            layer_boxes = l * l * (l - 1)
            
            # Add the number of boxes in each layer to the total number of boxes
            boxes += layer_boxes
        
        # Return the minimum possible number of boxes touching the floor
        return boxes
        