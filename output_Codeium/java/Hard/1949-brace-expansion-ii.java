/**https://leetcode.com/problems/brace-expansion-ii/ */
//Under the grammar given below, strings can represent a set of lowercase words. Let R(expr) denote the set of words the expression represents.
//The grammar can best be understood through simple examples:
//	Single letters represent a singleton set containing that word.
//	
//		R("a") = {"a"}
//		R("w") = {"w"}
//	
//	
//	When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
//	
//		R("{a,b,c}") = {"a","b","c"}
//		R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
//	
//	
//	When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
//	
//		R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
//		R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
//	
//	
//Formally, the three rules for our grammar:
//	For every lowercase letter x, we have R(x) = {x}.
//	For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...
//	For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}, where + denotes concatenation, and × denotes the cartesian product.
//Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.
// 
//Example 1:
//Input: expression = "{a,b}{c,{d,e}}"
//Output: ["ac","ad","ae","bc","bd","be"]
//Example 2:
//Input: expression = "{{a,z},a{b,c},{ab,z}}"
//Output: ["a","ab","ac","z"]
//Explanation: Each distinct word is written only once in the final answer.
// 
//Constraints:
//	1 <= expression.length <= 60
//	expression[i] consists of '{', '}', ','or lowercase English letters.
//	The given expression represents a set of words based on the grammar given in the description.
class Solution {
    public List<String> braceExpansionII(String expression) {
        List<String> res = new ArrayList<>();
        if (expression == null || expression.length() == 0) return res;
        Stack<List<String>> stack = new Stack<>();
        stack.push(new ArrayList<>());
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '{') {
                stack.push(new ArrayList<>());
            } else if (c == '}') {
                List<String> curr = stack.pop();
                List<String> prev = stack.peek();
                for (String s1 : prev) {
                    for (String s2 : curr) {
                        prev.add(s1 + s2);
                    }
                }
            } else if (c == ',') {
                continue;
            } else {
                List<String> curr = stack.peek();
                curr.add(String.valueOf(c));
            }
        }
        Collections.sort(stack.peek());
        return stack.peek();
    }
}