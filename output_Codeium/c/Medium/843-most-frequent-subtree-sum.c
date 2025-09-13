/**https://leetcode.com/problems/most-frequent-subtree-sum/ */
//Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
//The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
// 
//Example 1:
//Input: root = [5,2,-3]
//Output: [2,-3,4]
//Example 2:
//Input: root = [5,2,-5]
//Output: [2]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
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
int calculateSubtreeSums(struct TreeNode* node, int* freqMap) {
        if (!node) return 0;
        
        int leftSum = calculateSubtreeSums(node->left, freqMap);
        int rightSum = calculateSubtreeSums(node->right, freqMap);
        int subtreeSum = node->val + leftSum + rightSum;
        
        // Increment frequency of the current subtree sum
        freqMap[mapIndex++] = subtreeSum;
        return subtreeSum;
    }
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    int* freqMap = (int*)malloc(1000 * sizeof(int)); // Frequency map for subtree sums
    int* result = (int*)malloc(1000 * sizeof(int)); // Result array to store most frequent sums
    int maxFreq = 0, mapIndex = 0;
    int resultIndex = 0;
    
    // Helper function to calculate subtree sums
    
    
    // Calculate subtree sums and populate frequency map
    calculateSubtreeSums(root, freqMap);
    
    // Find the maximum frequency
    for (int i = 0; i < mapIndex; i++) {
        int count = 0;
        for (int j = 0; j < mapIndex; j++) {
            if (freqMap[i] == freqMap[j]) count++;
        }
        if (count > maxFreq) {
            maxFreq = count;
        }
    }
    
    // Collect all sums with maximum frequency
    for (int i = 0; i < mapIndex; i++) {
        int count = 0;
        for (int j = 0; j < mapIndex; j++) {
            if (freqMap[i] == freqMap[j]) count++;
        }
        if (count == maxFreq) {
            result[resultIndex++] = freqMap[i];
        }
    }
    
    *returnSize = resultIndex;
    free(freqMap);
    return result;
}
    
