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
char* maximumBinaryString(char* binary) {
    int n = strlen(binary);
    int count0 = 0, count1 = 0;
    for (int i = 0; i < n; i++) {
        if (binary[i] == '0') count0++;
        else count1++;
    }
    
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';
    
    if (count0 > count1) {
        for (int i = 0; i < n; i++) {
            result[i] = '1';
        }
        result[n - 1] = '0';
    } else {
        result[0] = '1';
        for (int i = 1; i < n; i++) {
            result[i] = binary[i - 1];
        }
    }
    
    return result;
    
}