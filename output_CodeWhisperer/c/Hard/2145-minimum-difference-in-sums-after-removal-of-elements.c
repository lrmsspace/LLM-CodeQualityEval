/**https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/ */
//You are given a 0-indexed integer array nums consisting of 3 * n elements.
//You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:
//	The first n elements belonging to the first part and their sum is sumfirst.
//	The next n elements belonging to the second part and their sum is sumsecond.
//The difference in sums of the two parts is denoted as sumfirst - sumsecond.
//	For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
//	Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
//Return the minimum difference possible between the sums of the two parts after the removal of n elements.
// 
//Example 1:
//Input: nums = [3,1,2]
//Output: -1
//Explanation: Here, nums has 3 elements, so n = 1. 
//Thus we have to remove 1 element from nums and divide the array into two equal parts.
//- If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
//- If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
//- If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
//The minimum difference between sums of the two parts is min(-1,1,2) = -1. 
//Example 2:
//Input: nums = [7,9,5,8,1,3]
//Output: 1
//Explanation: Here n = 2. So we must remove 2 elements and divide the remaining array into two parts containing two elements each.
//If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
//To obtain the minimum difference, we should remove nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in sums of the two parts is (7+5) - (8+3) = 1.
//It can be shown that it is not possible to obtain a difference smaller than 1.
// 
//Constraints:
//	nums.length == 3 * n
//	1 <= n <= 105
//	1 <= nums[i] <= 105
long long minimumDifference(int* nums, int numsSize) {
    int n = numsSize / 3;
    int* minHeap = (int*)malloc(n * sizeof(int));
    int minHeapSize = 0;

    int* maxHeap = (int*)malloc(n * sizeof(int));
    int* sumFirst = (int*)malloc((n + 1) * sizeof(int));
    int* sumSecond = (int*)malloc((n + 1) * sizeof(int));
    int i, j;

    for (i = 0; i < n; i++) {
        sumFirst[i] = nums[i];
        sumSecond[i] = nums[2 * n + i];
    }

    sumFirst[n] = 0;

    for (i = 2 * n - 1; i >= n; i--) {
        sumSecond[n] += nums[i];
    }

    for (i = n - 1; i >= 0; i--) {
        sumFirst[i] += sumFirst[i + 1];
        sumSecond[i] += sumSecond[i + 1];
    }

    int* minDiff = (int*)malloc((n + 1) * sizeof(int));

    for (i = 0; i <= n; i++) {
        minDiff[i] = sumFirst[i] - sumSecond[i];
    }
    int minDiffValue = minDiff[0];

    for (i = 0; i < numsSize; i++) {
        int index = nums[i];
        int* temp = (int*)malloc((n + 1) * sizeof(int));
        int tempSize = 0;

        for (j = 0; j <= n; j++) {
            if (j != index) {
                temp[tempSize++] = minDiff[j];
            }
        }

        for (j = tempSize / 2 - 1; j >= 0; j--) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int smallest = j;

            if (left < tempSize && temp[left] < temp[smallest]) {
                smallest = left;
            }

            if (right < tempSize && temp[right] < temp[smallest]) {
                smallest = right;
            }

            if (smallest != j) {
                int swap = temp[j];
                temp[j] = temp[smallest];
                temp[smallest] = swap;
            }
        }

        minDiffValue = temp[0];

        for (j = 0; j < tempSize; j++) {
            if (temp[j] < minDiffValue) {
                minDiffValue = temp[j];
            }
        }

        free(temp);
    }


    free(minHeap);
    free(maxHeap);

    free(sumFirst);

    free(sumSecond);

    free(minDiff);

    return minDiffValue;
}