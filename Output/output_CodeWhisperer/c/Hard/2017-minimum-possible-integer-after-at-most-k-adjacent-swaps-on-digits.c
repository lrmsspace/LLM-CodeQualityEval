/**https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/ */
//You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.
//Return the minimum integer you can obtain also as a string.
// 
//Example 1:
//Input: num = "4321", k = 4
//Output: "1342"
//Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
//Example 2:
//Input: num = "100", k = 1
//Output: "010"
//Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
//Example 3:
//Input: num = "36789", k = 1000
//Output: "36789"
//Explanation: We can keep the number without any swaps.
// 
//Constraints:
//	1 <= num.length <= 3 * 104
//	num consists of only digits and does not contain leading zeros.
//	1 <= k <= 109
char* minInteger(char* num, int k) {
    int len = strlen(num);
    char* res = (char*)malloc((len + 1) * sizeof(char));
    int* pos = (int*)malloc(10 * sizeof(int));
    int* next = (int*)malloc(len * sizeof(int));
    int* stack = (int*)malloc(len * sizeof(int));
    int top = -1;
    for (int i = 0; i < 10; i++) {
        pos[i] = -1;
    }
    for (int i = len - 1; i >= 0; i--) {
        next[i] = pos[num[i] - '0'];
        pos[num[i] - '0'] = i;
    }
    for (int i = 0; i < len; i++) {
        while (top >= 0 && stack[top] > next[stack[top]] && k > stack[top] - i) {
            int index = stack[top--];
            char temp = num[index];
            num[index] = num[i];
            num[i] = temp;
            k -= index - i;
            for (int j = 0; j < 10; j++) {
                if (pos[j] >= index) {
                    pos[j]--;
                }
            }
        }
        stack[++top] = i;
    }
    strcpy(res, num);
    return res;
}