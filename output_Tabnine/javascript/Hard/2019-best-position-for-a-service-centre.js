/**https://leetcode.com/problems/best-position-for-a-service-centre/ */
//A delivery company wants to build a new service center in a new city. The company knows the positions of all the customers in this city on a 2D-Map and wants to build the new center in a position such that the sum of the euclidean distances to all customers is minimum.
//Given an array positions where positions[i] = [xi, yi] is the position of the ith customer on the map, return the minimum sum of the euclidean distances to all customers.
//In other words, you need to choose the position of the service center [xcentre, ycentre] such that the following formula is minimized:
//Answers within 10-5 of the actual value will be accepted.
// 
//Example 1:
//Input: positions = [[0,1],[1,0],[1,2],[2,1]]
//Output: 4.00000
//Explanation: As shown, you can see that choosing [xcentre, ycentre] = [1, 1] will make the distance to each customer = 1, the sum of all distances is 4 which is the minimum possible we can achieve.
//Example 2:
//Input: positions = [[1,1],[3,3]]
//Output: 2.82843
//Explanation: The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843
// 
//Constraints:
//	1 <= positions.length <= 50
//	positions[i].length == 2
//	0 <= xi, yi <= 100
/**
 * @param {number[][]} positions
 * @return {number}
 */
var getMinDistSum = function(positions) {
    const n = positions.length;
    let minSum = Infinity;
    const visited = Array(n).fill(false);
    
    const dfs = (x, y, sum) => {
        if (sum >= minSum) return;
        if (visited.every(v => v)) {
            minSum = Math.min(minSum, sum);
            return;
        }
        
        visited[x] = true;
        
        for (let i = 0; i < n; i++) {
            if (!visited[i]) {
                const dx = positions[x][0] - positions[i][0];
                const dy = positions[x][1] - positions[i][1];
                dfs(i, y, sum + Math.sqrt(dx * dx + dy * dy));
            }
        }
        
        visited[x] = false;
    };
    
    for (let i = 0; i < n; i++) {
        dfs(i, i, 0);
    }
    
    return minSum;
    
};