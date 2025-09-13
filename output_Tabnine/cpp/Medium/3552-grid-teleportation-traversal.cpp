/*
 You are given a 2D character grid matrix of size m x n, represented as an array of strings, where matrix[i][j] represents the cell at the intersection of the ith row and jth column. Each cell is one of the following:
 '.' representing an empty cell.
 '#' representing an obstacle.
 An uppercase letter ('A'-'Z') representing a teleportation portal.
 You start at the top-left cell (0, 0), and your goal is to reach the bottom-right cell (m - 1, n - 1). You can move from the current cell to any adjacent cell (up, down, left, right) as long as the destination cell is within the grid bounds and is not an obstacle.
 If you step on a cell containing a portal letter and you haven't used that portal letter before, you may instantly teleport to any other cell in the grid with the same letter. This teleportation does not count as a move, but each portal letter can be used at most once during your journey.
 Return the minimum number of moves required to reach the bottom-right cell. If it is not possible to reach the destination, return -1.
 Example 1:
 Input: matrix = ["A..",".A.","..."]
 Output: 2
 Explanation:
 Before the first move, teleport from (0, 0) to (1, 1).
 In the first move, move from (1, 1) to (1, 2).
 In the second move, move from (1, 2) to (2, 2).
 Example 2:
 Input: matrix = [".#...",".#.#.",".#.#.","...#."]
 Output: 13
 Explanation:
 Constraints:
 1 <= m == matrix.length <= 103
 1 <= n == matrix[i].length <= 103
 matrix[i][j] is either '#', '.', or an uppercase English letter.
 matrix[0][0] is not an obstacle.
*/

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        set<char> usedPortals;

        q.push({0, 0});
        dist[0][0] = 0;
        usedPortals.insert('A');

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i == m - 1 && j == n - 1) {
                return dist[i][j];
            }

            for (int k = i - 1; k <= i + 1; ++k) {
                for (int l = j - 1; l <= j + 1; ++l) {
                    if (k >= 0 && k < m && l >= 0 && l < n && matrix[k][l] != '#' &&
                        (dist[k][l] == -1 || dist[k][l] > dist[i][j] + 1)) {
                        if (isupper(matrix[k][l])) {
                            if (usedPortals.find(matrix[k][l]) == usedPortals.end()) {
                                q.push({k, l});
                                usedPortals.insert(matrix[k][l]);
                            }
                        } else {
                            q.push({k, l});
                        }
                        dist[k][l] = dist[i][j] + 1;
                    }
                }
            }
        }

        return -1;
    }
};