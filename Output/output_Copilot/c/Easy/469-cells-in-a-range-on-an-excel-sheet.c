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
char** cellsInRange(char* s, int* returnSize) {
    char** result = (char**)malloc(100 * sizeof(char*));
    int i = 0, j = 0, k = 0;
    while (s[i] != ':') {
        int col1 = s[i] - 'A' + 1;
        int row1 = s[i + 1] - '0';
        int col2 = s[i + 2] - 'A' + 1;
        int row2 = s[i + 3] - '0';
        for (int r = row1; r <= row2; r++) {
            for (int c = col1; c <= col2; c++) {
                result[k] = (char*)malloc(3 * sizeof(char));
                result[k][0] = c + 'A' - 1;
                result[k][1] = r + '0';
                result[k][2] = '\0';
                k++;
            }
        }
        i += 5;
    }
    *returnSize = k;
    return result;
}