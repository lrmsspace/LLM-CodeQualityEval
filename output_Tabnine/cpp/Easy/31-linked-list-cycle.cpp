/**https://leetcode.com/problems/linked-list-cycle/ */
//Given head, the head of a linked list, determine if the linked list has a cycle in it.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//Return true if there is a cycle in the linked list. Otherwise, return false.
// 
//Example 1:
//Input: head = [3,2,0,-4], pos = 1
//Output: true
//Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
//Example 2:
//Input: head = [1,2], pos = 0
//Output: true
//Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
//Example 3:
//Input: head = [1], pos = -1
//Output: false
//Explanation: There is no cycle in the linked list.
// 
//Constraints:
//	The number of the nodes in the list is in the range [0, 104].
//	-105 <= Node.val <= 105
//	pos is -1 or a valid index in the linked-list.
// 
//Follow up: Can you solve it using O(1) (i.e. constant) memory?
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (slow!= fast) {
            if (fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;  // Cycle found!  head to fast is the cycle's starting point.  Let's find the length of the cycle.
        
        // Now, find the length of the cycle.
        int cycleLength = 1;
        slow = fast->next;
        while (slow!= fast) {
            slow = slow->next;
            cycleLength++;
        }
        
        // Now, find the meeting point.
        slow = head;
        fast = head;
        for (int i = 0; i < cycleLength; i++) {
            fast = fast->next;
        }
        
        while (slow!= fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow == fast;  // Meeting point is the cycle's starting point.  Now, let's find the cycle's length.
        
    }
};