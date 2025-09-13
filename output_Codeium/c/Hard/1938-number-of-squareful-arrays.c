/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
// 
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 12
//	0 <= nums[i] <= 109

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dfs(int* nums, int numsSize, int index, int* res, bool* visited) {
    if (index == numsSize) {
        (*res)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (visited[i] || (index > 0 && nums[i] == nums[index - 1] && !visited[i - 1])) {
            continue;
        }
        if (index > 0 && sqrt((double)(nums[index - 1] + nums[i])) != (int)sqrt((double)(nums[index - 1] + nums[i]))) {
            continue;
        }
        visited[i] = true;
        swap(&nums[index], &nums[i]);
        dfs(nums, numsSize, index + 1, res, visited);
        swap(&nums[index], &nums[i]);
        visited[i] = false;
    }
}   

int numSquarefulPerms(int* nums, int numsSize) {
    int res = 0;
    bool* visited = (bool*)malloc(numsSize * sizeof(bool));
    memset(visited, false, numsSize * sizeof(bool));
    dfs(nums, numsSize, 0, &res, visited);
    free(visited);
    return res;
}