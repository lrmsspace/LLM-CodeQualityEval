/**https://leetcode.com/problems/split-linked-list-in-parts/ */
//Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
//The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
//The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
//Return an array of the k parts.
// 
//Example 1:
//Input: head = [1,2,3], k = 5
//Output: [[1],[2],[3],[],[]]
//Explanation:
//The first element output[0] has output[0].val = 1, output[0].next = null.
//The last element output[4] is null, but its string representation as a ListNode is [].
//Example 2:
//Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
//Output: [[1,2,3,4],[5,6,7],[8,9,10]]
//Explanation:
//The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 1000].
//	0 <= Node.val <= 1000
//	1 <= k <= 50
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
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    
    *returnSize = k;
    struct ListNode** res = (struct ListNode**)malloc(k * sizeof(struct ListNode*));
    int len = 0, i;
    struct ListNode* p = head;
    // get the length of the list
    while (p) {
        len++;
        p = p->next;
    }
    p = head;
    int base = len / k, extra = len % k;
    for (i = 0; i < k; i++) {
        int l = base + (i < extra ? 1 : 0);
        res[i] = p;
        if (l == 0) {
            res[i] = NULL;
            continue;
        }
        while (--l) {
            p = p->next;
        }
        struct ListNode* next = p->next;
        p->next = NULL;
        p = next;
    }
    return res;
}
