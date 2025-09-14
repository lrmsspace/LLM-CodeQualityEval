/**https://leetcode.com/problems/maximum-profit-in-job-scheduling/ */
//We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
//You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
//If you choose a job that ends at time X you will be able to start another job that starts at time X.
// 
//Example 1:
//Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
//Output: 120
//Explanation: The subset chosen is the first and fourth job. 
//Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
//Example 2:
// 
//Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
//Output: 150
//Explanation: The subset chosen is the first, fourth and fifth job. 
//Profit obtained 150 = 20 + 70 + 60.
//Example 3:
//Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
//Output: 6
// 
//Constraints:
//	1 <= startTime.length == endTime.length == profit.length <= 5 * 104
//	1 <= startTime[i] < endTime[i] <= 109
//	1 <= profit[i] <= 104
int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* arr = (int*)malloc(sizeof(int) * (startTimeSize + 1));
    int* arr2 = (int*)malloc(sizeof(int) * (startTimeSize + 1));
    for (i = 0; i < startTimeSize; i++) {
        arr[i] = startTime[i];
        arr2[i] = endTime[i];
    }
    arr[startTimeSize] = 0;
    arr2[startTimeSize] = 0;
    qsort(arr, startTimeSize + 1, sizeof(int), cmp);
    qsort(arr2, startTimeSize + 1, sizeof(int), cmp);
    int* dp = (int*)malloc(sizeof(int) * (startTimeSize + 1));
    dp[0] = 0;
    for (i = 1; i <= startTimeSize; i++) {
        dp[i] = profit[i - 1] + dp[i - 1];
    }
    for (i = 1; i <= startTimeSize; i++) {
        for (j = 0; j < i; j++) {
            if (arr2[j] <= arr[i]) {
                dp[i] = max(dp[i], dp[j] + profit[i]);
            }
        }
    }
    return dp[startTimeSize];
}