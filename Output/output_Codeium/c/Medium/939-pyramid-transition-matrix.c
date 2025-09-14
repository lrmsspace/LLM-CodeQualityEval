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
    int dp[7][7][7] = {0};
    for (int i = 0; i < allowedSize; ++i) {
        int a = allowed[i][0] - 'A';
        int b = allowed[i][1] - 'A';
        int c = allowed[i][2] - 'A';
        dp[a][b] |= 1 << c;
    }
    int n = strlen(bottom);
    for (int i = n - 1; i > 0; --i) {
        int m = (n + i - 1) / i;
        char* next = (char*)malloc((m + 1) * sizeof(char));
        for (int j = 0; j < m; ++j) {
            int a = bottom[j * 2] - 'A';
            int b = bottom[j * 2 + 1] - 'A';
            next[j] = (dp[a][b] > 0) ? 'A' + (__builtin_ctz(dp[a][b]) % 7) : 'A';
        }
        next[m] = '\0';
        free(bottom);
        bottom = next;
    }
    return dp[bottom[0] - 'A'][bottom[1] - 'A'] > 0;
}