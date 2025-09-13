/**https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/ */
//Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// 
//Example 1:
//Input: head = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]
//Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
//Example 2:
//Input: head = []
//Output: []
// 
//Constraints:
//	The number of nodes in head is in the range [0, 2 * 104].
//	-105 <= Node.val <= 105
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    // Base case: if head is null or does not exist, return null
    if (head == NULL) {
        return NULL;
    }
    
    // Find the middle node of the linked list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    // Move fast pointer 2 steps ahead and slow pointer 1 step ahead
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // The slow pointer now points to the middle node
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = slow->val;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    
    return root;
    
}