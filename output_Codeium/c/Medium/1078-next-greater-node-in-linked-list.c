/**https://leetcode.com/problems/next-greater-node-in-linked-list/ */
//You are given the head of a linked list with n nodes.
//For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
//Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
// 
//Example 1:
//Input: head = [2,1,5]
//Output: [5,5,0]
//Example 2:
//Input: head = [2,7,4,3,5]
//Output: [7,0,5,5,0]
// 
//Constraints:
//	The number of nodes in the list is n.
//	1 <= n <= 104
//	1 <= Node.val <= 109
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int len = 0;
    struct ListNode* p = head;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    int* result = (int*)malloc(len * sizeof(int));
    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;
    p = head;
    for (int i = 0; i < len; i++) {
        while (top != -1 && stack[top] < p->val) {
            result[stack[top--]] = p->val;
        }
        stack[++top] = i;
        p = p->next;
    }
    while (top != -1) {
        result[stack[top--]] = 0;
    }
    *returnSize = len;
    return result;
}