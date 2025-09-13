#https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
#One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.
#For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.
#Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.
#It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.
#You may assume that the input format is always valid.
#	For example, it could never contain two consecutive commas, such as "1,,3".
#Note: You are not allowed to reconstruct the tree.
# 
#Example 1:
#Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
#Output: true
#Example 2:
#Input: preorder = "1,#"
#Output: false
#Example 3:
#Input: preorder = "9,#,#,1"
#Output: false
# 
#Constraints:
#	1 <= preorder.length <= 104
#	preorder consist of integers in the range [0, 100] and '#' separated by commas ','.
class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        # Split the preorder string into a list of nodes
        nodes = preorder.split(',')
        
        # Initialize a stack with a dummy node
        stack = [1]
        
        for node in nodes:
            # If the current node is not '#', push it to the stack
            if node != '#':
                stack.append(1)
            # If the current node is '#', decrement the top of the stack
            else:
                while stack and stack[-1] == 1:
                    stack.pop()
                if not stack:
                    return False
                stack[-1] -= 1
        
        # If the stack is empty, it means the preorder is valid
        return not stack
        