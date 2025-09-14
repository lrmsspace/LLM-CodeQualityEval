/*
 There is a 50 x 50 chessboard with one knight and some pawns on it. You are given two integers kx and ky where (kx, ky) denotes the position of the knight, and a 2D array positions where positions[i] = [xi, yi] denotes the position of the pawns on the chessboard.
 Alice and Bob play a turn-based game, where Alice goes first. In each player's turn:
 The player selects a pawn that still exists on the board and captures it with the knight in the fewest possible moves. Note that the player can select any pawn, it might not be one that can be captured in the least number of moves.
 In the process of capturing the selected pawn, the knight may pass other pawns without capturing them. Only the selected pawn can be captured in this turn.
 Alice is trying to maximize the sum of the number of moves made by both players until there are no more pawns on the board, whereas Bob tries to minimize them.
 Return the maximum total number of moves made during the game that Alice can achieve, assuming both players play optimally.
 Note that in one move, a chess knight has eight possible positions it can move to, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
 Example 1:
 Input: kx = 1, ky = 1, positions = [[0,0]]
 Output: 4
 Explanation:
 The knight takes 4 moves to reach the pawn at (0, 0).
 Example 2:
 Input: kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]
 Output: 8
 Explanation:
 Alice picks the pawn at (2, 2) and captures it in two moves: (0, 2) -> (1, 4) -> (2, 2).
 Bob picks the pawn at (3, 3) and captures it in two moves: (2, 2) -> (4, 1) -> (3, 3).
 Alice picks the pawn at (1, 1) and captures it in four moves: (3, 3) -> (4, 1) -> (2, 2) -> (0, 3) -> (1, 1).
 Example 3:
 Input: kx = 0, ky = 0, positions = [[1,2],[2,4]]
 Output: 3
 Explanation:
 Alice picks the pawn at (2, 4) and captures it in two moves: (0, 0) -> (1, 2) -> (2, 4). Note that the pawn at (1, 2) is not captured.
 Bob picks the pawn at (1, 2) and captures it in one move: (2, 4) -> (1, 2).
 Constraints:
 0 <= kx, ky <= 49
 1 <= positions.length <= 15
 positions[i].length == 2
 0 <= positions[i][0], positions[i][1] <= 49
 All positions[i] are unique.
 The input is generated such that positions[i] != [kx, ky] for all 0 <= i < positions.length.
*/

int maxMoves(int kx, int ky, int** positions, int positionsSize, int* positionsColSize) {
    int dp[1 << 15][50][50] = {0}; // DP array to store maximum moves
    int knightMoves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, 
                             {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    
    // Function to calculate the minimum moves from knight to a pawn
    int minMoves(int x, int y, int px, int py) {
        if (x == px && y == py) return 0;
        int queue[2500][3], front = 0, back = 0;
        int visited[50][50] = {0};
        queue[back++] = (int[]){x, y, 0}; // (x, y, moves)
        visited[x][y] = 1;

        while (front < back) {
            int cx = queue[front][0], cy = queue[front][1], moves = queue[front++][2];
            for (int i = 0; i < 8; i++) {
                int nx = cx + knightMoves[i][0], ny = cy + knightMoves[i][1];
                if (nx >= 0 && nx < 50 && ny >= 0 && ny < 50 && !visited[nx][ny]) {
                    if (nx == px && ny == py) return moves + 1;
                    visited[nx][ny] = 1;
                    queue[back++] = (int[]){nx, ny, moves + 1};
                }
            }
        }
        return -1; // unreachable
    }

    // Precompute minimum moves for each pawn
    int minMoveToPawn[15];
    for (int i = 0; i < positionsSize; i++) {
        minMoveToPawn[i] = minMoves(kx, ky, positions[i][0], positions[i][1]);
    }
    // Initialize DP for the base case (no pawns)
    for (int mask = 0; mask < (1 << positionsSize); mask++) {
        dp[mask][kx][ky] = 0; // No moves if no pawns
    }
    // Fill DP table
    for (int mask = 0; mask < (1 << positionsSize); mask++) {
        for (int x = 0; x < 50; x++) {
            for (int y = 0; y < 50; y++) {
                if (dp[mask][x][y] == 0 && mask != 0) continue; // Skip uninitialized states
                for (int i = 0; i < positionsSize; i++) {
                    if (!(mask & (1 << i))) { // If pawn i is not captured
                        int px = positions[i][0], py = positions[i][1];
                        int moves = minMoves(x, y, px, py);
                        if (moves != -1) {
                            int newMask = mask | (1 << i);
                            dp[newMask][px][py] = dp[newMask][px][py] > dp[mask][x][y] + moves ? 
                                                 dp[newMask][px][py] : dp[mask][x][y] + moves;
                        }
                    }
                }
            }
        }
    }
    // Find the maximum moves possible
    int maxMoves = 0;
    for (int mask = 0; mask < (1 << positionsSize); mask++) {
        for (int x = 0; x < 50; x++) {
            for (int y = 0; y < 50; y++) {
                maxMoves = maxMoves > dp[mask][x][y] ? maxMoves : dp[mask][x][y];
            }
        }
    }
    return maxMoves;
        
}