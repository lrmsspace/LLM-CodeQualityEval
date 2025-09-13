/**https://leetcode.com/problems/find-duplicate-subtrees/ */
//Given the root of a binary tree, return all duplicate subtrees.
//For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//Two trees are duplicate if they have the same structure with the same node values.
// 
//Example 1:
//Input: root = [1,2,3,4,null,2,4,null,null,4]
//Output: [[2,4],[4]]
//Example 2:
//Input: root = [2,1,1]
//Output: [[1]]
//Example 3:
//Input: root = [2,2,2,3,null,3,null]
//Output: [[2,3],[3]]
// 
//Constraints:
//	The number of the nodes in the tree will be in the range [1, 5000]
//	-200 <= Node.val <= 200
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

void traverse(struct TreeNode* root, map<string, vector<struct TreeNode*>>& m) {
    if (!root) {
        return;
    }
    string s = to_string(root->val);
    if (root->left) {
        s += "L" + to_string(root->left->val);
    }
    if (root->right) {
        s += "R" + to_string(root->right->val);
    }
    m[s].push_back(root);
    traverse(root->left, m);
    traverse(root->right, m);
}
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    map<string, vector<struct TreeNode*>> m;
    traverse(root, m);
    struct TreeNode** result = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * m.size());
    int i = 0;
    for (auto& it : m) {
        if (it.second.size() > 1) {
            result[i++] = it.second[0];
        }
    }
    *returnSize = i;
    return result;
}