/**https://leetcode.com/problems/coloring-a-border/ */
//You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
//Two squares are called adjacent if they are next to each other in any of the 4 directions.
//Two squares belong to the same connected component if they have the same color and they are adjacent.
//The border of a connected component is all the squares in the connected component that are either adjacent to (at least) a square not in the component, or on the boundary of the grid (the first or last row or column).
//You should color the border of the connected component that contains the square grid[row][col] with color.
//Return the final grid.
// 
//Example 1:
//Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
//Output: [[3,3],[3,2]]
//Example 2:
//Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
//Output: [[1,3,3],[2,3,3]]
//Example 3:
//Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
//Output: [[2,2,2],[2,1,2],[2,2,2]]
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j], color <= 1000
//	0 <= row < m
//	0 <= col < n
class Solution {
    public int[][] colorBorder(int[][] grid, int row, int col, int color) { 
        int m = grid.length;
        int n = grid[0].length;
        int[][] visited = new int[m][n];
        int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{row,col});
        visited[row][col] = 1;
        int curColor = grid[row][col];
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            int x = cur[0];
            int y = cur[1];
            boolean isBorder = false;
            for(inti=0;i<4;i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx<0||ny<0||nx>=m||ny>=n||grid[nx][ny]!=curColor){
                    isBorder = true;
                }else if(visited[nx][ny]==0){
                    visited[nx][ny] = 1;
                    queue.add(new int[]{nx,ny});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==1&&grid[i][j]==curColor){
                    boolean isBorder = false;
                    for(int k=0;k<4;k++){
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if(nx<0||ny<0||nx>=m||ny>=n||grid[nx][ny]!=curColor){
                            isBorder = true;
                        }
                    }
                    if(isBorder){
                        grid[i][j] = color;
                    }
                }
            }
        }
        return grid;
    }
}