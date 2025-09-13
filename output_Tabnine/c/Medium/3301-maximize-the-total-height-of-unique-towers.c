/*
 You are given an array maximumHeight, where maximumHeight[i] denotes the maximum height the ith tower can be assigned.
 Your task is to assign a height to each tower so that:
 The height of the ith tower is a positive integer and does not exceed maximumHeight[i].
 No two towers have the same height.
 Return the maximum possible total sum of the tower heights. If it's not possible to assign heights, return -1.
 Example 1:
 Input: maximumHeight = [2,3,4,3]
 Output: 10
 Explanation:
 We can assign heights in the following way: [1, 2, 4, 3].
 Example 2:
 Input: maximumHeight = [15,10]
 Output: 25
 Explanation:
 We can assign heights in the following way: [15, 10].
 Example 3:
 Input: maximumHeight = [2,2,1]
 Output: -1
 Explanation:
 It's impossible to assign positive heights to each index so that no two towers have the same height.
 Constraints:
 1 <= maximumHeight.length <= 105
 1 <= maximumHeight[i] <= 109
*/

long long maximumTotalSum(int* maximumHeight, int maximumHeightSize) {

    // Sort the maximumHeight array in descending order
    qsort(maximumHeight, maximumHeightSize, sizeof(int), compare);
    
    // Initialize the prefix sum array
    long long prefixSum[maximumHeightSize];
    prefixSum[0] = maximumHeight[0];
    for (int i = 1; i < maximumHeightSize; i++) {
        prefixSum[i] = prefixSum[i - 1] + maximumHeight[i];
    }
    
    // Initialize the maximum total sum
    long long maxTotalSum = 0;
    // Iterate through the maximumHeight array  
    for (int i = 0; i < maximumHeightSize; i++) {
        // Find the maximum prefix sum that is less than or equal to the current maximumHeight
        int left = 0;
        int right = i;
        int maxPrefixSum = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] <= maximumHeight[i]) {
                maxPrefixSum = prefixSum[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Update the maximum total sum
        maxTotalSum = max(maxTotalSum, maxPrefixSum + maximumHeight[i]);
    }
    
    // Return the maximum total sum
    return maxTotalSum; 
    
}