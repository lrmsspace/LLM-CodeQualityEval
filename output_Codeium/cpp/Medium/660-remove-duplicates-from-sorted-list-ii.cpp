/**https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ */
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
// 
//Example 1:
//Input: head = [1,2,3,3,4,4,5]
//Output: [1,2,5]
//Example 2:
//Input: head = [1,1,1,2,3]
//Output: [2,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 300].
//	-100 <= Node.val <= 100
//	The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur) {
            if (cur->next && cur->val == cur->next->val) {
                int val = cur->val;
                while (cur && cur->val == val) {
                    cur = cur->next;
                }
                pre->next = cur;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};