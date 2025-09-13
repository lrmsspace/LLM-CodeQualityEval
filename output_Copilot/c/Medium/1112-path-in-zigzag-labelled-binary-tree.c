/**https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/ */
//In an infinite binary tree where every node has two children, the nodes are labelled in row order.
//In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.
//Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
// 
//Example 1:
//Input: label = 14
//Output: [1,3,4,14]
//Example 2:
//Input: label = 26
//Output: [1,2,6,10,26]
// 
//Constraints:
//	1 <= label <= 10^6
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathInZigZagTree(int label, int* returnSize) {
    int i = 0, j = 0, k = 0, n = 0, m = 0, *res = NULL;
    for (i = 0, n = 1; n < label; i++, n *= 2);
    res = (int*)malloc(sizeof(int) * (i + 1));
    for (j = 0, m = n / 2; i >= 0; i--, j++, m /= 2) {
        res[j] = label;
        label = m + (n - 1 - label / 2);
    }
    *returnSize = j;
    return res;    
}