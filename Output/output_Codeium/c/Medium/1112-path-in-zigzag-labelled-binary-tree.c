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
    int row = 0, col = 0, level = 0;
    int* res = (int*)malloc(20 * sizeof(int));
    *returnSize = 0;
    while (label > 0) {
        res[(*returnSize)++] = label;
        level = row + 1;
        col = (label - 1) / level;
        label /= 2;
        row = (1 - (level & 1)) * col + label;
    }
    res[(*returnSize)++] = 1;
    return res;
}