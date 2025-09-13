/**https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/ */
//Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
// 
//Example 1:
//Input: arr = [5,5,4], k = 1
//Output: 1
//Explanation: Remove the single 4, only 5 is left.
//Example 2:
//Input: arr = [4,3,1,1,3,3,2], k = 3
//Output: 2
//Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
// 
//Constraints:
//	1 <= arr.length <= 10^5
//	1 <= arr[i] <= 10^9
//	0 <= k <= arr.length
int findLeastNumOfUniqueInts(int* arr, int arrSize, int k){

    int count[1000001] = {0};
    for (int i = 0; i < arrSize; i++)
        count[arr[i]]++;
    int ans = 0, sum = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (count[i] > 0) {
            sum += count[i];
            if (sum <= k)
                ans++;
        }
    }
    return ans;

}