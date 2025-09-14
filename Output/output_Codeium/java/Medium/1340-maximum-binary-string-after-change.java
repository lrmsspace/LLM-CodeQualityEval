/**https://leetcode.com/problems/maximum-binary-string-after-change/ */
//You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:
//	Operation 1: If the number contains the substring "00", you can replace it with "10".
//	
//		For example, "00010" -> "10010"
//	
//	
//	Operation 2: If the number contains the substring "10", you can replace it with "01".
//	
//		For example, "00010" -> "00001"
//	
//	
//Return the maximum binary string you can obtain after any number of operations. Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.
// 
//Example 1:
//Input: binary = "000110"
//Output: "111011"
//Explanation: A valid transformation sequence can be:
//"000110" -> "000101" 
//"000101" -> "100101" 
//"100101" -> "110101" 
//"110101" -> "110011" 
//"110011" -> "111011"
//Example 2:
//Input: binary = "01"
//Output: "01"
//Explanation: "01" cannot be transformed any further.
// 
//Constraints:
//	1 <= binary.length <= 105
//	binary consist of '0' and '1'.
class Solution {
    public String maximumBinaryString(String binary) {
int zeroCount = 0;
int oneCount = 0;

// Count the number of 0's and 1's
for (char c : binary.toCharArray()) {
    if (c == '0') {
        zeroCount++;
    } else {
        oneCount++;
    }
}

// If there are no 0's or all are 1's, return the original binary
if (zeroCount == 0 || zeroCount == binary.length()) {
    return binary;
}

// The result will have all 1's except for a single '0' in between
// the 1's that originally appeared before the first '0'.
int firstZeroIndex = binary.indexOf('0');
StringBuilder result = new StringBuilder();
for (int i = 0; i < binary.length(); i++) {
    if (i < firstZeroIndex || i >= firstZeroIndex + zeroCount - 1) {
        result.append('1');
    } else {
        result.append('0');
    }
}
return result.toString();
    }
}