#https://leetcode.com/problems/reverse-nodes-in-even-length-groups/
#You are given the head of a linked list.
#The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,
#	The 1st node is assigned to the first group.
#	The 2nd and the 3rd nodes are assigned to the second group.
#	The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
#Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.
#Reverse the nodes in each group with an even length, and return the head of the modified linked list.
# 
#Example 1:
#Input: head = [5,2,6,3,9,1,7,3,8,4]
#Output: [5,6,2,3,9,1,4,8,3,7]
#Explanation:
#- The length of the first group is 1, which is odd, hence no reversal occurs.
#- The length of the second group is 2, which is even, hence the nodes are reversed.
#- The length of the third group is 3, which is odd, hence no reversal occurs.
#- The length of the last group is 4, which is even, hence the nodes are reversed.
#Example 2:
#Input: head = [1,1,0,6]
#Output: [1,0,1,6]
#Explanation:
#- The length of the first group is 1. No reversal occurs.
#- The length of the second group is 2. The nodes are reversed.
#- The length of the last group is 1. No reversal occurs.
#Example 3:
#Input: head = [1,1,0,6,5]
#Output: [1,0,1,5,6]
#Explanation:
#- The length of the first group is 1. No reversal occurs.
#- The length of the second group is 2. The nodes are reversed.
#- The length of the last group is 2. The nodes are reversed.
# 
#Constraints:
#	The number of nodes in the list is in the range [1, 105].
#	0 <= Node.val <= 105
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseEvenLengthGroups(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head:
            return None

        # Initialize variables
        group_size = 1
        current = head
        prev_tail = None
        prev_head = None

        while current:
            # Check if the group size is even
            if group_size % 2 == 0:
                # Reverse the group
                prev = None
                group_head = current
                for _ in range(group_size):
                    next_node = current.next
                    current.next = prev
                    prev = current
                    current = next_node

                # Connect the reversed group to the previous part of the list
                if prev_tail:
                    prev_tail.next = prev
                else:
                    head = prev    
                prev_head.next = prev
                prev_head = group_head
                prev_tail = group_head
            else:
                # Move the previous head pointer to the end of the current group
                prev_head = current
                prev_tail = current
                for _ in range(group_size):
                    if current:
                        prev_tail = current
                        current = current.next
            # Move to the next group
            # Increase the group size for the next iteration
            # group_size += 1
            group_size += 1
        # Connect the last part of the list if it was not reversed
        if prev_tail:
            prev_tail.next = current
        return head    