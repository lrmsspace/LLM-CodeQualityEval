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
    char numStr[11];
    sprintf(numStr, "%d", num);
    int len = strlen(numStr);
    int maxIdx = len - 1;
    int leftIdx = -1, rightIdx = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (numStr[i] > numStr[maxIdx]) {
            maxIdx = i;
        }
        else if (numStr[i] < numStr[maxIdx]) {
            leftIdx = i;
            rightIdx = maxIdx;
        }
    }
    if (leftIdx == -1) {
        return num;
    }
    else {
        char temp = numStr[leftIdx];
        numStr[leftIdx] = numStr[rightIdx];
        numStr[rightIdx] = temp;
        return atoi(numStr);
    }
}