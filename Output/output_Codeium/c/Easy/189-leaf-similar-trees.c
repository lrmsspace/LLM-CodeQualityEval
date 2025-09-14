/**https://leetcode.com/problems/leaf-similar-trees/ */
//Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
//For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
//Two binary trees are considered leaf-similar if their leaf value sequence is the same.
//Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
// 
//Example 1:
//Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
//Output: true
//Example 2:
//Input: root1 = [1,2,3], root2 = [1,3,2]
//Output: false
// 
//Constraints:
//	The number of nodes in each tree will be in the range [1, 200].
//	Both of the given trees will have values in the range [0, 200].
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    //get leaf nodes
    struct TreeNode* leaf1[200];
    int leaf1Index = 0;
    struct TreeNode* leaf2[200];
    int leaf2Index = 0;
    
    void getLeaf(struct TreeNode* root, struct TreeNode** leaf, int* index) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            leaf[(*index)++] = root;
            return;
        }
        getLeaf(root->left, leaf, index);
        getLeaf(root->right, leaf, index);
    }
    
    getLeaf(root1, leaf1, &leaf1Index);
    getLeaf(root2, leaf2, &leaf2Index);
    
    if (leaf1Index != leaf2Index) return false;
    
    for (int i = 0; i < leaf1Index; i++) {
        if (leaf1[i]->val != leaf2[i]->val) return false;
    }
    
    return true;
}