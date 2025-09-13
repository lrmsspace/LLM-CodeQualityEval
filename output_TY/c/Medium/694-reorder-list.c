/**https://leetcode.com/problems/reorder-list/ */
//You are given the head of a singly linked-list. The list can be represented as:
//L0 → L1 → … → Ln - 1 → Ln
//Reorder the list to be on the following form:
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//You may not modify the values in the list's nodes. Only nodes themselves may be changed.
// 
//Example 1:
//Input: head = [1,2,3,4]
//Output: [1,4,2,3]
//Example 2:
//Input: head = [1,2,3,4,5]
//Output: [1,5,2,4,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 5 * 104].
//	1 <= Node.val <= 1000
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head){
    if(head==NULL || head->next==NULL || head->next->next==NULL) return;
    struct ListNode* slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode* temp=slow->next;
    slow->next=NULL;
    struct ListNode* prev=NULL;
    while(temp!=NULL){
        struct ListNode* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    struct ListNode* p1=head,*p2=prev;
    while(p2!=NULL){
        struct ListNode* next1=p1->next;
        struct ListNode* next2=p2->next;
        p1->next=p2;
        p2->next=next1;
        p1=next1;
        p2=next2;
    }
    return;
}