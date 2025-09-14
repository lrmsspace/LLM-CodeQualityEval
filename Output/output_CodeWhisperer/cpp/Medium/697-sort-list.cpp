/**https://leetcode.com/problems/sort-list/ */
//Given the head of a linked list, return the list after sorting it in ascending order.
// 
//Example 1:
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
//Example 2:
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
//Example 3:
//Input: head = []
//Output: []
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 5 * 104].
//	-105 <= Node.val <= 105
// 
//Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    ListNode* sortList(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        curr->next = left != nullptr ? left : right;

        return dummy->next;
    }
};