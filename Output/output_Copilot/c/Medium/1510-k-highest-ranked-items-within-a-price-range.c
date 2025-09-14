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
       int m = gridSize, n = gridColSize[0];
        int low = pricing[0], high = pricing[1];
        int row = start[0], col = start[1];
        int* dist = (int*)malloc(sizeof(int) * m * n);
        int* price = (int*)malloc(sizeof(int) * m * n);
        int** result = (int**)malloc(sizeof(int*) * k);
        *returnColumnSizes = (int*)malloc(sizeof(int) * k);
        *returnSize = 0;
        int* visited = (int*)malloc(sizeof(int) * m * n);
        memset(visited, 0, sizeof(int) * m * n);
        int* dx = (int*)malloc(sizeof(int) * 4);
        int* dy = (int*)malloc(sizeof(int) * 4);
        dx[0] = 0, dy[0] = 1;
        dx[1] = 1, dy[1] = 0;
        dx[2] = 0, dy[2] = -1;
        dx[3] = -1, dy[3] = 0;
        int* q = (int*)malloc(sizeof(int) * m * n);
        int l = 0, r = 0;
        q[r++] = row * n + col;
        visited[row * n + col] = 1;
        dist[row * n + col] = 0;
        price[row * n + col] = grid[row][col];
        while (l < r) {
            int x = q[l] / n, y = q[l] % n;
            l++;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 0 && !visited[nx * n + ny]) {
                    visited[nx * n + ny] = 1;
                    dist[nx * n + ny] = dist[x * n + y] + 1;
                    price[nx * n + ny] = grid[nx][ny];
                    q[r++] = nx * n + ny;
                }
            }
        }
        int** items = (int**)malloc(sizeof(int*) * m * n);
        int itemCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            if (visited[i * n + j] && grid[i][j] >= low && grid[i][j] <= high) {
                items[itemCount] = (int*)malloc(sizeof(int) * 4);
                items[itemCount][0] = dist[i * n + j];
                items[itemCount][1] = grid[i][j];
                items[itemCount][2] = i;
                items[itemCount][3] = j;
                itemCount++;
            }
            }
        }

        qsort(items, itemCount, sizeof(int*), [](const void* a, const void* b) {
            int* itemA = *(int**)a;
            int* itemB = *(int**)b;
            if (itemA[0] != itemB[0]) return itemA[0] - itemB[0];
            if (itemA[1] != itemB[1]) return itemA[1] - itemB[1];
            if (itemA[2] != itemB[2]) return itemA[2] - itemB[2];
            return itemA[3] - itemB[3];
        });

        for (int i = 0; i < k && i < itemCount; i++) {
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = items[i][2];
            result[*returnSize][1] = items[i][3];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }

        for (int i = 0; i < itemCount; i++) {
            free(items[i]);
        }
        free(items);
        free(dist);
        free(price);
        free(visited);
        free(dx);
        free(dy);
        free(q);    

}