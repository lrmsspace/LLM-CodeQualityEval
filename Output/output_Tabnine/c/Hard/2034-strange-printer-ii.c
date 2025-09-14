/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//	On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//	Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.
// 
//Example 1:
//Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
//Output: true
//Example 2:
//Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
//Output: true
//Example 3:
//Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
//Output: false
//Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
// 
//Constraints:
//	m == targetGrid.length
//	n == targetGrid[i].length
//	1 <= m, n <= 60
//	1 <= targetGrid[row][col] <= 60
bool isPrintable(int** targetGrid, int targetGridSize, int* targetGridColSize) {
    // Initialize the frequency of each color
    int colorFrequency[61] = {0};
    for (int i = 0; i < targetGridSize; i++) {
        for (int j = 0; j < targetGridColSize[i]; j++) {
            colorFrequency[targetGrid[i][j]]++;
        }
    }
    
    // Initialize the max frequency of each color
    int maxFrequency = 0;
    for (int i = 1; i <= 60; i++) {
        maxFrequency = max(maxFrequency, colorFrequency[i]);
    }
    
    // Initialize the max height and width of the rectangular pattern
    int maxHeight = 0, maxWidth = 0;
    for (int i = 0; i < targetGridSize; i++) {
        maxHeight = max(maxHeight, targetGridColSize[i]);
        maxWidth = max(maxWidth, maxFrequency);
    }
    
    // Perform a depth-first search to check if it is possible to print the matrix
    bool visited[targetGridSize][targetGridColSize[0]];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < targetGridSize; i++) {
        for (int j = 0; j < targetGridColSize[i]; j++) {
            if (!visited[i][j] && dfs(targetGrid, targetGridSize, targetGridColSize, i, j, visited, colorFrequency, maxFrequency, maxHeight, maxWidth)) {
                return true;
            }
        }
    }
    
    return false;
    
}