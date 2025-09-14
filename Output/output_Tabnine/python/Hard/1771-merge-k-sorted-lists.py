#https://leetcode.com/problems/merge-k-sorted-lists/
#You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
#Merge all the linked-lists into one sorted linked-list and return it.
# 
#Example 1:
#Input: lists = [[1,4,5],[1,3,4],[2,6]]
#Output: [1,1,2,3,4,4,5,6]
#Explanation: The linked-lists are:
#[
#  1->4->5,
#  1->3->4,
#  2->6
#]
#merging them into one sorted list:
#1->1->2->3->4->4->5->6
#Example 2:
#Input: lists = []
#Output: []
#Example 3:
#Input: lists = [[]]
#Output: []
# 
#Constraints:
#	k == lists.length
#	0 <= k <= 104
#	0 <= lists[i].length <= 500
#	-104 <= lists[i][j] <= 104
#	lists[i] is sorted in ascending order.
#	The sum of lists[i].length will not exceed 104.
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[Optional[ListNode]]
        :rtype: Optional[ListNode]
        """
        # Base case: if the list is empty, return None
        if not lists:
            return None
        
        # Find the minimum head of the list
        min_head = lists[0]
        min_index = 0
        for i in range(1, len(lists)):
            if lists[i] and lists[i].val < min_head.val:
                min_head = lists[i]
                min_index = i
        
        # Remove the minimum head from the list
        lists[min_index] = lists[min_index].next
        
        # Recursively merge the remaining lists
        merged_list = self.mergeKLists(lists)
        
        # Append the minimum head to the merged list
        min_head.next = merged_list
        
        return min_head
        