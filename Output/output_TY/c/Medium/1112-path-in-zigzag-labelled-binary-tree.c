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
int* pathInZigZagTree(int label, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*100);
    int i = 0;
    while(label){
        ans[i++] = label;
        label /= 2;
    }
    for(int j = 0; j < i/2; j++){
        int temp = ans[j];
        ans[j] = ans[i-j-1];
        ans[i-j-1]= temp;
    }
    *returnSize = i;
    return ans;
}