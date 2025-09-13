/**https://leetcode.com/problems/reorder-list/ */
//You are given the head of a singly linked-list. The list can be represented as:
//L0 → L1 → … → Ln - 1 → Ln
//Reorder the list to be on the following form:
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//You may not modify the values in the list's nodes. Only nodes themselves may be changed.
// 
//Example 1:
//Input: head = [1,2,3,4]
//Output: [1,4,2,3]
//Example 2:
//Input: head = [1,2,3,4,5]
//Output: [1,5,2,4,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 5 * 104].
//	1 <= Node.val <= 1000
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head ||!head->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find the middle of the list
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Merge the two halves
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p1 = dummy;
        ListNode* p2 = prev;
        while (p1 && p2) {
            ListNode* next1 = p1->next;
            ListNode* next2 = p2->next;
            p1->next = p2;
            p2->next = next1;
            p1 = next1;
            p2 = next2;
        }
        
        // Delete the original list and replace it with the merged list
        delete head;
        head = dummy->next;
        delete dummy;
        
        // Return the reordered list
        return head;
        
    }
};