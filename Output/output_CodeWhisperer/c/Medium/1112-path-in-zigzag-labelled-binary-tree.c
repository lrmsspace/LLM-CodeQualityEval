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
    int* result = (int*)malloc(sizeof(int) * 100);
    int i = 0;
    while (label > 0) {
        result[i++] = label;
        label /= 2;
        int level = 0;
        int temp = label;
        while (temp > 0) {
            temp /= 2;
            level++;
        }
        if (level % 2 == 0) {
            label = (1 << level) - 1 + (1 << level) - label;
        }
    }
    *returnSize = i;
    int* result2 = (int*)malloc(sizeof(int) * i);
    for (int j = 0; j < i; j++) {
        result2[j] = result[i - j - 1];
    }
    free(result);
    return result2;
}