/**https://leetcode.com/problems/stone-game-vi/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//There are n stones in a pile. On each player's turn, they can remove a stone from the pile and receive points based on the stone's value. Alice and Bob may value the stones differently.
//You are given two integer arrays of length n, aliceValues and bobValues. Each aliceValues[i] and bobValues[i] represents how Alice and Bob, respectively, value the ith stone.
//The winner is the person with the most points after all the stones are chosen. If both players have the same amount of points, the game results in a draw. Both players will play optimally. Both players know the other's values.
//Determine the result of the game, and:
//	If Alice wins, return 1.
//	If Bob wins, return -1.
//	If the game results in a draw, return 0.
// 
//Example 1:
//Input: aliceValues = [1,3], bobValues = [2,1]
//Output: 1
//Explanation:
//If Alice takes stone 1 (0-indexed) first, Alice will receive 3 points.
//Bob can only choose stone 0, and will only receive 2 points.
//Alice wins.
//Example 2:
//Input: aliceValues = [1,2], bobValues = [3,1]
//Output: 0
//Explanation:
//If Alice takes stone 0, and Bob takes stone 1, they will both have 1 point.
//Draw.
//Example 3:
//Input: aliceValues = [2,4,3], bobValues = [1,6,7]
//Output: -1
//Explanation:
//Regardless of how Alice plays, Bob will be able to have more points than Alice.
//For example, if Alice takes stone 1, Bob can take stone 2, and Alice takes stone 0, Alice will have 6 points to Bob's 7.
//Bob wins.
// 
//Constraints:
//	n == aliceValues.length == bobValues.length
//	1 <= n <= 105
//	1 <= aliceValues[i], bobValues[i] <= 100
int stoneGameVI(int* aliceValues, int aliceValuesSize, int* bobValues, int bobValuesSize) {
    int n = aliceValuesSize;
    int* sumAlice = (int*)malloc(sizeof(int) * n);
    int* sumBob = (int*)malloc(sizeof(int) * n);
    sumAlice[0] = aliceValues[0];
    sumBob[0] = bobValues[0];
    
    for (int i = 1; i < n; i++) {
        sumAlice[i] = sumAlice[i - 1] + aliceValues[i];
        sumBob[i] = sumBob[i - 1] + bobValues[i];
    }
    
    int* dp = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        dp[i] = sumAlice[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int start = 0; start <= n - len; start++) {
            int end = start + len - 1;
            dp[start] = fmax(dp[start], sumAlice[end] - dp[start] + sumBob[start - 1]);
        }
    }
    
    int result = dp[0] > sumAlice[n - 1] - dp[0]? 1 : dp[0] < sumAlice[n - 1] - dp[0]? -1 : 0;
    free(sumAlice);
    free(sumBob);
    free(dp);
    return result;
    
}