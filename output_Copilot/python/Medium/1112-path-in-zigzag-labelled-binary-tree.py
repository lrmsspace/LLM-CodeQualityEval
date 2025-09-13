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
        if label == 1:
            return [1]
        # 计算label所在的层数
        level = 0
        while (1 << level) <= label:
            level += 1
        level -= 1

        # 计算label在当前层的索引
        index = label - (1 << level)

        # 计算当前层的节点数
        num_nodes = 1 << level

        # 如果当前层是偶数层，则需要进行反转
        if level % 2 == 0:
            index = num_nodes - index - 1

        path = []
        while level >= 0:
            path.append(label)
            # 更新label为父节点的值
            label //= 2
            # 更新level和index
            level -= 1
            if level >= 0:
                num_nodes = 1 << level
                if level % 2 == 0:
                    index = num_nodes - label + (1 << (level + 1)) - 1 - index - 1

        return path[::-1]        