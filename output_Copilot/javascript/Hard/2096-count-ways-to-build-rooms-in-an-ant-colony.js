/**https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/ */
//You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0.
//You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built.
//Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: prevRoom = [-1,0,1]
//Output: 1
//Explanation: There is only one way to build the additional rooms: 0 → 1 → 2
//Example 2:
//Input: prevRoom = [-1,0,0,1,2]
//Output: 6
//Explanation:
//The 6 ways are:
//0 → 1 → 3 → 2 → 4
//0 → 2 → 4 → 1 → 3
//0 → 1 → 2 → 3 → 4
//0 → 1 → 2 → 4 → 3
//0 → 2 → 1 → 3 → 4
//0 → 2 → 1 → 4 → 3
// 
//Constraints:
//	n == prevRoom.length
//	2 <= n <= 105
//	prevRoom[0] == -1
//	0 <= prevRoom[i] < n for all 1 <= i < n
//	Every room is reachable from room 0 once all the rooms are built.
/**

 * @param {number[]} prevRoom

 * @return {number}

 */

var waysToBuildRooms = function(prevRoom) {

    const MOD = 1e9 + 7;
    const n = prevRoom.length;
    const dp = Array(n).fill(0);
    const fact = Array(n + 1).fill(1);
    
    // Precompute factorials
    for (let i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    // DFS to calculate dp values
    const dfs = (node) => {
        let size = 1; // Count the current node
        let ways = 1; // Initialize ways to build this subtree
        
        for (let i = 1; i < n; i++) {
            if (prevRoom[i] === node) {
                const [childSize, childWays] = dfs(i);
                size += childSize;
                ways = (ways * childWays * fact[childSize]) % MOD;
            }
        }
        
        dp[node] = ways;
        return [size, ways];
    };
    
    dfs(0); // Start DFS from room 0
    
    return dp[0]; // Return the number of ways to build all rooms 
    
};