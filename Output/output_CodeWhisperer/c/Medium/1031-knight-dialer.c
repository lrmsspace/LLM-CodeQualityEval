/**https://leetcode.com/problems/knight-dialer/ */
//The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagram:
//A chess knight can move as indicated in the chess diagram below:
//We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
//Given an integer n, return how many distinct phone numbers of length n we can dial.
//You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.
//As the answer may be very large, return the answer modulo 109 + 7.
// 
//Example 1:
//Input: n = 1
//Output: 10
//Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
//Example 2:
//Input: n = 2
//Output: 20
//Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
//Example 3:
//Input: n = 3131
//Output: 136006598
//Explanation: Please take care of the mod.
// 
//Constraints:
//	1 <= n <= 5000
#define MOD 1000000007  
int knightDialer(int n) {
    // If n is 1, we can dial any digit
    if (n == 1) return 10;
    
    // Define the possible moves for each digit
    int moves[10][3] = {
        {4, 6, -1},    // from 0
        {6, 8, -1},    // from 1
        {7, 9, -1},    // from 2
        {4, 8, -1},    // from 3
        {0, 3, 9},     // from 4
        {-1, -1, -1},  // from 5 (no valid moves)
        {0, 1, 7},     // from 6
        {2, 6, -1},    // from 7
        {1, 3, -1},    // from 8
        {2, 4, -1}     // from 9
    };
    
    // Initialize counts for each digit
    long current[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    long next[10];
    
    // Perform n-1 jumps
    for (int i = 1; i < n; i++) {
        // Reset next array
        for (int j = 0; j < 10; j++) {
            next[j] = 0;
        }
        
        // Calculate next state
        for (int d = 0; d < 10; d++) {
            for (int j = 0; j < 3 && moves[d][j] != -1; j++) {
                int nextDigit = moves[d][j];
                next[nextDigit] = (next[nextDigit] + current[d]) % MOD;
            }
        }
        
        // Update current state
        for (int d = 0; d < 10; d++) {
            current[d] = next[d];
        }
    }
    
    // Sum up all possibilities
    long result = 0;
    for (int d = 0; d < 10; d++) {
        result = (result + current[d]) % MOD;
    }
    
    return (int)result;
}
