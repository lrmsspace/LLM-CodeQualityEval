/**https://leetcode.com/problems/contains-duplicate/ */
//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// 
//Example 1:
//Input: nums = [1,2,3,1]
//Output: true
//Explanation:
//The element 1 occurs at the indices 0 and 3.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: false
//Explanation:
//All elements are distinct.
//Example 3:
//Input: nums = [1,1,1,3,3,4,3,2,4,2]
//Output: true
// 
//Constraints:
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
bool containsDuplicate(int* nums, int numsSize) {
    // Create a set to store the elements encountered so far
    // If an element is already in the set, it means it has been encountered before
    // Return true immediately
    int* visited = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (visited[nums[i] + 10000]) {
            free(visited);
            return true;
        }
        visited[nums[i] + 10000] = 1;
    }
    free(visited);
    return false;   
}