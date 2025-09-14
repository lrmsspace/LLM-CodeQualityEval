/**https://leetcode.com/problems/sum-of-matrix-after-queries/ */
//You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].
//Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:
//	if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
//	if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.
//Return the sum of integers in the matrix after all queries are applied.
// 
//Example 1:
//Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
//Output: 23
//Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 
//Example 2:
//Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
//Output: 17
//Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.
// 
//Constraints:
//	1 <= n <= 104
//	1 <= queries.length <= 5 * 104
//	queries[i].length == 3
//	0 <= typei <= 1
//	0 <= indexi < n
//	0 <= vali <= 105
long long matrixSumQueries(int n, int** queries, int queriesSize, int* queriesColSize) {
    long long sum = 0;
    int* rows = (int*)calloc(n, sizeof(int));
    int* cols = (int*)calloc(n, sizeof(int));
    for (int i = queriesSize - 1; i >= 0; i--) {
        int type = queries[i][0];
        int index = queries[i][1];
        int val = queries[i][2];
        if (type == 0) {
            if (rows[index] == 0) {
                rows[index] = 1;
                sum += (long long)val * (n - cols[index]);
            }
        } else {
            if (cols[index] == 0) {
                cols[index] = 1;
                sum += (long long)val * (n - rows[index]);
            }
        }
    }
    free(rows);
    free(cols);
    return sum;
}