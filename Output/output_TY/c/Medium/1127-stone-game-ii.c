/**https://leetcode.com/problems/stone-game-ii/ */
//Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 
//Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
//On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
//The game continues until all the stones have been taken.
//Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
// 
//Example 1:
//Input: piles = [2,7,9,4,4]
//Output: 10
//Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
//Example 2:
//Input: piles = [1,2,3,4,5,100]
//Output: 104
// 
//Constraints:
//	1 <= piles.length <= 100
//	1 <= piles[i] <= 104
int stoneGameII(int* piles, int pilesSize){
    int sum = 0;
    for (int i = 0; i < pilesSize; i++) sum += piles[i];
    int dp[101][101] = { 0 };
    for (int i = pilesSize - 1; i >= 0; i--) {
        for (int M = 1; M <= 100; M++) {
            int sum_ = 0;
            for (int x = 1;x <= 2 * M; x++) {
                sum_ += piles[i + x - 1];
                dp[i][M] = max(dp[i][M], sum_ + (i + x >= pilesSize ? 0 : dp[i + x][min(2 * M, pilesSize - i - x)]));
                sum_ -= piles[i + x - 1];
                if (sum_ <= 0) break;
                sum_ = 0;
                x = 100;
                continue;
            }
        }
    }
    return sum - dp[0][1];
}