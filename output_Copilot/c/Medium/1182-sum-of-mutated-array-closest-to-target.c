/**https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/ */
//Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.
//In case of a tie, return the minimum such integer.
//Notice that the answer is not neccesarilly a number from arr.
// 
//Example 1:
//Input: arr = [4,9,3], target = 10
//Output: 3
//Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
//Example 2:
//Input: arr = [2,3,5], target = 10
//Output: 5
//Example 3:
//Input: arr = [60864,25176,27249,21296,20204], target = 56803
//Output: 11361
// 
//Constraints:
//	1 <= arr.length <= 104
//	1 <= arr[i], target <= 105
int findBestValue(int* arr, int arrSize, int target) {
    int i, sum = 0, max = 0, min = 0, mid = 0, diff = 0, res = 0;
    for (i = 0; i < arrSize; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    if (sum <= target) {
        return max;
    }
    min = target / arrSize;
    max = max > min ? max : min;
    while (min < max) {
        mid = (min + max) / 2;
        sum = 0;
        for (i = 0; i < arrSize; i++) {
            sum += arr[i] > mid ? mid : arr[i];
        }
        diff = target - sum;
        if (diff > 0) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }
    sum = 0;
    for (i = 0; i < arrSize; i++) {
        sum += arr[i] > min ? min : arr[i];
    }
    if (sum < target) {
        res = min + 1;
    } else {
        res = min;
    }
    return res;    
}