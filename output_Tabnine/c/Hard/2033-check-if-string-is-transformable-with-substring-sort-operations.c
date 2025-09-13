/**https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/ */
//Given two strings s and t, transform string s into string t using the following operation any number of times:
//	Choose a non-empty substring in s and sort it in place so the characters are in ascending order.
//	
//		For example, applying the operation on the underlined substring in "14234" results in "12344".
//	
//	
//Return true if it is possible to transform s into t. Otherwise, return false.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "84532", t = "34852"
//Output: true
//Explanation: You can transform s into t using the following sort operations:
//"84532" (from index 2 to 3) -> "84352"
//"84352" (from index 0 to 2) -> "34852"
//Example 2:
//Input: s = "34521", t = "23415"
//Output: true
//Explanation: You can transform s into t using the following sort operations:
//"34521" -> "23451"
//"23451" -> "23415"
//Example 3:
//Input: s = "12345", t = "12435"
//Output: false
// 
//Constraints:
//	s.length == t.length
//	1 <= s.length <= 105
//	s and t consist of only digits.
bool isTransformable(char* s, char* t) {
    int n = strlen(s);
    int count[10] = {0};
    
    //Count the occurrences of digits in s
    for (int i = 0; i < n; ++i) {
        ++count[s[i] - '0'];
    }
    
    //Check if the digits in s and t are in ascending order
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i + 1]) {
            return false;
        }
        if (t[i] > t[i + 1]) {
            return false;
        }
    }
    
    //Find the first digit in s that appears in t
    int first = -1;
    for (int i = 0; i < n; ++i) {
        if (count[t[i] - '0'] > 0) {
            first = i;
            break;
        }
    }
    
    //Iterate over t and try to transform s into t
    for (int i = 0; i < n; ++i) {
        if (t[i] == s[first]) {
            continue;
        }
        
        //Find the first digit in s that can be swapped with t[i]
        int swap = -1;
        for (int j = first + 1; j < n; ++j) {
            if (count[s[j] - '0'] > 0 && s[j] < t[i]) {
                swap = j;
                break;
            }
        }
        
        //If no digit in s can be swapped, return false
        if (swap == -1) {
            return false;
        }
        
        //Swap the digits in s
        char temp = s[first];
        s[first] = s[swap];
        s[swap] = temp;
        
        //Decrement the count of the swapped digit in s
        --count[s[first] - '0'];
        
        //Update the first digit in s
        first = swap;
    }
    
    //All digits in s have been transformed into t, so return true
    return true;
    
}