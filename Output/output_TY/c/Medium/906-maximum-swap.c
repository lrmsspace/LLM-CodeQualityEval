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
int maximumSwap(int num){
    char *s = malloc(sizeof(char) * 11);
    sprintf(s, "%d", num);
    int n = strlen(s);
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i] < s[j]) {
                char tmp = s[i];
            }
        }
    }
    return atoi(s);
}