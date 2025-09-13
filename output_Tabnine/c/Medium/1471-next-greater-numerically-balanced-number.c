/**https://leetcode.com/problems/next-greater-numerically-balanced-number/ */
//An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
//Given an integer n, return the smallest numerically balanced number strictly greater than n.
// 
//Example 1:
//Input: n = 1
//Output: 22
//Explanation: 
//22 is numerically balanced since:
//- The digit 2 occurs 2 times. 
//It is also the smallest numerically balanced number strictly greater than 1.
//Example 2:
//Input: n = 1000
//Output: 1333
//Explanation: 
//1333 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times. 
//It is also the smallest numerically balanced number strictly greater than 1000.
//Note that 1022 cannot be the answer because 0 appeared more than 0 times.
//Example 3:
//Input: n = 3000
//Output: 3133
//Explanation: 
//3133 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times.
//It is also the smallest numerically balanced number strictly greater than 3000.
// 
//Constraints:
//	0 <= n <= 106
int nextBeautifulNumber(int n) {

    // Convert the number to a string for easier manipulation
    string num = to_string(n);
    int nLength = num.length();
    int i = nLength - 1;
    // Find the first digit that is less than the next digit
    while (i > 0 && num[i] <= num[i - 1]) {
        i--;
    }
    // If no such digit exists, then n is the smallest numerically balanced number
    if (i == 0) {
        return n + 1;
    }
    // Find the first digit greater than the digit at index i
    int j = nLength - 1;
    while (j > i && num[j] <= num[i]) {
        j--;
    }
    // Swap the digits at index i and j
    swap(num[i], num[j]);
    // Reverse the digits after index i
    reverse(num.begin() + i + 1, num.end());
    // Convert the string back to an integer
    return stoi(num);
}