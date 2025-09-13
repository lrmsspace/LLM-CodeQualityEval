#https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
#You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.
#Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).
#Return the number of pairs of interchangeable rectangles in rectangles.
# 
#Example 1:
#Input: rectangles = [[4,8],[3,6],[10,20],[15,30]]
#Output: 6
#Explanation: The following are the interchangeable pairs of rectangles by index (0-indexed):
#- Rectangle 0 with rectangle 1: 4/8 == 3/6.
#- Rectangle 0 with rectangle 2: 4/8 == 10/20.
#- Rectangle 0 with rectangle 3: 4/8 == 15/30.
#- Rectangle 1 with rectangle 2: 3/6 == 10/20.
#- Rectangle 1 with rectangle 3: 3/6 == 15/30.
#- Rectangle 2 with rectangle 3: 10/20 == 15/30.
#Example 2:
#Input: rectangles = [[4,5],[7,8]]
#Output: 0
#Explanation: There are no interchangeable pairs of rectangles.
# 
#Constraints:
#	n == rectangles.length
#	1 <= n <= 105
#	rectangles[i].length == 2
#	1 <= widthi, heighti <= 105
class Solution(object):
    def interchangeableRectangles(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        # Create a dictionary to store the ratio of width to height for each rectangle
        ratio_dict = {}
        
        # Iterate through each rectangle
        for i in range(len(rectangles)):
            width, height = rectangles[i]
            
            # Calculate the ratio and add it to the dictionary
            ratio = width / height
            ratio_dict[ratio] = ratio_dict.get(ratio, 0) + 1
        
        # Calculate the number of interchangeable pairs by counting the number of occurrences of each ratio
        interchangeable_pairs = 0
        for count in ratio_dict.values():
            interchangeable_pairs += count * (count - 1) // 2
        
        return interchangeable_pairs
        