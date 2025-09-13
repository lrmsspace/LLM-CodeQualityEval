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
        while (i < start.length() && j < result.length()) {
            if (start.charAt(i) == result.charAt(j)) {
                i++;
                j++;
            } else if (start.charAt(i) == 'X') {
                i++;
            } else if (result.charAt(j) == 'X') {
                j++;
            } else if (start.charAt(i) == 'L' && result.charAt(j) == 'R') {
                i++;
                j++;
            } else if (start.charAt(i) == 'R' && result.charAt(j) == 'L') {
                i++;
                j++;
            } else {
                return false;
            }
        }
        return i == start.length() && j == result.length();
        
    }
}