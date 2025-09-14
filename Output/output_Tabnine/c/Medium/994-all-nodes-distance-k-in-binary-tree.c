/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.
// 
//Example 1:
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//Example 2:
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 500].
//	0 <= Node.val <= 500
//	All the values Node.val are unique.
//	target is the value of one of the nodes in the tree.
//	0 <= k <= 1000
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
    int* res = malloc(sizeof(int) * k);
    *returnSize = 0;
    
    if (!root ||!target) return res;
    
    int* dist = malloc(sizeof(int) * 500);
    memset(dist, -1, sizeof(int) * 500);
    
    dfs(root, target, 0, dist);
    
    queue* q = queue_create();
    queue_enqueue(q, target->val);
    dist[target->val] = 0;
    
    while (queue_size(q) > 0) {
        int u = queue_dequeue(q);
        
        if (dist[u] == k) {
            res[*returnSize] = u;
            (*returnSize)++;
        }
        
        if (dist[u] > k) break;
        
        if (root->left && dist[root->left->val] == dist[u] - 1) {
            queue_enqueue(q, root->left->val);
        }
        
        if (root->right && dist[root->right->val] == dist[u] - 1) {
            queue_enqueue(q, root->right->val);
        }
        
        if (root->left && root->left->left && dist[root->left->left->val] == dist[u] - 2) {
            queue_enqueue(q, root->left->left->val);
        }
        
        if (root->left && root->left->right && dist[root->left->right->val] == dist[u] - 2) {
            queue_enqueue(q, root->left->right->val);
        }
        
        if (root->right && root->right->left && dist[root->right->left->val] == dist[u] - 2) {
            queue_enqueue(q, root->right->left->val);
        }
        
        if (root->right && root->right->right && dist[root->right->right->val] == dist[u] - 2) {
            queue_enqueue(q, root->right->right->val);
        }


    }
    
    queue_destroy(q);
    free(dist);
    
    return res;
    
}