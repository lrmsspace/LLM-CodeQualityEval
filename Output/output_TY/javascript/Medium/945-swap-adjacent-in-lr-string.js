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
/**
 * @param {string} start
 * @param {string} result
 * @return {boolean}
 */
var canTransform = function(start, result) {
    var startL = start.split('L');
    var resultL = result.split('L');
    var startR = start.split('R');
    var resultR = result.split('R');
    
    if(startL.length !== resultL.length || startR.length !== resultR.length) return false;
    
    for(var i = 0; i < startL.length; i++){
        if(startL[i].length !== resultL[i].length) return false;
        if(startL[i].length > 0 && startL[i].charAt(startL[i].length - 1) !== 'X') return false;
    }
    
   for(var i = 0; i < startR.length; i++)
    {
        if(startR[i].length !== resultR[i].length) return false;
        if(startR[i].length > 0 && startR[i].charAt(0) !== 'X') return false;
    }
    
    return true;
};