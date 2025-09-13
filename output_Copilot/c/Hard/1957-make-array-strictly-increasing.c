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
        // Comparison function for qsort
        int compare(const void* a, const void* b) {
            return (*(int*)a - *(int*)b);
        }

        int makeArrayIncreasing(int* arr1, int arr1Size, int* arr2, int arr2Size) {
            // Sort arr2 and remove duplicates
            qsort(arr2, arr2Size, sizeof(int), compare);
            int* uniqueArr2 = (int*)malloc(arr2Size * sizeof(int));
            int uniqueSize = 0;
            for (int i = 0; i < arr2Size; i++) {
                if (i == 0 || arr2[i] != arr2[i - 1]) {
                    uniqueArr2[uniqueSize++] = arr2[i];
                }
            }

            // Dynamic programming table
            int** dp = (int**)malloc((arr1Size + 1) * sizeof(int*));
            for (int i = 0; i <= arr1Size; i++) {
                dp[i] = (int*)malloc((uniqueSize + 1) * sizeof(int));
                for (int j = 0; j <= uniqueSize; j++) {
                    dp[i][j] = INT_MAX;
                }
            }

            dp[0][0] = INT_MIN;

            for (int i = 1; i <= arr1Size; i++) {
                for (int j = 0; j <= uniqueSize; j++) {
                    if (dp[i - 1][j] != INT_MAX) {
                        // Keep arr1[i-1]
                        if (arr1[i - 1] > dp[i - 1][j]) {
                            dp[i][j] = arr1[i - 1];
                        }
                        // Replace arr1[i-1] with an element from arr2
                        for (int k = j; k < uniqueSize; k++) {
                            if (uniqueArr2[k] > dp[i - 1][j]) {
                                dp[i][k + 1] = uniqueArr2[k];
                                break;
                            }
                        }
                    }
                }
            }

            // Find the minimum operations
            int result = INT_MAX;
            for (int j = 0; j <= uniqueSize; j++) {
                if (dp[arr1Size][j] != INT_MAX) {
                    result = j;
                    break;
                }
            }

            // Free memory
            for (int i = 0; i <= arr1Size; i++) {
                free(dp[i]);
            }
            free(dp);
            free(uniqueArr2);

            return result == INT_MAX ? -1 : result;
        }
        