/**https://leetcode.com/problems/rotate-list/ */
//Given the head of a linked list, rotate the list to the right by k places.
// 
//Example 1:
//Input: head = [1,2,3,4,5], k = 2
//Output: [4,5,1,2,3]
//Example 2:
//Input: head = [0,1,2], k = 4
//Output: [2,0,1]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 500].
//	-100 <= Node.val <= 100
//	0 <= k <= 2 * 109
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head==NULL||head->next==NULL||k==0) return head;
    int n=1;
    struct ListNode* p=head;
    while(p->next!=NULL){
        n++;
        p=p->next;
    }
    p->next=head;
    k=k%n;
    int m=n-k;
    while(m--){
        p=p->next;
    }
    head=p->next;
    p->next=NULL;
    return head;
}