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
    char s[12];
    sprintf(s, "%d", num);
    int len = strlen(s);
    int max = -1, maxIndex = -1, leftIndex = -1, rightIndex = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] > max) {
            max = s[i];
            maxIndex = i;
        } else if (s[i] < max) {
            leftIndex = i;
            rightIndex = maxIndex;
        }
    }
    if (leftIndex == -1) {
        return num;
    }
    char temp = s[leftIndex];
    s[leftIndex] = s[rightIndex];
    s[rightIndex] = temp;
    return atoi(s);    
}