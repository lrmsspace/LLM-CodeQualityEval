/*
 You are given an integer array receiver of length n and an integer k. n players are playing a ball-passing game.
 You choose the starting player, i. The game proceeds as follows: player i passes the ball to player receiver[i], who then passes it to receiver[receiver[i]], and so on, for k passes in total. The game's score is the sum of the indices of the players who touched the ball, including repetitions, i.e. i + receiver[i] + receiver[receiver[i]] + ... + receiver(k)[i].
 Return the maximum possible score.
 Notes:
 receiver may contain duplicates.
 receiver[i] may be equal to i.
 Example 1:
 Input: receiver = [2,0,1], k = 4
 Output: 6
 Explanation:
 Starting with player i = 2 the initial score is 2:
 Pass
 Sender Index
 Receiver Index
 Score
 1
 2
 1
 3
 2
 1
 0
 3
 3
 0
 2
 5
 4
 2
 1
 6
 Example 2:
 Input: receiver = [1,1,1,2,3], k = 3
 Output: 10
 Explanation:
 Starting with player i = 4 the initial score is 4:
 Pass
 Sender Index
 Receiver Index
 Score
 1
 4
 3
 7
 2
 3
 2
 9
 3
 2
 1
 10
 Constraints:
 1 <= receiver.length == n <= 105
 0 <= receiver[i] <= n - 1
 1 <= k <= 1010
*/

/**
 * @param {number[]} receiver
 * @param {number} k
 * @return {number}
 */
var getMaxFunctionValue = function(receiver, k) {
    const n = receiver.length;
    const m = Math.floor(Math.log2(k)) + 1;
    const dp = new Array(n).fill(0).map(() => new Array(m).fill(0));
    
    for (let i = 0; i < n; i++) {
        dp[i][0] = receiver[i];
    }
    
    for (let j = 1; j < m; j++) {
        for (let i = 0; i < n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    
    let ans = 0;
    for (let i = 0; i < n; i++) {
        let sum = i;
        let cur = i;
        for (let j = 0; j < m; j++) {
            if ((k >> j) & 1) {
                sum += dp[cur][j];
                cur = dp[cur][j];
            }
        }
        ans = Math.max(ans, sum);
    }
    
    return ans;        
};