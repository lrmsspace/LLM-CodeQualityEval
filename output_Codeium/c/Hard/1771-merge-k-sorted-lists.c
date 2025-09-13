/**https://leetcode.com/problems/merge-k-sorted-lists/ */
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.
// 
//Example 1:
//Input: lists = [[1,4,5],[1,3,4],[2,6]]
//Output: [1,1,2,3,4,4,5,6]
//Explanation: The linked-lists are:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//merging them into one sorted list:
//1->1->2->3->4->4->5->6
//Example 2:
//Input: lists = []
//Output: []
//Example 3:
//Input: lists = [[]]
//Output: []
// 
//Constraints:
//	k == lists.length
//	0 <= k <= 104
//	0 <= lists[i].length <= 500
//	-104 <= lists[i][j] <= 104
//	lists[i] is sorted in ascending order.
//	The sum of lists[i].length will not exceed 104.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode dummy;
    struct ListNode* cur = &dummy;
    int i, j, k, min;
    int val[listsSize];
    int flag[listsSize] = {1};

    while (1) {
        min = INT_MAX;
        k = -1;
        for (i = 0; i < listsSize; i++) {
            if (flag[i] && lists[i] && lists[i]->val < min) {
                min = lists[i]->val;
                k = i;
            }
        }
        if (k == -1) break;
        cur->next = lists[k];
        cur = cur->next;
        lists[k] = lists[k]->next;
        flag[k] = 0;
    }

    return dummy.next;
}