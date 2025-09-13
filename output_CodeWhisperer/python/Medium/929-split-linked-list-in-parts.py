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
        if not head:
            return [None] * k
        length = 0
        curr = head
        while curr:
            length += 1
            curr = curr.next
        part_size = length // k
        remainder = length % k
        result = []
        curr = head
        for i in range(k):
            result.append(curr)
            part_length = part_size + (1 if i < remainder else 0)
            for j in range(part_length - 1):
                if curr:
                    curr = curr.next
            if curr:
                next_node = curr.next
                curr.next = None
                curr = next_node
        return result
        