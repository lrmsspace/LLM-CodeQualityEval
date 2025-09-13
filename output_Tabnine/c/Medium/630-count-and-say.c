/**https://leetcode.com/problems/count-and-say/ */
//The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
//	countAndSay(1) = "1"
//	countAndSay(n) is the run-length encoding of countAndSay(n - 1).
//Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
//Given a positive integer n, return the nth element of the count-and-say sequence.
// 
//Example 1:
//Input: n = 4
//Output: "1211"
//Explanation:
//countAndSay(1) = "1"
//countAndSay(2) = RLE of "1" = "11"
//countAndSay(3) = RLE of "11" = "21"
//countAndSay(4) = RLE of "21" = "1211"
//Example 2:
//Input: n = 1
//Output: "1"
//Explanation:
//This is the base case.
// 
//Constraints:
//	1 <= n <= 30
// 
//Follow up: Could you solve it iteratively?
char* countAndSay(int n) {
    if (n <= 0) return "";
    if (n == 1) return "1";
    
    char* prev = countAndSay(n - 1);
    int len = strlen(prev);
    char* result = (char*)malloc(len * 2 + 1);
    result[len * 2] = '\0';
    int i = 0, j = 0;
    
    while (i < len) {
        int count = 1;
        while (i + 1 < len && prev[i] == prev[i + 1]) {
            count++;
            i++;
        }
        result[j++] = '0' + count;
        result[j++] = prev[i++];
    }
    
    free(prev);
    return result;
    
}