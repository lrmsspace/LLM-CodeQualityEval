/**https://leetcode.com/problems/mini-parser/ */
//Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.
//Each element is either an integer or a list whose elements may also be integers or other lists.
// 
//Example 1:
//Input: s = "324"
//Output: 324
//Explanation: You should return a NestedInteger object which contains a single integer 324.
//Example 2:
//Input: s = "[123,[456,[789]]]"
//Output: [123,[456,[789]]]
//Explanation: Return a NestedInteger object containing a nested list with 2 elements:
//1. An integer containing value 123.
//2. A nested list containing two elements:
//    i.  An integer containing value 456.
//    ii. A nested list with one element:
//         a. An integer containing value 789
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	s consists of digits, square brackets "[]", negative sign '-', and commas ','.
//	s is the serialization of valid NestedInteger.
//	All the values in the input are in the range [-106, 106].
/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */
struct NestedInteger* deserialize(char * s){
    int i, j, sign, num;
    struct NestedInteger *res = malloc(sizeof(struct NestedInteger));
    NestedIntegerInit(res);
    for (i = 0; s[i] == ' '; i++);
    if (s[i] == '[') {
        i++;
        while (s[i] != ']') {
            struct NestedInteger *tmp = deserialize(s + i);
            NestedIntegerAdd(res, tmp);
            i += strlen(s + i);
        }
    } else {
        sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
    }
    while (isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
        i++;
    }
    NestedIntegerSetInteger(res, num * sign);
    return res;
}