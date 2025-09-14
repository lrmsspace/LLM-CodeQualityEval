#https://leetcode.com/problems/split-linked-list-in-parts/
#Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
#The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
#The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
#Return an array of the k parts.
# 
#Example 1:
#Input: head = [1,2,3], k = 5
#Output: [[1],[2],[3],[],[]]
#Explanation:
#The first element output[0] has output[0].val = 1, output[0].next = null.
#The last element output[4] is null, but its string representation as a ListNode is [].
#Example 2:
#Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
#Output: [[1,2,3,4],[5,6,7],[8,9,10]]
#Explanation:
#The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
# 
#Constraints:
#	The number of nodes in the list is in the range [0, 1000].
#	0 <= Node.val <= 1000
#	1 <= k <= 50
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def splitListToParts(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: List[Optional[ListNode]]
        """
        # Count the total number of nodes in the linked list
        count = 0
        curr = head
        while curr:
            count += 1
            curr = curr.next
        
        # Calculate the size of each part and the remaining nodes
        part_size = count // k
        remaining_nodes = count % k
        
        # Create the result array
        result = [None] * k
        
        # Initialize pointers for the current part and the remaining nodes
        curr = head
        prev = None
        
        # Iterate through the linked list and split it into k parts 
        for i in range(k):
            # Calculate the number of nodes in the current part
            part_count = part_size + (remaining_nodes > 0)
            remaining_nodes -= 1
            
            # Create a new linked list for the current part
            part_head = ListNode(0)
            part_tail = part_head
            
            # Iterate through the current part and update the pointers
            for _ in range(part_count):
                part_tail.next = ListNode(curr.val)
                part_tail = part_tail.next
                curr = curr.next
            
            # Update the previous pointer to the last node of the current part
            if prev:
                prev.next = part_head.next
            prev = part_tail
        
        return result