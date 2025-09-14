/**https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/ */
//You are given a 0-indexed 2D integer array grid of size m x n that represents a map of the items in a shop. The integers in the grid represent the following:
//	0 represents a wall that you cannot pass through.
//	1 represents an empty cell that you can freely move to and from.
//	All other positive integers represent the price of an item in that cell. You may also freely move to and from these item cells.
//It takes 1 step to travel between adjacent grid cells.
//You are also given integer arrays pricing and start where pricing = [low, high] and start = [row, col] indicates that you start at the position (row, col) and are interested only in items with a price in the range of [low, high] (inclusive). You are further given an integer k.
//You are interested in the positions of the k highest-ranked items whose prices are within the given price range. The rank is determined by the first of these criteria that is different:
//	Distance, defined as the length of the shortest path from the start (shorter distance has a higher rank).
//	Price (lower price has a higher rank, but it must be in the price range).
//	The row number (smaller row number has a higher rank).
//	The column number (smaller column number has a higher rank).
//Return the k highest-ranked items within the price range sorted by their rank (highest to lowest). If there are fewer than k reachable items within the price range, return all of them.
// 
//Example 1:
//Input: grid = [[1,2,0,1],[1,3,0,1],[0,2,5,1]], pricing = [2,5], start = [0,0], k = 3
//Output: [[0,1],[1,1],[2,1]]
//Explanation: You start at (0,0).
//With a price range of [2,5], we can take items from (0,1), (1,1), (2,1) and (2,2).
//The ranks of these items are:
//- (0,1) with distance 1
//- (1,1) with distance 2
//- (2,1) with distance 3
//- (2,2) with distance 4
//Thus, the 3 highest ranked items in the price range are (0,1), (1,1), and (2,1).
//Example 2:
//Input: grid = [[1,2,0,1],[1,3,3,1],[0,2,5,1]], pricing = [2,3], start = [2,3], k = 2
//Output: [[2,1],[1,2]]
//Explanation: You start at (2,3).
//With a price range of [2,3], we can take items from (0,1), (1,1), (1,2) and (2,1).
//The ranks of these items are:
//- (2,1) with distance 2, price 2
//- (1,2) with distance 2, price 3
//- (1,1) with distance 3
//- (0,1) with distance 4
//Thus, the 2 highest ranked items in the price range are (2,1) and (1,2).
//Example 3:
//Input: grid = [[1,1,1],[0,0,1],[2,3,4]], pricing = [2,3], start = [0,0], k = 3
//Output: [[2,1],[2,0]]
//Explanation: You start at (0,0).
//With a price range of [2,3], we can take items from (2,0) and (2,1). 
//The ranks of these items are: 
//- (2,1) with distance 5
//- (2,0) with distance 6
//Thus, the 2 highest ranked items in the price range are (2,1) and (2,0). 
//Note that k = 3 but there are only 2 reachable items within the price range.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	0 <= grid[i][j] <= 105
//	pricing.length == 2
//	2 <= low <= high <= 105
//	start.length == 2
//	0 <= row <= m - 1
//	0 <= col <= n - 1
//	grid[row][col] > 0
//	1 <= k <= m * n
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** highestRankedKItems(int** grid, int gridSize, int* gridColSize, int* pricing, int pricingSize, int* start, int startSize, int k, int* returnSize, int** returnColumnSizes) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = gridSize, n = gridColSize[0];
    int** res = (int**)malloc(k * sizeof(int*));
    int* colSizes = (int*)malloc(k * sizeof(int));
    int idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] >= pricing[0] && grid[i][j] <= pricing[1]) {
                int dist = INT_MAX, x = INT_MAX, y = INT_MAX;
                if (start[0] == i && start[1] == j) {
                    dist = 0;
                } else {
                    int visited[m][n];
                    memset(visited, 0, sizeof(visited));
                    int d = 0;
                    queue<pair<int, int>> q;
                    q.push({start[0], start[1]});
                    visited[start[0]][start[1]] = 1;
                    while (!q.empty()) {
                        int sz = q.size();
                        for (int _ = 0; _ < sz; _++) {
                            int x0 = q.front().first, y0 = q.front().second;
                            q.pop();
                            if (x0 == i && y0 == j) {
                                dist = d;
                                break;
                            }
                            for (int k = 0; k < 4; k++) {
                                int x1 = x0 + directions[k][0], y1 = y0 + directions[k][1];
                                if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] != 0 && !visited[x1][y1]) {
                                    q.push({x1, y1});
                                    visited[x1][y1] = 1;
                                }
                            }
                        }
                        d++;
                    }
                }
                if (dist < x) {
                    x = dist;
                    y = grid[i][j];
                    res[idx] = (int*)malloc(2 * sizeof(int));
                    res[idx][0] = i;
                    res[idx][1] = j;
                    colSizes[idx++] = 2;
                } else if (dist == x && grid[i][j] < y) {
                    y = grid[i][j];
                    res[idx] = (int*)malloc(2 * sizeof(int));
                    res[idx][0] = i;
                    res[idx][1] = j;
                    colSizes[idx++] = 2;
                }
            }
        }
    }
    *returnSize = idx;
    *returnColumnSizes = colSizes;
    return res;
    
}