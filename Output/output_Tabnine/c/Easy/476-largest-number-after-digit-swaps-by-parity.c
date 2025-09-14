/**https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/ */
//You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).
//Return the largest possible value of num after any number of swaps.
// 
//Example 1:
//Input: num = 1234
//Output: 3412
//Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
//Swap the digit 2 with the digit 4, this results in the number 3412.
//Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
//Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
//Example 2:
//Input: num = 65875
//Output: 87655
//Explanation: Swap the digit 8 with the digit 6, this results in the number 85675.
//Swap the first digit 5 with the digit 7, this results in the number 87655.
//Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
// 
//Constraints:
//	1 <= num <= 109
int largestInteger(int num) {
    char arr[10];
    sprintf(arr, "%d", num);
    int n = strlen(arr);
    
    // Find the first pair of adjacent digits with different parities
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] % 2 == 0 && arr[i + 1] % 2!= 0) ||
            (arr[i] % 2!= 0 && arr[i + 1] % 2 == 0)) {
            // Swap the digits
            char temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            break;
        }
    }
    
    // Sort the remaining digits in descending order
    qsort(arr + 2, n - 2, sizeof(char), compare);
    
    // Construct the largest number
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = result * 10 + (arr[i] - '0');
    }
    
    return result;
    
}