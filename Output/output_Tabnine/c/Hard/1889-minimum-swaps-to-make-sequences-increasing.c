/**https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/ */
//You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
//	For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
//Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.
//An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].
// 
//Example 1:
//Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
//Output: 1
//Explanation: 
//Swap nums1[3] and nums2[3]. Then the sequences are:
//nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
//which are both strictly increasing.
//Example 2:
//Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
//Output: 1
// 
//Constraints:
//	2 <= nums1.length <= 105
//	nums2.length == nums1.length
//	0 <= nums1[i], nums2[i] <= 2 * 105
int minSwap(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;
    int* dp = (int*)malloc(sizeof(int) * n);
    int* prev = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; ++i) {
        dp[i] = i;
        prev[i] = -1;
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums1[i] > nums1[j] && nums2[i] > nums2[j]) {
                int t = dp[j] + 1;
                if (t < dp[i]) {
                    dp[i] = t;
                    prev[i] = j;
                }
            }
        }
    }
    
    int minSwaps = dp[n - 1];
    int* path = (int*)malloc(sizeof(int) * minSwaps);
    int k = n - 1;
    for (int i = 0; i < minSwaps; ++i) {
        path[i] = k;
        k = prev[k];
    }
    
    for (int i = 0; i < minSwaps / 2; ++i) {
        int t = path[i];
        path[i] = path[minSwaps - 1 - i];
        path[minSwaps - 1 - i] = t;
    }
    
    free(dp);
    free(prev);
    return minSwaps;
    
}