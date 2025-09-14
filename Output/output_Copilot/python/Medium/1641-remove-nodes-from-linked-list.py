#https://leetcode.com/problems/remove-nodes-from-linked-list/
#You are given the head of a linked list.
#Remove every node which has a node with a greater value anywhere to the right side of it.
#Return the head of the modified linked list.
# 
#Example 1:
#Input: head = [5,2,13,3,8]
#Output: [13,8]
#Explanation: The nodes that should be removed are 5, 2 and 3.
#- Node 13 is to the right of node 5.
#- Node 13 is to the right of node 2.
#- Node 8 is to the right of node 3.
#Example 2:
#Input: head = [1,1,1,1]
#Output: [1,1,1,1]
#Explanation: Every node has value 1, so no nodes are removed.
# 
#Constraints:
#	The number of the nodes in the given list is in the range [1, 105].
#	1 <= Node.val <= 105
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Initialize a stack to keep track of the nodes
        stack = []
        # Initialize a pointer to the current node
        current = head
        
        # Traverse the linked list and add nodes to the stack
        while current:
            stack.append(current)
            current = current.next
        
        # Initialize a variable to keep track of the maximum value seen so far
        max_val = float('-inf')
        
        # Initialize a dummy node to build the new linked list
        dummy = ListNode(0)
        tail = dummy
        
        # Traverse the stack in reverse order (from last node to first node)
        while stack:
            node = stack.pop()
            # If the current node's value is greater than or equal to max_val, keep it
            if node.val >= max_val:
                tail.next = node
                tail = tail.next
                max_val = node.val
                # Set the next pointer of the current node to None to avoid cycles
                node.next = None
    
        # Return the head of the modified linked list
        return dummy.next   