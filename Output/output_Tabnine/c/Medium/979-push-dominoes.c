/**https://leetcode.com/problems/push-dominoes/ */
//There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
//After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
//When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
//For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
//You are given a string dominoes representing the initial state where:
//	dominoes[i] = 'L', if the ith domino has been pushed to the left,
//	dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//	dominoes[i] = '.', if the ith domino has not been pushed.
//Return a string representing the final state.
// 
//Example 1:
//Input: dominoes = "RR.L"
//Output: "RR.L"
//Explanation: The first domino expends no additional force on the second domino.
//Example 2:
//Input: dominoes = ".L.R...LR..L.."
//Output: "LL.RR.LLRRLL.."
// 
//Constraints:
//	n == dominoes.length
//	1 <= n <= 105
//	dominoes[i] is either 'L', 'R', or '.'.
char* pushDominoes(char* dominoes) {
    int n = strlen(dominoes);
    char* result = (char*)malloc((n + 1) * sizeof(char));
    memcpy(result, dominoes, n + 1);
    
    int left = 0, right = n - 1;
    while (left <= right) {
        if (result[left] == 'R') {
            left++;
        } else if (result[left] == 'L') {
            int i = left + 1;
            while (i <= right && result[i] == '.') {
                result[i] = 'L';
                i++;
            }
            left = i;
        } else {
            int i = left + 1;
            while (i <= right && result[i] == '.') {
                result[i] = 'R';
                i++;
            }
            left = i;
        }
    }
    
    left = 0, right = n - 1;
    while (left <= right) {
        if (result[right] == 'L') {
            right--;
        } else if (result[right] == 'R') {
            int i = right - 1;
            while (i >= left && result[i] == '.') {
                result[i] = 'R';
                i--;
            }
            right = i;
        } else {
            int i = right - 1;
            while (i >= left && result[i] == '.') {
                result[i] = 'L';
                i--;
            }
            right = i;
        }
    }
    
    result[n] = '\0';
    return result;
    
}