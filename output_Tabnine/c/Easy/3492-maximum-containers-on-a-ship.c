/*
 You are given a positive integer n representing an n x n cargo deck on a ship. Each cell on the deck can hold one container with a weight of exactly w.
 However, the total weight of all containers, if loaded onto the deck, must not exceed the ship's maximum weight capacity, maxWeight.
 Return the maximum number of containers that can be loaded onto the ship.
 Example 1:
 Input: n = 2, w = 3, maxWeight = 15
 Output: 4
 Explanation: 
 The deck has 4 cells, and each container weighs 3. The total weight of loading all containers is 12, which does not exceed maxWeight.
 Example 2:
 Input: n = 3, w = 5, maxWeight = 20
 Output: 4
 Explanation: 
 The deck has 9 cells, and each container weighs 5. The maximum number of containers that can be loaded without exceeding maxWeight is 4.
 Constraints:
 1 <= n <= 1000
 1 <= w <= 1000
 1 <= maxWeight <= 109
*/

int maxContainers(int n, int w, int maxWeight) {

    // Initialize the dp array with 0s
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    
    // Iterate through the cells of the deck
    for (int i = 1; i <= n; i++) {
        // Calculate the maximum number of containers that can be loaded in the current cell
        int maxContainers = min(i, maxWeight / w);
        
        // Iterate through the possible number of containers
        for (int j = 1; j <= maxContainers; j++) {
            // Update the maximum number of containers that can be loaded in the current cell
            dp[i] = max(dp[i], dp[i - j] + j);
        }
    }
    
    // Return the maximum number of containers that can be loaded onto the ship
    return dp[n];
    
}