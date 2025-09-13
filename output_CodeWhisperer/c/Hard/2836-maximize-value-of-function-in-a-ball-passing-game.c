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
long long getMaxFunctionValue(int* receiver, int receiverSize, long long k) {
    // 计算k的二进制位数
    int bits = 0;
    long long temp = k;
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }
    
    // dp[i][j] 表示从i开始走2^j步后的位置
    // sum[i][j] 表示从i开始走2^j步的路径和（不包括起点）
    int** dp = (int**)malloc(receiverSize * sizeof(int*));
    long long** sum = (long long**)malloc(receiverSize * sizeof(long long*));
    for (int i = 0; i < receiverSize; i++) {
        dp[i] = (int*)malloc(bits * sizeof(int));
        sum[i] = (long long*)malloc(bits * sizeof(long long));
        // 初始化第一步（2^0）
        dp[i][0] = receiver[i];
        sum[i][0] = receiver[i];
    }
    
    // 预处理每个2^j步的情况
    for (int j = 1; j < bits; j++) {
        for (int i = 0; i < receiverSize; i++) {
            int mid = dp[i][j-1];
            dp[i][j] = dp[mid][j-1];
            sum[i][j] = sum[i][j-1] + sum[mid][j-1];
        }
    }
    
    // 计算最大得分
    long long maxScore = 0;
    for (int start = 0; start < receiverSize; start++) {
        long long score = start; // 初始分数为起点
        int curr = start;
        
        // 根据k的二进制位处理每一步
        for (int j = 0; j < bits; j++) {
            if (k & (1LL << j)) {
                score += sum[curr][j];
                curr = dp[curr][j];
            }
        }
        
        maxScore = maxScore > score ? maxScore : score;
    }
    
    // 释放内存
    for (int i = 0; i < receiverSize; i++) {
        free(dp[i]);
        free(sum[i]);
    }
    free(dp);
    free(sum);
    
    return maxScore;
}
