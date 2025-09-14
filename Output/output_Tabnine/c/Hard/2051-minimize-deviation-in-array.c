/**https://leetcode.com/problems/minimize-deviation-in-array/ */
//You are given an array nums of n positive integers.
//You can perform two types of operations on any element of the array any number of times:
//	If the element is even, divide it by 2.
//	
//		For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
//	
//	
//	If the element is odd, multiply it by 2.
//	
//		For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
//	
//	
//The deviation of the array is the maximum difference between any two elements in the array.
//Return the minimum deviation the array can have after performing some number of operations.
// 
//Example 1:
//Input: nums = [1,2,3,4]
//Output: 1
//Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
//Example 2:
//Input: nums = [4,1,5,20,3]
//Output: 3
//Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
//Example 3:
//Input: nums = [2,10,8]
//Output: 3
// 
//Constraints:
//	n == nums.length
//	2 <= n <= 5 * 104
//	1 <= nums[i] <= 109
int minimumDeviation(int* nums, int numsSize) {
    int n = numsSize;
    int* even = (int*)malloc(n * sizeof(int));
    int* odd = (int*)malloc(n * sizeof(int));
    int minEven = INT_MAX, minOdd = INT_MAX;
    int maxEven = INT_MIN, maxOdd = INT_MIN;
    int sumEven = 0, sumOdd = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) {
            even[i] = nums[i] / 2;
            sumEven += even[i];
            minEven = min(minEven, even[i]);
            maxEven = max(maxEven, even[i]);
        } else {
            odd[i] = nums[i] * 2;
            sumOdd += odd[i];
            minOdd = min(minOdd, odd[i]);
            maxOdd = max(maxOdd, odd[i]);
        }
    }
    int ans = maxOdd - minEven;
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) {
            ans = min(ans, max(maxOdd - even[i], even[i] - minEven));
        } else {
            ans = min(ans, max(maxEven - odd[i], odd[i] - minOdd));
        }
    }
    free(even);
    free(odd);
    return ans;
}