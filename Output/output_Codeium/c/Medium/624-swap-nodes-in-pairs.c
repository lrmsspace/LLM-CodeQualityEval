/**https://leetcode.com/problems/swap-nodes-in-pairs/ */
//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
// 
//Example 1:
//Input: head = [1,2,3,4]
//Output: [2,1,4,3]
//Explanation:
//Example 2:
//Input: head = []
//Output: []
//Example 3:
//Input: head = [1]
//Output: [1]
//Example 4:
//Input: head = [1,2,3]
//Output: [2,1,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 100].
//	0 <= Node.val <= 100
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
if (!head || !head->next) return head;

struct ListNode *new_head = head->next;
struct ListNode *prev = NULL;

while (head && head->next) {
    struct ListNode *next_pair = head->next->next;
    struct ListNode *second = head->next;

    // Swap the nodes
    second->next = head;
    head->next = next_pair;
    if (prev) {
        prev->next = second;
    }

    // Move to the next pair
    prev = head;
    head = next_pair;
}

return new_head;

}