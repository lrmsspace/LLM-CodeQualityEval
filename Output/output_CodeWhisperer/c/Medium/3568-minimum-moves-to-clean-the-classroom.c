/*
 You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:
 'S': Starting position of the student
 'L': Litter that must be collected (once collected, the cell becomes empty)
 'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
 'X': Obstacle the student cannot pass through
 '.': Empty space
 You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.
 Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.
 Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.
 Example 1:
 Input: classroom = ["S.", "XL"], energy = 2
 Output: 2
 Explanation:
 The student starts at cell (0, 0) with 2 units of energy.
 Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
 A valid sequence of moves to collect all litter is as follows:
 Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
 Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
 The student collects all the litter using 2 moves. Thus, the output is 2.
 Example 2:
 Input: classroom = ["LS", "RL"], energy = 4
 Output: 3
 Explanation:
 The student starts at cell (0, 1) with 4 units of energy.
 A valid sequence of moves to collect all litter is as follows:
 Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining.
 Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4.
 Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
 The student collects all the litter using 3 moves. Thus, the output is 3.
 Example 3:
 Input: classroom = ["L.S", "RXL"], energy = 3
 Output: -1
 Explanation:
 No valid path collects all 'L'.
 Constraints:
 1 <= m == classroom.length <= 20
 1 <= n == classroom[i].length <= 20
 classroom[i][j] is one of 'S', 'L', 'R', 'X', or '.'
 1 <= energy <= 50
 There is exactly one 'S' in the grid.
 There are at most 10 'L' cells in the grid.
*/

int minMoves(char** classroom, int classroomSize, int energy) {
    // Get grid dimensions
    int m = classroomSize;
    int n = strlen(classroom[0]);
    
    // Find starting position and count litter
    int startX = -1, startY = -1;
    int litterCount = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(classroom[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            else if(classroom[i][j] == 'L') {
                litterCount++;
            }
        }
    }
    
    // State encoding: (x, y, energy, collected_litter_state)
    // Use queue for BFS
    typedef struct {
        int x, y;
        int energy;
        int state;
        int moves;
    } State;
    
    // Create queue
    State* queue = (State*)malloc(sizeof(State) * m * n * energy * (1 << litterCount));
    int front = 0, rear = 0;
    
    // Track visited states
    int**** visited = (int****)malloc(m * sizeof(int***));
    for(int i = 0; i < m; i++) {
        visited[i] = (int***)malloc(n * sizeof(int**));
        for(int j = 0; j < n; j++) {
            visited[i][j] = (int**)malloc((energy + 1) * sizeof(int*));
            for(int k = 0; k <= energy; k++) {
                visited[i][j][k] = (int*)calloc((1 << litterCount), sizeof(int));
            }
        }
    }
    
    // Directions for movement
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    // Start BFS
    queue[rear++] = (State){startX, startY, energy, 0, 0};
    visited[startX][startY][energy][0] = 1;
    
    while(front < rear) {
        State curr = queue[front++];
        
        // Check if all litter collected
        if(curr.state == (1 << litterCount) - 1) {
            // Free memory
            free(queue);
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    for(int k = 0; k <= energy; k++) {
                        free(visited[i][j][k]);
                    }
                    free(visited[i][j]);
                }
                free(visited[i]);
            }
            free(visited);
            return curr.moves;
        }
        
        // Try all directions
        for(int d = 0; d < 4; d++) {
            int newX = curr.x + dx[d];
            int newY = curr.y + dy[d];
            
            // Check bounds and obstacles
            if(newX < 0 || newX >= m || newY < 0 || newY >= n || 
               classroom[newX][newY] == 'X' || curr.energy == 0) {
                continue;
            }
            
            int newEnergy = curr.energy - 1;
            int newState = curr.state;
            
            // Reset energy if on 'R'
            if(classroom[newX][newY] == 'R') {
                newEnergy = energy;
            }
            
            // Collect litter if present
            if(classroom[newX][newY] == 'L') {
                int litterBit = 0;
                int tempX = 0, tempY = 0;
                for(int i = 0; i < m; i++) {
                    for(int j = 0; j < n; j++) {
                        if(classroom[i][j] == 'L') {
                            if(i == newX && j == newY) {
                                litterBit = (1 << tempY);
                                break;
                            }
                            tempY++;
                        }
                    }
                    if(litterBit) break;
                }
                newState |= litterBit;
            }
            
            // Add new state if not visited
            if(!visited[newX][newY][newEnergy][newState]) {
                queue[rear++] = (State){newX, newY, newEnergy, newState, curr.moves + 1};
                visited[newX][newY][newEnergy][newState] = 1;
            }
        }
    }
    
    // Free memory
    free(queue);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k <= energy; k++) {
                free(visited[i][j][k]);
            }
            free(visited[i][j]);
        }
        free(visited[i]);
    }
    free(visited);
    
    return -1;
}            
