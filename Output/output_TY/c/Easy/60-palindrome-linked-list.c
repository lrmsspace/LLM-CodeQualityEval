/**https://leetcode.com/problems/palindrome-linked-list/ */
//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// 
//Example 1:
//Input: head = [1,2,2,1]
//Output: true
//Example 2:
//Input: head = [1,2]
//Output: false
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 105].
//	0 <= Node.val <= 9
// 
//Follow up: Could you do it in O(n) time and O(1) space?
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head){
    int count = 0;
    struct ListNode *temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    int *arr = (int *)malloc(count*sizeof(int));
    temp = head;
    for(int i=0;i<count;i++){
        arr[i] = temp->val;
        temp = temp->next;
    }
    for(int i=0;i<count/2;i++){
        if(arr[i]!=arr[count-i-1]){
            return false;
        }
    }
}