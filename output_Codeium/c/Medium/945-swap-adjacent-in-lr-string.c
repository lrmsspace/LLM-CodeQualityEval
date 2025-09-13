/**https://leetcode.com/problems/swap-adjacent-in-lr-string/ */
//In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string result, return True if and only if there exists a sequence of moves to transform start to result.
// 
//Example 1:
//Input: start = "RXXLRXRXL", result = "XRLXXRRLX"
//Output: true
//Explanation: We can transform start to result following these steps:
//RXXLRXRXL ->
//XRXLRXRXL ->
//XRLXRXRXL ->
//XRLXXRRXL ->
//XRLXXRRLX
//Example 2:
//Input: start = "X", result = "L"
//Output: false
// 
//Constraints:
//	1 <= start.length <= 104
//	start.length == result.length
//	Both start and result will only consist of characters in 'L', 'R', and 'X'.
bool canTransform(char* start, char* result) {
int i = 0, j = 0;
int n = strlen(start);

// Traverse both strings
while (i < n && j < n) {

    // Skip X in both strings
    while (i < n && start[i] == 'X') i++;
    while (j < n && result[j] == 'X') j++;

    // If one reaches the end and the other doesn't
    if ((i < n) != (j < n)) return false;

    // If both characters are different
    if (i < n && j < n && start[i] != result[j]) return false;

    // Check L and R positions
    if (i < n && j < n) {
        if (start[i] == 'L' && i < j) return false;
        if (start[i] == 'R' && i > j) return false;
    }

    i++;
    j++;
}

return true;

}