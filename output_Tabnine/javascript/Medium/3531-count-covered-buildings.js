/*
 You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].
 A building is covered if there is at least one building in all four directions: left, right, above, and below.
 Return the number of covered buildings.
 Example 1:
 Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
 Output: 1
 Explanation:
 Only building [2,2] is covered as it has at least one building:
 above ([1,2])
 below ([3,2])
 left ([2,1])
 right ([2,3])
 Thus, the count of covered buildings is 1.
 Example 2:
 Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]
 Output: 0
 Explanation:
 No building has at least one building in all four directions.
 Example 3:
 Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]
 Output: 1
 Explanation:
 Only building [3,3] is covered as it has at least one building:
 above ([1,3])
 below ([5,3])
 left ([3,2])
 right ([3,5])
 Thus, the count of covered buildings is 1.
 Constraints:
 2 <= n <= 105
 1 <= buildings.length <= 105 
 buildings[i] = [x, y]
 1 <= x, y <= n
 All coordinates of buildings are unique.
*/

/**
 * @param {number} n
 * @param {number[][]} buildings
 * @return {number}
 */
var countCoveredBuildings = function(n, buildings) {
    // Initialize a 2D array dp to store the count of buildings covered by each building
    const dp = Array.from({length: n + 1}, () => Array(n + 1).fill(0));
    
    // Sort the buildings based on their x-coordinate
    buildings.sort((a, b) => a[0] - b[0]);  
    let count = 0;
    for (let i = 0; i < buildings.length; i++) {
        const [x, y] = buildings[i];
        // Update the count of buildings covered by the current building
        count += (y - 1) - dp[x][y - 1];
        
        // Update the count of buildings covered by buildings to the right of the current building
        for (let j = x + 1; j <= n; j++) {
            dp[j][y] = Math.max(dp[j][y], count);
        }
    }
    // Return the total count of covered buildings
    return count;
    
};