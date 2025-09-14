/**https://leetcode.com/problems/swim-in-rising-water/ */
//You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
//The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
//Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
// 
//Example 1:
//Input: grid = [[0,2],[1,3]]
//Output: 3
//Explanation:
//At time 0, you are in grid location (0, 0).
//You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
//You cannot reach point (1, 1) until time 3.
//When the depth of water is 3, we can swim anywhere inside the grid.
//Example 2:
//Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
//Output: 16
//Explanation: The final route is shown.
//We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
// 
//Constraints:
//	n == grid.length
//	n == grid[i].length
//	1 <= n <= 50
//	0 <= grid[i][j] < n2
//	Each value grid[i][j] is unique.
int swimInWater(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;

    int* parent = (int*)malloc(n * n * sizeof(int));

    for (int i = 0; i < n * n; i++) {
        parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    }

    int* directions = (int*)malloc(4 * sizeof(int));

    directions[0] = 0;

    directions[1] = 1;

    directions[2] = 0;

    directions[3] = -1;

    int* directions2 = (int*)malloc(4 * sizeof(int));

    directions2[0] = 1;

    directions2[1] = 0;

    directions2[2] = -1;

    directions2[3] = 0;

    int* queue = (int*)malloc(n * n * sizeof(int));
    int front = 0;

    int rear = 0;

    queue[rear++] = 0;

    int* visited = (int*)malloc(n * n * sizeof(int));

    memset(visited, 0, n * n * sizeof(int));

    visited[0] = 1;

    int time = 0;

    while (front < rear) {
        int size = rear - front;

        while (size--) {
            int curr = queue[front++];

            int x = curr / n;

            int y = curr % n;

            if (x == n - 1 && y == n - 1) {
                return time;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i];

                int ny = y + directions2[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx * n + ny] && grid[nx][ny] <= time) {
                    unionSet(curr, nx * n + ny);
                    visited[nx * n + ny] = 1;
                    queue[rear++] = nx * n + ny;
                }
            }
        }

        time++;
    }

    return -1;  
    
}