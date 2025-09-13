/**https://leetcode.com/problems/number-of-equivalent-domino-pairs/ */
//Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
//Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
// 
//Example 1:
//Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
//Output: 1
//Example 2:
//Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
//Output: 3
// 
//Constraints:
//	1 <= dominoes.length <= 4 * 104
//	dominoes[i].length == 2
//	1 <= dominoes[i][j] <= 9
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int count[10][10] = {0}, res = 0;
    for (int i = 0; i < dominoesSize; ++i) {
        ++count[dominoes[i][0]][dominoes[i][1]];
    }
    for (int i = 0; i <= 9; ++i)
        for (int j = 0; j <= i; ++j)
            if (count[i][j] > 1)
                res += (count[i][j] - 1) * count[i][j] / 2;
    return res;
}