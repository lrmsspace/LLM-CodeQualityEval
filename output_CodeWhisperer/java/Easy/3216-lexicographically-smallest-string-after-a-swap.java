/*
 Given a string s containing only digits, return the lexicographically smallest string that can be obtained after swapping adjacent digits in s with the same parity at most once.
 Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.
 Example 1:
 Input: s = "45320"
 Output: "43520"
 Explanation: 
 s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.
 Example 2:
 Input: s = "001"
 Output: "001"
 Explanation:
 There is no need to perform a swap because s is already the lexicographically smallest.
 Constraints:
 2 <= s.length <= 100
 s consists only of digits.
*/

class Solution {
    public String getSmallestString(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        for(int i = 0; i < n; i++){
            int min = arr[i] - '0';
            int minIndex = i;
            for(int j = i + 1; j < n; j++){
                if((arr[j] - '0') % 2 == arr[i] % 2 && arr[j] - '0' < min){
                    min = arr[j] - '0';
                    minIndex = j;
                }
            }
            if(minIndex != i){
                char temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
                return new String(arr);
            }
        }
        return new String(arr);        
    }
}