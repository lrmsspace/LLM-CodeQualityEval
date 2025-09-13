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
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char **ans = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        ans[i] = (char *)malloc(15 * sizeof(char));
    }
    int i = 1;
    for (int j = 0; j < n; j++) {
        if (i % 3 == 0 && i % 5 == 0) {
           strcpy(ans[j], "FizzBuzz");
        }
    }
    return ans;
}