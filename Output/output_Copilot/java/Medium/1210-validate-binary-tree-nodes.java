/**https://leetcode.com/problems/validate-binary-tree-nodes/ */
//You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
//If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
//Note that the nodes have no values and that we only use the node numbers in this problem.
// 
//Example 1:
//Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
//Output: true
//Example 2:
//Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
//Output: false
//Example 3:
//Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
//Output: false
// 
//Constraints:
//	n == leftChild.length == rightChild.length
//	1 <= n <= 104
//	-1 <= leftChild[i], rightChild[i] <= n - 1
class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] indegree = new int[n];
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
            }
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
            }
        }
        int rootCount = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                rootCount++;
            } else if (indegree[i] > 1) {
                return false;
            }
        }
        return rootCount == 1; // There should be exactly one root node  
    }
}