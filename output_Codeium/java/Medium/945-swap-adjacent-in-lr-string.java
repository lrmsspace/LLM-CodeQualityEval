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
class Solution {
    public boolean canTransform(String start, String result) {
    int i = 0, j = 0;
    int len = start.length();
    while (i < len && j < len) {
        while (i < len && start.charAt(i) == 'X') i++;
        while (j < len && result.charAt(j) == 'X') j++;
        if (i < len && j < len) {
            if (start.charAt(i) != result.charAt(j)) return false;
            if (start.charAt(i) == 'L' && i < j) return false;
            if (start.charAt(i) == 'R' && i > j) return false;
            i++;
            j++;
        }   
    }
    while (i < len) {
        if (start.charAt(i) != 'X') return false;
        i++;
    }
    while (j < len) {
        if (result.charAt(j) != 'X') return false;
        j++;
    }
    return true;
    }
}