/**https://leetcode.com/problems/queens-that-can-attack-the-king/ */
//On a 0-indexed 8 x 8 chessboard, there can be multiple black queens and one white king.
//You are given a 2D integer array queens where queens[i] = [xQueeni, yQueeni] represents the position of the ith black queen on the chessboard. You are also given an integer array king of length 2 where king = [xKing, yKing] represents the position of the white king.
//Return the coordinates of the black queens that can directly attack the king. You may return the answer in any order.
// 
//Example 1:
//Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
//Output: [[0,1],[1,0],[3,3]]
//Explanation: The diagram above shows the three queens that can directly attack the king and the three queens that cannot attack the king (i.e., marked with red dashes).
//Example 2:
//Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
//Output: [[2,2],[3,4],[4,4]]
//Explanation: The diagram above shows the three queens that can directly attack the king and the three queens that cannot attack the king (i.e., marked with red dashes).
// 
//Constraints:
//	1 <= queens.length < 64
//	queens[i].length == king.length == 2
//	0 <= xQueeni, yQueeni, xKing, yKing < 8
//	All the given positions are unique.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** queensAttacktheKing(int** queens, int queensSize, int* queensColSize, int* king, int kingSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * queensSize);
    int count = 0;
    for (int i = 0; i < queensSize; i++) {
        if (queens[i][0] == king[0] || queens[i][1] == king[1] || queens[i][0] - king[0] == queens[i][1] - king[1] || queens[i][0] + queens[i][1] == king[0] + king[1]) {
            result[count] = (int*)malloc(sizeof(int) * 2);
            result[count][0] = queens[i][0];
            result[count][1] = queens[i][1];
            count++;
        }
    }
    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}