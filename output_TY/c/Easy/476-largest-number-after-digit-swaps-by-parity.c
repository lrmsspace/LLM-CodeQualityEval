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
int largestInteger(int num){
    int n = num;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int o = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    int s = 0;
    int t = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    while (n > 0){
        if (n % 10 == 0){
            z = n % 10;
            n = n / 10;
        }
        else if (n % 10 == 1){
            y = n % 10;
            n = n / 10;
        }
        else if (n % 10 == 2){
            x = n % 10;
            n = n / 10;
        }
    }
    while (num > 0){
        if (num % 10 == 0){
            w = num % 10;
            num = num / 10;
        }
        else if (num % 10 == 1){
            v = num % 10;
            num = num / 10;
        }
        else if (num % 10 == 2){
            u = num % 10;
            num = num / 10;
        }
    }
    while (n > 0){
        if (n % 10 == 0){
            t = n % 10;
            n = n / 10;
        }
        else if (n % 10 == 1){
            s = n % 10;
            n = n / 10;
        }
        else if (n % 10 == 2){
            r = n % 10;
            n = n / 10;
        }
    }
    while (num > 0){
        if (num % 10 == 0){
            q = num % 10;
            num = num / 10;
        }
        else if (num % 10 == 1){
            p = num % 10;
            num = num / 10;
        }
        else if (num % 10 == 2){
            o = num % 10;
            num = num / 10;
        }
    }
    while (n > 0){
        if (n % 10 == 0){
            m = n % 10;
            n = n / 10;
        }
        else if (n % 10 == 1){
            l = n % 10;
            n = n / 10;
        }
        else if (n % 10 == 2){
            k = n % 10;
            n = n / 10;
        }
    }
    while (num > 0){
        if (num % 10 == 0){
            j = num % 10;
            num = num / 10;
        }
        else if (num % 10 == 1){
            i = num % 10;
            num = num / 10;
        }
    }
    return (z * 100000000) + (y * 10000000) + (x * 1000000) + (w * 100000) + (v * 10000) + (u * 1000) + (t * 100) + (s * 10) + (r * 1);
}