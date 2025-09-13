# You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.
# Example 1:
# Input: nums = [1,2,3], head = [1,2,3,4,5]
# Output: [4,5]
# Explanation:
# Remove the nodes with values 1, 2, and 3.
# Example 2:
# Input: nums = [1], head = [1,2,1,2,1,2]
# Output: [2,2,2]
# Explanation:
# Remove the nodes with value 1.
# Example 3:
# Input: nums = [5], head = [1,2,3,4]
# Output: [1,2,3,4]
# Explanation:
# No node has value 5.
# Constraints:
# 1 <= nums.length <= 105
# 1 <= nums[i] <= 105
# All elements in nums are unique.
# The number of nodes in the given list is in the range [1, 105].
# 1 <= Node.val <= 105
# The input is generated such that there is at least one node in the linked list that has a value not present in nums.

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Create a set from nums for efficient lookup
        nums_set = set(nums)
        
        # Initialize pointers
        current = head
        prev = None
        
        # Traverse the linked list
        while current:
            # If the current node's value is in nums_set, remove it
            if current.val in nums_set:
                if prev:
                    prev.next = current.next
                else:
                    head = current.next
                current = current.next
            else:
                prev = current
                current = current.next
        
        return head        