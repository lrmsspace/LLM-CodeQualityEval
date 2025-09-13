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
    long long maxScore = 0;
    int n = receiverSize;
    
    for (int start = 0; start < n; start++) {
        long long score = 0;
        int current = start;
        
        // Use a map to detect cycles
        int visited[n];
        for (int i = 0; i < n; i++) visited[i] = -1;
        
        for (long long j = 0; j < k; j++) {
            if (visited[current] != -1) {
                // Cycle detected
                long long cycleLength = j - visited[current];
                long long remainingSteps = k - j;
                long long fullCycles = remainingSteps / cycleLength;
                long long extraSteps = remainingSteps % cycleLength;

                // Calculate the score for the full cycles
                score += fullCycles * score;

                // Add the score for the extra steps
                for (long long m = 0; m < extraSteps; m++) {
                    score += current;
                    current = receiver[current];
                }
                break;
            }
            
            visited[current] = j;
            score += current;
            current = receiver[current];
        }
        
        maxScore = maxScore > score ? maxScore : score;
    }
    
    return maxScore;    
}