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
    // Base case: if there's no list to merge, return NULL
    if (listsSize == 0) {
        return NULL;
    }
    
    // If there's only one list, return it
    if (listsSize == 1) {
        return lists[0];
    }
    
    // Divide the lists into two halves
    int mid = listsSize / 2;
    struct ListNode** left = malloc(mid * sizeof(struct ListNode*));
    struct ListNode** right = malloc((listsSize - mid) * sizeof(struct ListNode*));
    
    // Copy the left half of the lists into left
    for (int i = 0; i < mid; i++) {
        left[i] = lists[i];
    }
    
    // Copy the right half of the lists into right
    for (int i = mid; i < listsSize; i++) {
        right[i - mid] = lists[i];
    }
    
    // Recursively merge the left and right halves
    struct ListNode* mergedLeft = mergeKLists(left, mid);
    struct ListNode* mergedRight = mergeKLists(right, listsSize - mid);
    
    // Merge the two sorted halves
    return mergeTwoLists(mergedLeft, mergedRight);
    
}