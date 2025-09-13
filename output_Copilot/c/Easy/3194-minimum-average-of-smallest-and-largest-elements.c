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
    double averages[numsSize / 2];
    int index = 0;

    while (numsSize > 0) {
        // Find the minimum and maximum elements
        int minIndex = 0, maxIndex = 0;
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Calculate the average of the min and max elements
        averages[index++] = (nums[minIndex] + nums[maxIndex]) / 2.0;

        // Remove the min and max elements from the array
        if (minIndex > maxIndex) {
            int temp = minIndex;
            minIndex = maxIndex;
            maxIndex = temp;
        }
        
        for (int i = maxIndex; i < numsSize - 1; i++) {
            nums[i] = nums[i + 1];
        }
        numsSize--;

        for (int i = minIndex; i < numsSize - 1; i++) {
            nums[i] = nums[i + 1];
        }
        numsSize--;
    }

    // Find the minimum average
    double minAverage = averages[0];
    for (int i = 1; i < index; i++) {
        if (averages[i] < minAverage) {
            minAverage = averages[i];
        }
    }

    return minAverage;
    
}