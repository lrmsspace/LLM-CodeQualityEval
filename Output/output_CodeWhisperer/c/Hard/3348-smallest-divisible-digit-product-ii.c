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
    int count[10] = {0};
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        count[num[i] - '0']++;
    }
    long long product = 1;
    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            product *= i;
        }
    }
    while (product % t != 0) {
        product *= 2;
        if (product > 1e18) {
            char* result = (char*)malloc(2 * sizeof(char));
            result[0] = '-';
            result[1] = '1';
            return result;
        }
    }
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;
    for (int i = 2; i <= 9; i++) {
        while (count[i] > 0) {
            result[index++] = i + '0';
            count[i]--;
        }
    }
    result[index] = '\0';
    return result;    
}