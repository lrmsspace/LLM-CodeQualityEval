/*
 You are given an integer array nums. Your task is to remove all elements from the array by performing one of the following operations at each step until nums is empty:
 Choose any two elements from the first three elements of nums and remove them. The cost of this operation is the maximum of the two elements removed.
 If fewer than three elements remain in nums, remove all the remaining elements in a single operation. The cost of this operation is the maximum of the remaining elements.
 Return the minimum cost required to remove all the elements.
 Example 1:
 Input: nums = [6,2,8,4]
 Output: 12
 Explanation:
 Initially, nums = [6, 2, 8, 4].
 In the first operation, remove nums[0] = 6 and nums[2] = 8 with a cost of max(6, 8) = 8. Now, nums = [2, 4].
 In the second operation, remove the remaining elements with a cost of max(2, 4) = 4.
 The cost to remove all elements is 8 + 4 = 12. This is the minimum cost to remove all elements in nums. Hence, the output is 12.
 Example 2:
 Input: nums = [2,1,3,3]
 Output: 5
 Explanation:
 Initially, nums = [2, 1, 3, 3].
 In the first operation, remove nums[0] = 2 and nums[1] = 1 with a cost of max(2, 1) = 2. Now, nums = [3, 3].
 In the second operation remove the remaining elements with a cost of max(3, 3) = 3.
 The cost to remove all elements is 2 + 3 = 5. This is the minimum cost to remove all elements in nums. Hence, the output is 5.
 Constraints:
 1 <= nums.length <= 1000
 1 <= nums[i] <= 106
*/
int minCost(int* nums, int numsSize) {
    int cost = 0;

    while (numsSize > 0) {
        int max1 = INT_MIN, max2 = INT_MIN;

        // Find the two maximum elements in the first three elements
        for (int i = 0; i < 3 && i < numsSize; i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }

        // Remove the two maximum elements and add their maximum value to the cost
        cost += max1 > max2 ? max1 : max2;

        // Remove the remaining elements if there are fewer than three elements left
        if (numsSize <= 3) {
            numsSize = 0;
        } else {
            numsSize -= 3;
            nums += 3;
        }
    }

    return cost;
}