/**https://leetcode.com/problems/jump-game-iv/ */
//Given an array of integers arr, you are initially positioned at the first index of the array.
//In one step you can jump from index i to index:
//	i + 1 where: i + 1 < arr.length.
//	i - 1 where: i - 1 >= 0.
//	j where: arr[i] == arr[j] and i != j.
//Return the minimum number of steps to reach the last index of the array.
//Notice that you can not jump outside of the array at any time.
// 
//Example 1:
//Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
//Output: 3
//Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
//Example 2:
//Input: arr = [7]
//Output: 0
//Explanation: Start index is the last index. You do not need to jump.
//Example 3:
//Input: arr = [7,6,9,6,9,6,9,7]
//Output: 1
//Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
// 
//Constraints:
//	1 <= arr.length <= 5 * 104
//	-108 <= arr[i] <= 108
int minJumps(int* arr, int arrSize) {
    int* dp = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    int* map = (int*)malloc(200001 * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        map[arr[i] + 100000]++;
    }
    int* next = (int*)malloc(arrSize * sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        next[i] = i + 1;
    }
    for (int i = 0; i < arrSize; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            next[i] = i - 1;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            dp[i] = fmin(dp[i], dp[i - 1] + 1);
            next[i] = i - 1;
        }
        if (i + 1 < arrSize) {
            dp[i + 1] = fmin(dp[i + 1], dp[i] + 1);
            next[i + 1] = i;
        }
        if (map[arr[i] + 100000] > 1) {
            for (int j = next[i]; j < arrSize; j = next[j]) {
                if (j != i && arr[j] == arr[i]) {
                    dp[j] = fmin(dp[j], dp[i] + 1);
                    next[j] = i;
                }
            }
        }
    }
    int result = dp[arrSize - 1];
    free(dp);
    free(map);
    free(next);
    return result;    
}