/*
 There is a dungeon with n x m rooms arranged as a grid.
 You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
 Return the minimum time to reach the room (n - 1, m - 1).
 Two rooms are adjacent if they share a common wall, either horizontally or vertically.
 Example 1:
 Input: moveTime = [[0,4],[4,4]]
 Output: 7
 Explanation:
 The minimum time required is 7 seconds.
 At time t == 4, move from room (0, 0) to room (1, 0) in one second.
 At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
 Example 2:
 Input: moveTime = [[0,0,0,0],[0,0,0,0]]
 Output: 6
 Explanation:
 The minimum time required is 6 seconds.
 At time t == 0, move from room (0, 0) to room (1, 0) in one second.
 At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
 At time t == 3, move from room (1, 1) to room (1, 2) in one second.
 At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
 Example 3:
 Input: moveTime = [[0,1],[1,2]]
 Output: 4
 Constraints:
 2 <= n == moveTime.length <= 750
 2 <= m == moveTime[i].length <= 750
 0 <= moveTime[i][j] <= 109
*/

int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize) {
    // Create dp array to store minimum time to reach each cell
    int n = moveTimeSize;
    int m = moveTimeColSize[0];
    int dp[750][750];
    
    // Initialize dp array with max value
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = 1e9;
        }
    }
    
    // Initialize starting point
    dp[0][0] = 0;
    
    // BFS queue to store cells to process
    int queue[750*750][3];
    int front = 0, rear = 0;
    
    // Add starting cell to queue with time=0 and move=1
    queue[rear][0] = 0;
    queue[rear][1] = 0; 
    queue[rear][2] = 1;
    rear++;
    
    // Directions for adjacent cells
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    while(front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        int move = queue[front][2];
        front++;
        
        // Try all 4 directions
        for(int i = 0; i < 4; i++) {
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            
            // Check if new position is valid
            if(newX >= 0 && newX < n && newY >= 0 && newY < m) {
                // Calculate new time considering alternating move times
                int newTime = dp[x][y];
                if(newTime < moveTime[newX][newY]) {
                    newTime = moveTime[newX][newY];
                }
                newTime += move;
                
                // Update if new time is less
                if(newTime < dp[newX][newY]) {
                    dp[newX][newY] = newTime;
                    queue[rear][0] = newX;
                    queue[rear][1] = newY;
                    queue[rear][2] = move == 1 ? 2 : 1;
                    rear++;
                }
            }
        }
    }
    
    return dp[n-1][m-1];
}    