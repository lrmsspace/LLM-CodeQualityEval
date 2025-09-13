/**https://leetcode.com/problems/pyramid-transition-matrix/ */
//You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.
//To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.
//	For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
//You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.
//Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.
// 
//Example 1:
//Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
//Output: true
//Explanation: The allowed triangular patterns are shown on the right.
//Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
//There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
//Example 2:
//Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
//Output: false
//Explanation: The allowed triangular patterns are shown on the right.
//Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
// 
//Constraints:
//	2 <= bottom.length <= 6
//	0 <= allowed.length <= 216
//	allowed[i].length == 3
//	The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
//	All the values of allowed are unique.
bool pyramidTransition(char* bottom, char** allowed, int allowedSize) {
        
        // Check if a character is an operator
        int isOperator(char c) {
            return c == '+' || c == '-' || c == '*';
        }
        
        // Calculate the result of an expression
        int calculate(int a, int b, char op) {
            if (op == '+') {
                return a + b;
            } else if (op == '-') {
                return a - b;
            } else if (op == '*') {
                return a * b;
            }
            return 0;
        }
        
        // Backtracking function to find all possible results
        void backtrack(char* expression, int start, int end, int** result, int* returnSize, int* returnColumnSizes, int* path, int pathIndex) {
            if (start == end) {
                result[*returnSize] = (int*)malloc(pathIndex * sizeof(int));
                returnColumnSizes[*returnSize] = pathIndex;
                for (int i = 0; i < pathIndex; i++) {
                    result[*returnSize][i] = path[i];
                }
                (*returnSize)++;
                return;
            }
            for (int i = start; i <= end; i++) {
                if (isOperator(expression[i])) {
                    path[pathIndex] = calculate(path[pathIndex - 1], path[pathIndex + 1], expression[i]);
                    backtrack(expression, i + 1, end, result, returnSize, returnColumnSizes, path, pathIndex + 1);
                }
            }
        }
        
        // Initialize variables
        int** result = (int**)malloc(1000 * sizeof(int*));
        int* returnColumnSizes = (int*)malloc(1000 * sizeof(int));
        int returnSize = 0;
        int* path = (int*)malloc(1000 * sizeof(int));
        
        // Find all possible results
        backtrack(bottom, 0, strlen(bottom) - 1, result, &returnSize, returnColumnSizes, path, 0);
        
        // Return result
        return returnSize; 
}