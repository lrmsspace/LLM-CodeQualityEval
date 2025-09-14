/**https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ */
//You are given the head of a linked list, and an integer k.
//Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
// 
//Example 1:
//Input: head = [1,2,3,4,5], k = 2
//Output: [1,4,3,2,5]
//Example 2:
//Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
//Output: [7,9,6,6,8,7,3,0,9,5]
// 
//Constraints:
//	The number of nodes in the list is n.
//	1 <= k <= n <= 105
//	0 <= Node.val <= 100
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* temp2 = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        int pos = count - k + 1;
        for(int i = 1; i < pos; i++){
            temp2 = temp2->next;
        }
        ListNode* temp3 = head;
        for(int i = 1; i < k; i++){
            temp3 = temp3->next;
        }
        swap(temp3->val, temp2->val);
        return head;
    }
};