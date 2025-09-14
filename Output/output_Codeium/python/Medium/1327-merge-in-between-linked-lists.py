#https://leetcode.com/problems/merge-in-between-linked-lists/
#You are given two linked lists: list1 and list2 of sizes n and m respectively.
#Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
#The blue edges and nodes in the following figure indicate the result:
#Build the result list and return its head.
# 
#Example 1:
#Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
#Output: [10,1,13,1000000,1000001,1000002,5]
#Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
#Example 2:
#Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
#Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
#Explanation: The blue edges and nodes in the above figure indicate the result.
# 
#Constraints:
#	3 <= list1.length <= 104
#	1 <= a <= b < list1.length - 1
#	1 <= list2.length <= 104
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        """
        :type list1: ListNode
        :type a: int
        :type b: int
        :type list2: ListNode
        :rtype: ListNode
        """
        # Find the node just before the ath node
        prev_a = list1
        for _ in range(a - 1):
            prev_a = prev_a.next

        # Find the bth node
        node_b = prev_a.next
        for _ in range(b - a + 1):
            node_b = node_b.next

        # Connect the end of list2 to node_b
        end_list2 = list2
        while end_list2.next:
            end_list2 = end_list2.next
        end_list2.next = node_b

        # Connect prev_a to the start of list2
        prev_a.next = list2

        return list1

