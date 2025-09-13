#https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
#You are given the head of a linked list, and an integer k.
#Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
# 
#Example 1:
#Input: head = [1,2,3,4,5], k = 2
#Output: [1,4,3,2,5]
#Example 2:
#Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
#Output: [7,9,6,6,8,7,3,0,9,5]
# 
#Constraints:
#	The number of nodes in the list is n.
#	1 <= k <= n <= 105
#	0 <= Node.val <= 100
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapNodes(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        # 计算链表的长度
        length = 0
        current = head
        while current:
            length += 1
            current = current.next

        # 找到第 k 个节点和第 (length - k + 1) 个节点
        first_k_node = head
        second_k_node = head
        for _ in range(k - 1):
            first_k_node = first_k_node.next
        for _ in range(length - k):
            second_k_node = second_k_node.next

        # 交换值
        first_k_node.val, second_k_node.val = second_k_node.val, first_k_node.val

        return head        