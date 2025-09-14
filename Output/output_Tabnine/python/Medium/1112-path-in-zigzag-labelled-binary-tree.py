#https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
#In an infinite binary tree where every node has two children, the nodes are labelled in row order.
#In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.
#Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
# 
#Example 1:
#Input: label = 14
#Output: [1,3,4,14]
#Example 2:
#Input: label = 26
#Output: [1,2,6,10,26]
# 
#Constraints:
#	1 <= label <= 10^6
class Solution(object):
    def pathInZigZagTree(self, label):
        """
        :type label: int
        :rtype: List[int]
        """
        def find_parent(label):
            row = 1
            while label > (2 ** row) - 1:
                row += 1
            parent_label = label - (2 ** (row - 1))
            return parent_label
        
        def find_sibling(label):
            row = 1
            while label > (2 ** row) - 1:
                row += 1
            sibling_label = label + (2 ** (row - 1)) if row % 2 == 0 else label - (2 ** (row - 1))
            return sibling_label
        
        path = []
        while label > 1:
            path.append(label)
            label = find_sibling(label)
        
        path.append(1)
        path.reverse()
        
        return path 
        