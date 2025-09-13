/**https://leetcode.com/problems/number-of-music-playlists/ */
//Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:
//	Every song is played at least once.
//	A song can only be played again only if k other songs have been played.
//Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 3, goal = 3, k = 1
//Output: 6
//Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
//Example 2:
//Input: n = 2, goal = 3, k = 0
//Output: 6
//Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].
//Example 3:
//Input: n = 2, goal = 3, k = 1
//Output: 2
//Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].
// 
//Constraints:
//	0 <= k < n <= goal <= 100
int numMusicPlaylists(int n, int goal, int k) {
    // DP table to store the number of playlists
    long[][] dp = new long[goal + 1][n + 1];
    
    // Initialize the base cases
    for (int i = 0; i <= goal; i++) {
        dp[i][0] = 1; // There is only 1 way to play 0 songs
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0; // There are 0 ways to play songs when goal is 0
    }
    
    // Fill the DP table
    for (int i = 1; i <= goal; i++) {
        for (int j = 1; j <= n; j++) {
            // Calculate the number of ways to play i songs given j songs played
            // The number of ways to play i songs given j songs played is the sum of the number of ways to play i-1 songs given j songs played
            // and the number of ways to play j-1 songs given i-1 songs played, but only if j-1 >= k
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - 1 >= k? dp[i - 1][j - 1] : 0)) % (1000000007);
        }
    }
    
    // Return the number of playlists
    return (int) dp[goal][n];
    
}