/*
 You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
 You repeat the following procedure n / 2 times:
 Remove the smallest element, minElement, and the largest element maxElement, from nums.
 Add (minElement + maxElement) / 2 to averages.
 Return the minimum element in averages.
 Example 1:
 Input: nums = [7,8,3,4,15,13,4,1]
 Output: 5.5
 Explanation:
 step
 nums
 averages
 0
 [7,8,3,4,15,13,4,1]
 []
 1
 [7,8,3,4,13,4]
 [8]
 2
 [7,8,4,4]
 [8,8]
 3
 [7,4]
 [8,8,6]
 4
 []
 [8,8,6,5.5]
 The smallest element of averages, 5.5, is returned.
 Example 2:
 Input: nums = [1,9,8,3,10,5]
 Output: 5.5
 Explanation:
 step
 nums
 averages
 0
 [1,9,8,3,10,5]
 []
 1
 [9,8,3,5]
 [5.5]
 2
 [8,5]
 [5.5,6]
 3
 []
 [5.5,6,6.5]
 Example 3:
 Input: nums = [1,2,3,7,8,9]
 Output: 5.0
 Explanation:
 step
 nums
 averages
 0
 [1,2,3,7,8,9]
 []
 1
 [2,3,7,8]
 [5]
 2
 [3,7]
 [5,5]
 3
 []
 [5,5,5]
 Constraints:
 2 <= n == nums.length <= 50
 n is even.
 1 <= nums[i] <= 50
*/

double minimumAverage(int* nums, int numsSize) {
    int i, j, min, max, temp;
    double sum = 0;
    double *averages = (double*)malloc(numsSize/2*sizeof(double));
    for (i = 0; i < numsSize/2; i++) {
        min = nums[0];
        max = nums[0];
        j = 0;
        while (j < numsSize) {
            if (nums[j] < min) {
                min = nums[j];
            }
            if (nums[j] > max) {
                max = nums[j];
            }
            j++;
        }
        for (j = 0; j < numsSize; j++) {
            if (nums[j] == min) {
                nums[j] = 0;
                break;
            }
        }
        for (j = 0; j < numsSize; j++) {
            if (nums[j] == max) {
                nums[j] = 0;
                break;
            }
        }
        averages[i] = (double)(min + max) / 2;
        numsSize -= 2;
    }
    for (i = 0; i < numsSize/2; i++) {
        min = i;
        for (j = i+1; j < numsSize/2; j++) {
            if (averages[j] < averages[min]) {
                min = j;
            }
        }
        temp = averages[i];
        averages[i] = averages[min];
        averages[min] = temp;
    }
    return averages[numsSize/4];

        
}