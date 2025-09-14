/**https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/ */
//You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
//The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
//Find the kth largest value (1-indexed) of all the coordinates of matrix.
// 
//Example 1:
//Input: matrix = [[5,2],[1,6]], k = 1
//Output: 7
//Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.
//Example 2:
//Input: matrix = [[5,2],[1,6]], k = 2
//Output: 5
//Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.
//Example 3:
//Input: matrix = [[5,2],[1,6]], k = 3
//Output: 4
//Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 1000
//	0 <= matrix[i][j] <= 106
//	1 <= k <= m * n 
int kthLargestValue(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Create a 2D array to store XOR values for each coordinate
    vector<vector<int>> xorMatrix(m, vector<int>(n, 0));
    
    // Vector to store all XOR values for finding kth largest
    vector<int> allValues;
    
    // Calculate XOR values for each coordinate
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Calculate XOR based on previous values
            if (i == 0 && j == 0) {
                xorMatrix[i][j] = matrix[i][j];
            } else if (i == 0) {
                xorMatrix[i][j] = xorMatrix[i][j-1] ^ matrix[i][j];
            } else if (j == 0) {
                xorMatrix[i][j] = xorMatrix[i-1][j] ^ matrix[i][j];
            } else {
                // XOR(i,j) = XOR(i-1,j) ^ XOR(i,j-1) ^ XOR(i-1,j-1) ^ matrix[i][j]
                // This is because elements in the overlapping region get XORed twice
                xorMatrix[i][j] = xorMatrix[i-1][j] ^ xorMatrix[i][j-1] ^ xorMatrix[i-1][j-1] ^ matrix[i][j];
            }
            
            // Add the XOR value to our collection
            allValues.push_back(xorMatrix[i][j]);
        }
    }
    
    // Use nth_element to find the kth largest value
    // Note: nth_element is more efficient than sorting the entire array
    nth_element(allValues.begin(), allValues.begin() + k - 1, allValues.end(), greater<int>());
    
    // Return the kth largest value
    return allValues[k - 1];
}
