/**https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/ */
//You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
//Each minute, a node becomes infected if:
//	The node is currently uninfected.
//	The node is adjacent to an infected node.
//Return the number of minutes needed for the entire tree to be infected.
// 
//Example 1:
//Input: root = [1,5,3,null,4,10,6,9,2], start = 3
//Output: 4
//Explanation: The following nodes are infected during:
//- Minute 0: Node 3
//- Minute 1: Nodes 1, 10 and 6
//- Minute 2: Node 5
//- Minute 3: Node 4
//- Minute 4: Nodes 9 and 2
//It takes 4 minutes for the whole tree to be infected so we return 4.
//Example 2:
//Input: root = [1], start = 1
//Output: 0
//Explanation: At minute 0, the only node in the tree is infected so we return 0.
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 105].
//	1 <= Node.val <= 105
//	Each node has a unique value.
//	A node with a value of start exists in the tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* node, int start) {
    if (!node) return 0;
    int res = 0;
    if (node->val != start) res++;
    res += dfs(node->left, start);
    res += dfs(node->right, start);
    return res;
}

int amountOfTime(struct TreeNode* root, int start) {
    if (!root) return 0;    
    int res = 0;
    struct TreeNode* st = root;
    while (st->val != start) {
        if (st->left && st->left->val == start) st = st->left;
        else if (st->right && st->right->val == start) st = st->right;
        else {
            if (st->val < start) st = st->right;
            else st = st->left;
        }
        res++;
    }
    int left = dfs(st->left, start);
    int right = dfs(st->right, start);
    return res + max(left, right);
}
