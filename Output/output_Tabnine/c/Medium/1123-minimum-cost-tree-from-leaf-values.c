/**https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/ */
//Given an array arr of positive integers, consider all binary trees such that:
//	Each node has either 0 or 2 children;
//	The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
//	The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
//Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
//A node is a leaf if and only if it has zero children.
// 
//Example 1:
//Input: arr = [6,2,4]
//Output: 32
//Explanation: There are two possible trees shown.
//The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
//Example 2:
//Input: arr = [4,11]
//Output: 44
// 
//Constraints:
//	2 <= arr.length <= 40
//	1 <= arr[i] <= 15
//	It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
int mctFromLeafValues(int* arr, int arrSize) {
    int n = arrSize;
    int* left = (int*)malloc(n * sizeof(int));
    int* right = (int*)malloc(n * sizeof(int));
    int* dp = (int*)malloc(n * sizeof(int));
    int* prev = (int*)malloc(n * sizeof(int));
    int* next = (int*)malloc(n * sizeof(int));
    
    memset(left, -1, n * sizeof(int));
    memset(right, -1, n * sizeof(int));
    memset(dp, 0, n * sizeof(int));
    memset(prev, -1, n * sizeof(int));
    memset(next, -1, n * sizeof(int));
    
    // Initialize dp array
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i] * arr[i];
    }
    
    // Build the left and right arrays
    for (int i = 0; i < n; i++) {
        int maxLeft = INT_MIN;
        int maxRight = INT_MIN;
        
        for (int j = 0; j < i; j++) {
            if (arr[j] > maxLeft) {
                maxLeft = arr[j];
                left[i] = j;
            }
        }
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > maxRight) {
                maxRight = arr[j];
                right[i] = j;
            }
        }
    }
    
    // Build the prev and next arrays
    for (int i = 0; i < n; i++) {
        if (left[i]!= -1) {
            prev[left[i]] = i;
        }
        
        if (right[i]!= -1) {
            next[right[i]] = i;
        }
    }
    
    // Build the minimum cost tree
    for (int i = 1; i < n; i++) {
        int minCost = INT_MAX;
        int minCostIndex = -1;
        
        for (int j = 0; j < i; j++) {
            int cost = dp[j] + dp[i] + arr[j] * arr[i];
            
            if (cost < minCost) {
                minCost = cost;
                minCostIndex = j;
            }
        }
        
        dp[i] = minCost;
        prev[i] = minCostIndex;
        next[minCostIndex] = i;
    }
    
    int result = dp[n - 1];
    free(left);
    free(right);
    free(dp);
    free(prev);
    free(next);
    
    return result;
    
}