/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.
// 
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//	1 <= grid.length <= 100
//	1 <= grid[0].length <= 100
//	grid[i][j] is 0 or 1


int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
    int max = 0;
    int m = gridSize;
    int n = gridColSize[0];
    int** left = (int**)malloc(sizeof(int*) * m);
    int** top = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++)
    {
        left[i] = (int*)malloc(sizeof(int) * n);
        top[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
                top[i][j] = (i == 0) ? 1 : top[i - 1][j] + 1;
                int len = fmin(left[i][j], top[i][j]);
                while (len > max)
                {
                    if (top[i][j - len + 1] >= len && left[i - len + 1][j] >= len)
                    {
                        max = len;
                        break;
                    }
                    len--;
                }
            }
        }
    }
    return max * max;
}