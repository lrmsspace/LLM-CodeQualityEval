/**https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/ */
//There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.
//You are given an integer array groupSizes, where groupSizes[i] is the size of the group that person i is in. For example, if groupSizes[1] = 3, then person 1 must be in a group of size 3.
//Return a list of groups such that each person i is in a group of size groupSizes[i].
//Each person should appear in exactly one group, and every person must be in a group. If there are multiple answers, return any of them. It is guaranteed that there will be at least one valid solution for the given input.
// 
//Example 1:
//Input: groupSizes = [3,3,3,3,3,1,3]
//Output: [[5],[0,1,2],[3,4,6]]
//Explanation: 
//The first group is [5]. The size is 1, and groupSizes[5] = 1.
//The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
//The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
//Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
//Example 2:
//Input: groupSizes = [2,1,3,3,3,2]
//Output: [[1],[0,5],[2,3,4]]
// 
//Constraints:
//	groupSizes.length == n
//	1 <= n <= 500
//	1 <= groupSizes[i] <= n
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes) {
    // Create a frequency array to count the number of people in each group
    int* freq = (int*)calloc(groupSizesSize, sizeof(int));
    for (int i = 0; i < groupSizesSize; i++) {
        freq[groupSizes[i] - 1]++;
    }
    
    // Create a stack to store the group members
    int** stack = (int**)calloc(groupSizesSize, sizeof(int*));
    int* stackSizes = (int*)calloc(groupSizesSize, sizeof(int));
    
    // Initialize the return array
    *returnSize = groupSizesSize;
    *returnColumnSizes = (int*)calloc(groupSizesSize, sizeof(int));
    int** result = (int**)calloc(groupSizesSize, sizeof(int*));
    
    // Iterate through the frequency array
    for (int i = 0; i < groupSizesSize; i++) {
        (*returnColumnSizes)[i] = freq[i];
        result[i] = (int*)calloc(freq[i], sizeof(int));
        
        // Fill the result array with the group members
        while (stackSizes[i] > 0 && freq[i] > 0) {
            result[i][--stackSizes[i]] = i;
            freq[i]--;
        }
        
        // Push the group members into the stack
        for (int j = i; j < groupSizesSize && freq[j] > 0; j++) {
            stack[stackSizes[j]] = j;
            stackSizes[j]++;
        }
    }
    
    // Free the memory
    free(freq);
    free(stack);
    free(stackSizes);
    
    return result;
    
}