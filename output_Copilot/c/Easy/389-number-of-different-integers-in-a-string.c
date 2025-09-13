/**https://leetcode.com/problems/number-of-different-integers-in-a-string/ */
//You are given a string word that consists of digits and lowercase English letters.
//You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left with some integers that are separated by at least one space: "123", "34", "8", and "34".
//Return the number of different integers after performing the replacement operations on word.
//Two integers are considered different if their decimal representations without any leading zeros are different.
// 
//Example 1:
//Input: word = "a123bc34d8ef34"
//Output: 3
//Explanation: The three different integers are "123", "34", and "8". Notice that "34" is only counted once.
//Example 2:
//Input: word = "leet1234code234"
//Output: 2
//Example 3:
//Input: word = "a1b01c001"
//Output: 1
//Explanation: The three integers "1", "01", and "001" all represent the same integer because
//the leading zeros are ignored when comparing their decimal values.
// 
//Constraints:
//	1 <= word.length <= 1000
//	word consists of digits and lowercase English letters.
int numDifferentIntegers(char* word) {
    int i = 0;
    int len = strlen(word);
    int count = 0;
    int *num = (int *)malloc(sizeof(int) * len);
    memset(num, 0, sizeof(int) * len);
    while (i < len) {
        if (word[i] >= '0' && word[i] <= '9') {
            int j = i;
            while (j < len && word[j] >= '0' && word[j] <= '9') {
                j++;
            }
            int k = i;
            while (k < j && word[k] == '0') {
                k++;
            }
            if (k == j) {
                num[count++] = 0;
            } else {
                int n = 0;
                while (k < j) {
                    n = n * 10 + word[k] - '0';
                    k++;
                }
                num[count++] = n;
            }
            i = j;
        } else {
            i++;
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (num[i] > num[j]) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < count; i++) {
        if (i == 0 || num[i] != num[i - 1]) {
            result++;
        }
    }
    free(num);
    return result;    
}