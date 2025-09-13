/**https://leetcode.com/problems/make-array-strictly-increasing/ */
//Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
//In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
//If there is no way to make arr1 strictly increasing, return -1.
// 
//Example 1:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
//Output: 1
//Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
//Example 2:
//Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
//Output: 2
//Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
//Example 3:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
//Output: -1
//Explanation: You can't make arr1 strictly increasing.
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 2000
//	0 <= arr1[i], arr2[i] <= 10^9
// 


int makeArrayIncreasing(int* arr1, int arr1Size, int* arr2, int arr2Size){
    int i, j, k;
    for (i = 0; i < arr2Size; i++) {
        for (j = 0; j < i; j++) {
            if (arr2[j] >= arr2[i]) {
                for (k = i; k > j; k--) {
                    arr2[k] = arr2[k - 1];
                }
                arr2[j] = arr2[i];
                arr2[i] = arr2[j];
            }
        }
    }
    arr2Size = i;
    int dp[arr1Size + 1][arr2Size + 1];
    for (i = 0; i <= arr1Size; i++) {
        for (j = 0; j <= arr2Size; j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (i = 0; i < arr1Size; i++) {
        for (j = 0; j <= arr2Size; j++) {
            if (dp[i][j] >= 0) {
                if (j < arr2Size && arr2[j] < arr1[i]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
               if (i > 0 && arr1[i] > arr1[i - 1]) {
                   dp[i + 1][j] = dp[i][j];
               }
            }
        }
    }
    for (i = 0; i <= arr2Size; i++) {
        if (dp[arr1Size][i] >= 0) {
            return dp[arr1Size][i];
        }
    }
    return -1;
}