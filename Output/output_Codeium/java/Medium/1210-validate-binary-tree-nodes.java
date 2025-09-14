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
    boolean[] visited = new boolean[n];
    int[] inDegree = new int[n];
    for (int i = 0; i < n; i++) {
        if (leftChild[i] != -1) inDegree[leftChild[i]]++;
        if (rightChild[i] != -1) inDegree[rightChild[i]]++;
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            if (root != -1) return false; // More than one root found
            root = i;
        } else if (inDegree[i] > 1) {
            return false; // Node with more than one parent
        }
    }

    if (root == -1) return false; // No root found

    Queue<Integer> queue = new LinkedList<>();
    queue.offer(root);
    while (!queue.isEmpty()) {
        int node = queue.poll();
        if (visited[node]) return false; // Cycle detected
        visited[node] = true;
        if (leftChild[node] != -1) queue.offer(leftChild[node]);
        if (rightChild[node] != -1) queue.offer(rightChild[node]);
    }

    for (boolean v : visited) {
        if (!v) return false; // Disconnected node found
    }

    return true;    
    }
}