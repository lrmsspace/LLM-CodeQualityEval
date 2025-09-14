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
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head, *pre = NULL, *l1 = head, *l2, *tmp;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        pre = NULL;
        while (slow) {
            tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        l2 = pre;
        while (l1 && l2) {
            tmp = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = tmp;
        }        
    }
};