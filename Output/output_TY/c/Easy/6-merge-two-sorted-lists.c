/**https://leetcode.com/problems/merge-two-sorted-lists/ */
//You are given the heads of two sorted linked lists list1 and list2.
//Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
//Return the head of the merged linked list.
// 
//Example 1:
//Input: list1 = [1,2,4], list2 = [1,3,4]
//Output: [1,1,2,3,4,4]
//Example 2:
//Input: list1 = [], list2 = []
//Output: []
//Example 3:
//Input: list1 = [], list2 = [0]
//Output: [0]
// 
//Constraints:
//	The number of nodes in both lists is in the range [0, 50].
//	-100 <= Node.val <= 100
//	Both list1 and list2 are sorted in non-decreasing order.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
     // 处理空链表的情况
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    // 创建一个虚拟头节点，方便处理合并后的链表
    struct ListNode dummy;
    struct ListNode *current = &dummy;

    // 遍历两个链表，比较节点值并合并
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // 将剩余的节点添加到合并后的链表中
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // 返回合并后链表的头节点
    return dummy.next;
}