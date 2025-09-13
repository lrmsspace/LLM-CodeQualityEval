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
    int digits[10] = {0};
    int parity[10] = {0};
    int count = 0;
    while (num > 0) {
        int digit = num % 10;
        digits[count] = digit;
        parity[count] = digit % 2;
        count++;
        num /= 10;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (digits[j] < digits[j + 1]) {
                int temp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = temp;
                temp = parity[j];
                parity[j] = parity[j + 1];
                parity[j + 1] = temp;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < count; i++) {
        result = result * 10 + digits[i];
    }
    return result;
    
}