/*
 Given an integer array hours representing times in hours, return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.
 A complete day is defined as a time duration that is an exact multiple of 24 hours.
 For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.
 Example 1:
 Input: hours = [12,12,30,24,24]
 Output: 2
 Explanation: The pairs of indices that form a complete day are (0, 1) and (3, 4).
 Example 2:
 Input: hours = [72,48,24,3]
 Output: 3
 Explanation: The pairs of indices that form a complete day are (0, 1), (0, 2), and (1, 2).
 Constraints:
 1 <= hours.length <= 5 * 105
 1 <= hours[i] <= 109
*/

long long countCompleteDayPairs(int* hours, int hoursSize) {
    // Sort the hours array in non-decreasing order
    qsort(hours, hoursSize, sizeof(int), compare);
    
    // Initialize variables
    long long count = 0;
    int left = 0;
    int right = hoursSize - 1;
    
    // Iterate through the sorted hours array
    while (left < right) {
        // Check if the sum of the current hours forms a complete day
        if (hours[left] + hours[right] == 24) {
            // Increment the count and move the pointers
            count++;
            left++;
            right--;
        } else if (hours[left] + hours[right] < 24) {
            // Move the left pointer to the right
            left++;
        } else {
            // Move the right pointer to the left
            right--;
        }
    }
    
    // Return the count of complete day pairs
    return count;
    
}