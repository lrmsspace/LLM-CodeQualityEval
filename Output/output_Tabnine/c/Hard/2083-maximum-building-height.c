/**https://leetcode.com/problems/maximum-building-height/ */
//You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
//However, there are city restrictions on the heights of the new buildings:
//	The height of each building must be a non-negative integer.
//	The height of the first building must be 0.
//	The height difference between any two adjacent buildings cannot exceed 1.
//Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
//It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
//Return the maximum possible height of the tallest building.
// 
//Example 1:
//Input: n = 5, restrictions = [[2,1],[4,1]]
//Output: 2
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
//Example 2:
//Input: n = 6, restrictions = []
//Output: 5
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
//Example 3:
//Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
//Output: 5
//Explanation: The green area in the image indicates the maximum allowed height for each building.
//We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
// 
//Constraints:
//	2 <= n <= 109
//	0 <= restrictions.length <= min(n - 1, 105)
//	2 <= idi <= n
//	idi is unique.
//	0 <= maxHeighti <= 109
int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize) {
    int* dp = (int*)calloc(n, sizeof(int));
    int* maxHeight = (int*)calloc(n, sizeof(int));
    
    // Initialize the first building as 0
    dp[0] = maxHeight[0] = 0;
    
    // Iterate through the restrictions
    for (int i = 0; i < restrictionsSize; i++) {
        int id = restrictions[i][0] - 1;
        int maxH = restrictions[i][1];
        
        // Update the maximum height for the building if needed
        maxHeight[id] = max(maxHeight[id], maxH);
    }
    
    // Build the dp array using a greedy approach
    for (int i = 1; i < n; i++) {
        dp[i] = maxHeight[i];
        
        // Find the maximum height of the previous buildings that can be built without violating the height difference constraint
        for (int j = 0; j < i; j++) {
            if (maxHeight[j] <= maxHeight[i] - 1) {
                dp[i] = max(dp[i], dp[j] + maxHeight[i]);
            }
        }
    }
    
    // Return the maximum height of the tallest building
    int maxHeightBuilding = 0;
    for (int i = 0; i < n; i++) {
        maxHeightBuilding = max(maxHeightBuilding, dp[i]);
    }
    
    // Free the dynamically allocated memory
    free(dp);
    free(maxHeight);
    
    return maxHeightBuilding;
    
}