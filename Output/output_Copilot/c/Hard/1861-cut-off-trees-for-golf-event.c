/**https://leetcode.com/problems/cut-off-trees-for-golf-event/ */
//You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:
//	0 means the cell cannot be walked through.
//	1 represents an empty cell that can be walked through.
//	A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
//In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.
//You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).
//Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.
//Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.
// 
//Example 1:
//Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
//Output: 6
//Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.
//Example 2:
//Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
//Output: -1
//Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.
//Example 3:
//Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
//Output: 6
//Explanation: You can follow the same path as Example 1 to cut off all the trees.
//Note that you can cut off the first tree at (0, 0) before making any steps.
// 
//Constraints:
//	m == forest.length
//	n == forest[i].length
//	1 <= m, n <= 50
//	0 <= forest[i][j] <= 109
//	Heights of all trees are distinct.


        typedef struct {
            int x, y, steps;
        } Point;

        int compare(const void* a, const void* b) {
            return (*(int**)a)[2] - (*(int**)b)[2];
        }

        bool isValid(int x, int y, int rows, int cols, int** forest, bool** visited) {
            return x >= 0 && x < rows && y >= 0 && y < cols && forest[x][y] > 0 && !visited[x][y];
        }

        int bfs(int** forest, int rows, int cols, int startX, int startY, int targetX, int targetY) {
            if (startX == targetX && startY == targetY) return 0;

            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            bool** visited = (bool**)malloc(rows * sizeof(bool*));
            for (int i = 0; i < rows; i++) {
                visited[i] = (bool*)calloc(cols, sizeof(bool));
            }

            Point* queue = (Point*)malloc(rows * cols * sizeof(Point));
            int front = 0, rear = 0;

            queue[rear++] = (Point){startX, startY, 0};
            visited[startX][startY] = true;

            while (front < rear) {
                Point current = queue[front++];
                for (int i = 0; i < 4; i++) {
                    int newX = current.x + directions[i][0];
                    int newY = current.y + directions[i][1];
                    if (isValid(newX, newY, rows, cols, forest, visited)) {
                        if (newX == targetX && newY == targetY) {
                            for (int i = 0; i < rows; i++) free(visited[i]);
                            free(visited);
                            free(queue);
                            return current.steps + 1;
                        }
                        queue[rear++] = (Point){newX, newY, current.steps + 1};
                        visited[newX][newY] = true;
                    }
                }
            }

            for (int i = 0; i < rows; i++) free(visited[i]);
            free(visited);
            free(queue);
            return -1;
        }

        int cutOffTree(int** forest, int forestSize, int* forestColSize) {
            int rows = forestSize, cols = forestColSize[0];
            int treeCount = 0;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (forest[i][j] > 1) treeCount++;
                }
            }

            int** trees = (int**)malloc(treeCount * sizeof(int*));
            int index = 0;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (forest[i][j] > 1) {
                        trees[index] = (int*)malloc(3 * sizeof(int));
                        trees[index][0] = i;
                        trees[index][1] = j;
                        trees[index][2] = forest[i][j];
                        index++;
                    }
                }
            }

            qsort(trees, treeCount, sizeof(int*), compare);

            int totalSteps = 0, startX = 0, startY = 0;

            for (int i = 0; i < treeCount; i++) {
                int targetX = trees[i][0], targetY = trees[i][1];
                int steps = bfs(forest, rows, cols, startX, startY, targetX, targetY);
                if (steps == -1) {
                    for (int j = 0; j < treeCount; j++) free(trees[j]);
                    free(trees);
                    return -1;
                }
                totalSteps += steps;
                startX = targetX;
                startY = targetY;
                forest[startX][startY] = 1;
            }

            for (int i = 0; i < treeCount; i++) free(trees[i]);
            free(trees);
            return totalSteps;
        }

            