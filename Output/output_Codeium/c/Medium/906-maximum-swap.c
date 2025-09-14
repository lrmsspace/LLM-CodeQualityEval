/**https://leetcode.com/problems/maximum-swap/ */
//You are given an integer num. You can swap two digits at most once to get the maximum valued number.
//Return the maximum valued number you can get.
// 
//Example 1:
//Input: num = 2736
//Output: 7236
//Explanation: Swap the number 2 and the number 7.
//Example 2:
//Input: num = 9973
//Output: 9973
//Explanation: No swap.
// 
//Constraints:
//	0 <= num <= 108
int maximumSwap(int num) {
    char num_str[10];
    sprintf(num_str, "%d", num);
    int n = strlen(num_str);
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (num_str[i] < num_str[j]) {
                char temp = num_str[i];
                num_str[i] = num_str[j];
                num_str[j] = temp;
                int result = 0;
                for (int k = 0; k < n; ++k) {
                    result = result * 10 + (num_str[k] - '0');
                }
                return result;
            }
        }
    }
    return num;
}