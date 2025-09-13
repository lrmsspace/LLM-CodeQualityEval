/**https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/ */
//A cell (r, c) of an excel sheet is represented as a string "<col><row>" where:
//	<col> denotes the column number c of the cell. It is represented by alphabetical letters.
//	
//		For example, the 1st column is denoted by 'A', the 2nd by 'B', the 3rd by 'C', and so on.
//	
//	
//	<row> is the row number r of the cell. The rth row is represented by the integer r.
//You are given a string s in the format "<col1><row1>:<col2><row2>", where <col1> represents the column c1, <row1> represents the row r1, <col2> represents the column c2, and <row2> represents the row r2, such that r1 <= r2 and c1 <= c2.
//Return the list of cells (x, y) such that r1 <= x <= r2 and c1 <= y <= c2. The cells should be represented as strings in the format mentioned above and be sorted in non-decreasing order first by columns and then by rows.
// 
//Example 1:
//Input: s = "K1:L2"
//Output: ["K1","K2","L1","L2"]
//Explanation:
//The above diagram shows the cells which should be present in the list.
//The red arrows denote the order in which the cells should be presented.
//Example 2:
//Input: s = "A1:F1"
//Output: ["A1","B1","C1","D1","E1","F1"]
//Explanation:
//The above diagram shows the cells which should be present in the list.
//The red arrow denotes the order in which the cells should be presented.
// 
//Constraints:
//	s.length == 5
//	'A' <= s[0] <= s[3] <= 'Z'
//	'1' <= s[1] <= s[4] <= '9'
//	s consists of uppercase English letters, digits and ':'.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** cellsInRange(char * s, int* returnSize){
    int start_col = s[0] - 'A' + 1;
    int end_col = s[3] - 'A' + 1;
    int start_row = s[1] - '0';
    int end_row = s[4] - '0';
    int row_size = end_row - start_row + 1;
    int col_size = end_col - start_col + 1;
    int total_size = row_size * col_size;
    char ** result = malloc(total_size * sizeof(char *));
    int index = 0;
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_col; j <= end_col; j++) {
            char * cell = malloc(3 * sizeof(char));
            cell[0] = j + 'A' - 1;
            cell[1] = i +'0';
        }
    }
    *returnSize = total_size;
    return result;
}