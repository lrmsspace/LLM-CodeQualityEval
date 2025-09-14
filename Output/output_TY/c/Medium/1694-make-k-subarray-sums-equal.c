/**https://leetcode.com/problems/make-k-subarray-sums-equal/ */
//You are given a 0-indexed integer array arr and an integer k. The array arr is circular. In other words, the first element of the array is the next element of the last element, and the last element of the array is the previous element of the first element.
//You can do the following operation any number of times:
//	Pick any element from arr and increase or decrease it by 1.
//Return the minimum number of operations such that the sum of each subarray of length k is equal.
//A subarray is a contiguous part of the array.
// 
//Example 1:
//Input: arr = [1,4,1,3], k = 2
//Output: 1
//Explanation: we can do one operation on index 1 to make its value equal to 3.
//The array after the operation is [1,3,1,3]
//- Subarray starts at index 0 is [1, 3], and its sum is 4 
//- Subarray starts at index 1 is [3, 1], and its sum is 4 
//- Subarray starts at index 2 is [1, 3], and its sum is 4 
//- Subarray starts at index 3 is [3, 1], and its sum is 4 
//Example 2:
//Input: arr = [2,5,5,7], k = 3
//Output: 5
//Explanation: we can do three operations on index 0 to make its value equal to 5 and two operations on index 3 to make its value equal to 5.
//The array after the operations is [5,5,5,5]
//- Subarray starts at index 0 is [5, 5, 5], and its sum is 15
//- Subarray starts at index 1 is [5, 5, 5], and its sum is 15
//- Subarray starts at index 2 is [5, 5, 5], and its sum is 15
//- Subarray starts at index 3 is [5, 5, 5], and its sum is 15 
// 
//Constraints:
//	1 <= k <= arr.length <= 105
//	1 <= arr[i] <= 109
long long makeSubKSumEqual(int* arr, int arrSize, int k){
    int i, j, l, r, m, n, t, sum, minSum;
    int *cnt = (int*)malloc(sizeof(int) * 1000001);
    for (i = 0; i < arrSize; i++) {
        cnt[arr[i]]++;
    }
    for (i = 0; i < 1000001; i++) {
        if (cnt[i] > 0) {
            sum = 0;
            for (j = i; j <= 1000000; j += i) {
                sum += cnt[j];
            }
            if (sum >= k) {
                minSum = i;
                break;
            }
        }
}
    for (i = 0; i < arrSize; i++) {
        t = arr[i] - minSum;
        if (t < 0) {
            t = -t;
        }
        sum += t;
    }
    while (sum > k) {
        for (i = 0; i < 1000001; i++) {
            if (cnt[i] > 0) {
                sum -= cnt[i];
                cnt[i] = 0;
                break;
            }
        }
    }
    for (i = 0; i < arrSize; i++) {
        t = arr[i] - minSum;
        if (t < 0) {
            t = -t;
        }
        if (t % k == 0) {
            sum += t / k;
        }
        else {
            sum += t / k + 1;
        }
    }
    return sum;
}