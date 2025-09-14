/*
 You are given a string num which represents a positive integer, and an integer t.
 A number is called zero-free if none of its digits are 0.
 Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".
 Example 1:
 Input: num = "1234", t = 256
 Output: "1488"
 Explanation:
 The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
 Example 2:
 Input: num = "12355", t = 50
 Output: "12355"
 Explanation:
 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.
 Example 3:
 Input: num = "11111", t = 26
 Output: "-1"
 Explanation:
 No number greater than 11111 has the product of its digits divisible by 26.
 Constraints:
 2 <= num.length <= 2 * 105
 num consists only of digits in the range ['0', '9'].
 num does not contain leading zeros.
 1 <= t <= 1014
*/

char* smallestNumber(char* num, long long t) {
    int n = strlen(num);
    long long product = 1;
    for (int i = 0; i < n; i++) {
        if (num[i] == '0') return "-1"; // Contains zero, not zero-free
        product *= num[i] - '0';
    }

    if (product % t == 0) return num; // Already zero-free and divisible by t

    // Try to find the smallest number greater than num
    for (int i = n - 1; i >= 0; i--) {
        for (char d = num[i] + 1; d <= '9'; d++) {
            long long new_product = product / (num[i] - '0') * (d - '0');
            if (new_product % t == 0) {
                num[i] = d;
                for (int j = i + 1; j < n; j++) {
                    num[j] = '1'; // Fill with smallest digit
                }
                return num;
            }
        }
        product /= (num[i] - '0');
    }

    return "-1"; // No valid number found    
}