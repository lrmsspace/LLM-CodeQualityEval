/**https://leetcode.com/problems/fizz-buzz/ */
//Given an integer n, return a string array answer (1-indexed) where:
//	answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
//	answer[i] == "Fizz" if i is divisible by 3.
//	answer[i] == "Buzz" if i is divisible by 5.
//	answer[i] == i (as a string) if none of the above conditions are true.
// 
//Example 1:
//Input: n = 3
//Output: ["1","2","Fizz"]
//Example 2:
//Input: n = 5
//Output: ["1","2","Fizz","4","Buzz"]
//Example 3:
//Input: n = 15
//Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
// 
//Constraints:
//	1 <= n <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * n);
    *returnSize = n;
    for (int i = 0; i < n; i++) {
        int num = i + 1;
        if (num % 3 == 0 && num % 5 == 0) {
            result[i] = (char*)malloc(sizeof(char) * 9);
            strcpy(result[i], "FizzBuzz");
        } else if (num % 3 == 0) {
            result[i] = (char*)malloc(sizeof(char) * 5);
            strcpy(result[i], "Fizz");
        } else if (num % 5 == 0) {
            result[i] = (char*)malloc(sizeof(char) * 5);
            strcpy(result[i], "Buzz");
        } else {
            result[i] = (char*)malloc(sizeof(char) * 2);
            sprintf(result[i], "%d", num);
        }
    }
    return result;
    
}