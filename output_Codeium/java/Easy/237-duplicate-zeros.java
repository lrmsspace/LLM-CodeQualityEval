/**https://leetcode.com/problems/duplicate-zeros/ */
//Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
//Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
// 
//Example 1:
//Input: arr = [1,0,2,3,0,4,5,0]
//Output: [1,0,0,2,3,0,0,4]
//Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
//Example 2:
//Input: arr = [1,2,3]
//Output: [1,2,3]
//Explanation: After calling your function, the input array is modified to: [1,2,3]
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 9
class Solution {
    public void duplicateZeros(int[] arr) {
        int possibleDups = 0;
        int length_ = arr.length - 1;

        // Step 1. Count the zeros
        for (int i = 0; i <= length_; i++) {

            // Stop when left points beyond the array boundary
            if (i > length_ - possibleDups) {
                break;

            }

            // Count the zeros
            if (arr[i] == 0) {

                // Edge case: This zero can't be duplicated. We have no more space,
                // as indicated by `possibleDups` being 0.
                if (i == length_ - possibleDups) {
                    arr[length_] = 0;
                    length_ -= 1;
                    possibleDups -= 1;
                }

                // Count the zeros
                possibleDups += 1;
            }
        }

        // Step 2. Start backwards and duplicate every element until
        // no more zeros left to duplicate
        int lastNonZeroFinder = length_;
        for (int i = length_ - 1; i >= 0; i--) {

            // Check if the current value is not zero
            if (arr[lastNonZeroFinder - possibleDups] != 0) {
                arr[lastNonZeroFinder] = arr[lastNonZeroFinder - possibleDups];
                lastNonZeroFinder -= 1;
                possibleDups -= 1;
            } else {
                arr[lastNonZeroFinder] = 0;
                lastNonZeroFinder -= 1;
                possibleDups -= 1;

                // Everything behind this including and after
                // this current index has been processed
                arr[lastNonZeroFinder] = 0;
                lastNonZeroFinder -= 1;
            }
        }
    }
}