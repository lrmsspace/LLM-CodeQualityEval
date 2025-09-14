/**https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/ */
//Given the following details of a matrix with n columns and 2 rows :
//	The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
//	The sum of elements of the 0-th(upper) row is given as upper.
//	The sum of elements of the 1-st(lower) row is given as lower.
//	The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
//Your task is to reconstruct the matrix with upper, lower and colsum.
//Return it as a 2-D integer array.
//If there are more than one valid solution, any of them will be accepted.
//If no valid solution exists, return an empty 2-D array.
// 
//Example 1:
//Input: upper = 2, lower = 1, colsum = [1,1,1]
//Output: [[1,1,0],[0,0,1]]
//Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.
//Example 2:
//Input: upper = 2, lower = 3, colsum = [2,2,1,1]
//Output: []
//Example 3:
//Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
//Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
// 
//Constraints:
//	1 <= colsum.length <= 10^5
//	0 <= upper, lower <= colsum.length
//	0 <= colsum[i] <= 2
class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        List<List<Integer>> res = new ArrayList<>();
        int n = colsum.length;
        int sum = upper + lower;
        if (sum!= 2 * n || upper > lower) return res;
        
        int[] row = new int[n];
        row[0] = upper;
        row[n - 1] = lower;
        
        int sumCol = upper + lower;
        int left = n - 2;
        
        for (int i = 1; i < n - 1; i++) {
            if (sumCol < colsum[i] * 2) {
                row[i] = 0;
                sumCol += colsum[i];
            } else {
                row[i] = 1;
                sumCol -= colsum[i];
                left--;
            }
        }
        
        if (sumCol!= 0) return res;
        
        res.add(Arrays.asList(row));

        row = new int[n];
        row[0] = 1;
        row[n - 1] = 1;
        for (int i = 1; i < n - 1; i++) {
            row[i] = 0;
        }
        res.add(Arrays.asList(row));
        
        return res;
        
    }
}