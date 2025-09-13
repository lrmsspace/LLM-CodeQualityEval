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
struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head == NULL) return NULL;
    if(head->next == NULL) return (struct TreeNode*)malloc(sizeof(struct TreeNode) + sizeof(int) + sizeof(struct TreeNode*)*2);
    struct ListNode *fast = head, *slow = head, *pre = head;
    while(fast != NULL && fast->next != NULL){
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode) + sizeof(int) + sizeof(struct TreeNode*)*2);
    root->val = slow->val;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    return root;
}