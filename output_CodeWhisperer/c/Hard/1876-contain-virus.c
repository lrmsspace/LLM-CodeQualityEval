/**https://leetcode.com/problems/contain-virus/ */
//A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
//The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.
//Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.
//Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.
// 
//Example 1:
//Input: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
//Output: 10
//Explanation: There are 2 contaminated regions.
//On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
//On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
//Example 2:
//Input: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 4
//Explanation: Even though there is only one cell saved, there are 4 walls built.
//Notice that walls are only built on the shared boundary of two different cells.
//Example 3:
//Input: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
//Output: 13
//Explanation: The region on the left only builds two new walls.
// 
//Constraints:
//	m == isInfected.length
//	n == isInfected[i].length
//	1 <= m, n <= 50
//	isInfected[i][j] is either 0 or 1.
//	There is always a contiguous viral region throughout the described process that will infect strictly more uncontaminated squares in the next round.
int containVirus(int** isInfected, int isInfectedSize, int* isInfectedColSize) {
    int m = isInfectedSize, n = isInfectedColSize[0];

    int walls = 0;

    while (true) {
        int max = 0, maxI = -1, maxJ = -1;
        int** visited = (int**)malloc(sizeof(int*) * m);
        for (int i = 0; i < m; i++) {
            visited[i] = (int*)malloc(sizeof(int) * n);
            memset(visited[i], 0, sizeof(int) * n);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isInfected[i][j] == 1 && !visited[i][j]) {
                    int count = 0;
                    int** region = (int**)malloc(sizeof(int*) * m);
                    for (int k = 0; k < m; k++) {
                        region[k] = (int*)malloc(sizeof(int) * n);
                        memset(region[k], 0, sizeof(int) * n);
                    }
                    int** perimiter = (int**)malloc(sizeof(int*) * m);
                    for (int k = 0; k < m; k++) {
                        perimiter[k] = (int*)malloc(sizeof(int) * n);
                        memset(perimiter[k], 0, sizeof(int) * n);
                    }
                    dfs(isInfected, visited, region, perimiter, i, j, m, n, &count);
                    if (count > max) {
                        max = count;
                        maxI = i;
                        maxJ = j;
                    }
                    for (int k = 0; k < m; k++) {
                        free(region[k]);
                        free(perimiter[k]);
                    }
                    free(region);
                    free(perimiter);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            free(visited[i]);
        }
        free(visited);

        if (maxI == -1) {
            break;
        }

        walls += buildWalls(isInfected, maxI, maxJ, m, n);
    }
    return walls;
}