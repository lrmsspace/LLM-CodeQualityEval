/**https://leetcode.com/problems/russian-doll-envelopes/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.
// 
//Example 1:
//Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
//Output: 3
//Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//Example 2:
//Input: envelopes = [[1,1],[1,1],[1,1]]
//Output: 1
// 
//Constraints:
//	1 <= envelopes.length <= 105
//	envelopes[i].length == 2
//	1 <= wi, hi <= 105
int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    // Sort the envelopes by width in descending order and height in ascending order
    qsort(envelopes, envelopesSize, sizeof(int *), compareEnvelopes);
    
    // Initialize an array to store the heights of the envelopes
    int* heights = (int*)malloc(envelopesSize * sizeof(int));
    heights[0] = envelopes[0][1];
    
    // Initialize the result variable
    int result = 1;
    
    // Iterate through the sorted envelopes

    for (int i = 1; i < envelopesSize; i++) {
        // If the current envelope's height is greater than the height of the last envelope, update the heights array
        if (envelopes[i][1] > heights[result - 1]) {
            heights[result++] = envelopes[i][1];
        } else {
            // Binary search to find the correct position to insert the current envelope's height into the heights array
            int left = 0, right = result - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (heights[mid] < envelopes[i][1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            heights[left] = envelopes[i][1];
        }
    }
    
    // Free the allocated memory
    free(heights);
    
    // Return the maximum number of envelopes that can be Russian doll
    return result;
    
}