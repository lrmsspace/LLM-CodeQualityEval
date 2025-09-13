#https://leetcode.com/problems/linked-list-components/
#You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.
#Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.
# 
#Example 1:
#Input: head = [0,1,2,3], nums = [0,1,3]
#Output: 2
#Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
#Example 2:
#Input: head = [0,1,2,3,4], nums = [0,3,1,4]
#Output: 2
#Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
# 
#Constraints:
#	The number of nodes in the linked list is n.
#	1 <= n <= 104
#	0 <= Node.val < n
#	All the values Node.val are unique.
#	1 <= nums.length <= n
#	0 <= nums[i] < n
#	All the values of nums are unique.
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def numComponents(self, head, nums):
        """
        :type head: Optional[ListNode]
        :type nums: List[int]
        :rtype: int
        """
        # Convert nums to a set for O(1) lookups
        num_set = set(nums)
        count = 0
        in_component = False
        
        # Traverse the linked list
        while head:
            # Check if the current node's value is in nums
            if head.val in num_set:
                # If we are not already in a component, we found a new one
                if not in_component:
                    count += 1
                    in_component = True
            else:
                # If the current node's value is not in nums, we are no longer in a component
                in_component = False
            
            head = head.next
        
        return count        