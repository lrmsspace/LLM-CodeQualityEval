/**https://leetcode.com/problems/basic-calculator-iv/ */
//Given an expression such as expression = "e + 8 - a + 5" and an evaluation map such as {"e": 1} (given in terms of evalvars = ["e"] and evalints = [1]), return a list of tokens representing the simplified expression, such as ["-1*a","14"]
//	An expression alternates chunks and symbols, with a space separating each chunk and symbol.
//	A chunk is either an expression in parentheses, a variable, or a non-negative integer.
//	A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like "2x" or "-x".
//Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction.
//	For example, expression = "1 + 2 * 3" has an answer of ["7"].
//The format of the output is as follows:
//	For each term of free variables with a non-zero coefficient, we write the free variables within a term in sorted order lexicographically.
//	
//		For example, we would never write a term like "b*a*c", only "a*b*c".
//	
//	
//	Terms have degrees equal to the number of free variables being multiplied, counting multiplicity. We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
//	
//		For example, "a*a*b*c" has degree 4.
//	
//	
//	The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.) A leading coefficient of 1 is still printed.
//	An example of a well-formatted answer is ["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"].
//	Terms (including constant terms) with coefficient 0 are not included.
//	
//		For example, an expression of "0" has an output of [].
//	
//	
//Note: You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
// 
//Example 1:
//Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
//Output: ["-1*a","14"]
//Example 2:
//Input: expression = "e - 8 + temperature - pressure", evalvars = ["e", "temperature"], evalints = [1, 12]
//Output: ["-1*pressure","5"]
//Example 3:
//Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
//Output: ["1*e*e","-64"]
// 
//Constraints:
//	1 <= expression.length <= 250
//	expression consists of lowercase English letters, digits, '+', '-', '*', '(', ')', ' '.
//	expression does not contain any leading or trailing spaces.
//	All the tokens in expression are separated by a single space.
//	0 <= evalvars.length <= 100
//	1 <= evalvars[i].length <= 20
//	evalvars[i] consists of lowercase English letters.
//	evalints.length == evalvars.length
//	-100 <= evalints[i] <= 100  
class Solution {
    public:
        // Class to represent a term in the expression
        class Term {
        public:
            int coefficient;
            vector<string> variables;
            
            Term(int coef = 0, vector<string> vars = {}) : coefficient(coef), variables(vars) {
                sort(variables.begin(), variables.end());
            }
            
            // Compare terms by degree (number of variables) and then lexicographically
            bool operator<(const Term& other) const {
                if (variables.size() != other.variables.size()) {
                    return variables.size() > other.variables.size(); // Higher degree first
                }
                return variables < other.variables; // Lexicographic order
            }
            
            // Check if two terms have the same variables
            bool sameVars(const Term& other) const {
                return variables == other.variables;
            }
            
            // Convert term to string format
            string toString() const {
                if (coefficient == 0) return "";
                
                string result = to_string(coefficient);
                for (const string& var : variables) {
                    result += "*" + var;
                }
                return result;
            }
        };
        
        vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
            // Create evaluation map
            unordered_map<string, int> evalMap;
            for (int i = 0; i < evalvars.size(); i++) {
                evalMap[evalvars[i]] = evalints[i];
            }
            
            // Parse and evaluate the expression
            int pos = 0;
            vector<Term> result = parseExpr(expression, pos, evalMap);
            
            // Sort terms by degree and lexicographically
            sort(result.begin(), result.end());
            
            // Convert to output format
            vector<string> output;
            for (const Term& term : result) {
                if (term.coefficient != 0) {
                    output.push_back(term.toString());
                }
            }
            
            return output;
        }
        
    private:
        // Parse and evaluate an expression
        vector<Term> parseExpr(const string& expr, int& pos, const unordered_map<string, int>& evalMap) {
            vector<Term> result;
            vector<Term> current;
            char op = '+';
            
            while (pos < expr.size()) {
                if (expr[pos] == ' ') {
                    pos++;
                    continue;
                }
                
                if (expr[pos] == '(') {
                    pos++; // Skip '('
                    current = parseExpr(expr, pos, evalMap);
                } else if (expr[pos] == ')') {
                    pos++; // Skip ')'
                    break;
                } else if (isdigit(expr[pos])) {
                    current = {Term(parseNum(expr, pos))};
                } else if (isalpha(expr[pos])) {
                    string var = parseVar(expr, pos);
                    if (evalMap.count(var)) {
                        current = {Term(evalMap.at(var))};
                    } else {
                        current = {Term(1, {var})};
                    }
                } else {
                    op = expr[pos++];
                    continue;
                }
                
                // Apply operation
                if (op == '+') {
                    result = add(result, current);
                } else if (op == '-') {
                    for (Term& term : current) {
                        term.coefficient = -term.coefficient;
                    }
                    result = add(result, current);
                } else if (op == '*') {
                    result = multiply(result, current);
                }
                
                op = '+'; // Reset operation
            }
            
            return result;
        }
        
        // Parse a number
        int parseNum(const string& expr, int& pos) {
            int num = 0;
            while (pos < expr.size() && isdigit(expr[pos])) {
                num = num * 10 + (expr[pos++] - '0');
            }
            return num;
        }
        
        // Parse a variable
        string parseVar(const string& expr, int& pos) {
            string var;
            while (pos < expr.size() && isalpha(expr[pos])) {
                var += expr[pos++];
            }
            return var;
        }
        
        // Add two expressions
        vector<Term> add(const vector<Term>& expr1, const vector<Term>& expr2) {
            if (expr1.empty()) return expr2;
            if (expr2.empty()) return expr1;
            
            vector<Term> result = expr1;
            for (const Term& term : expr2) {
                bool found = false;
                for (Term& existing : result) {
                    if (existing.sameVars(term)) {
                        existing.coefficient += term.coefficient;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    result.push_back(term);
                }
            }
            
            // Remove terms with zero coefficient
            result.erase(remove_if(result.begin(), result.end(), 
                                  [](const Term& t) { return t.coefficient == 0; }), 
                        result.end());
            
            return result;
        }
        
        // Multiply two expressions
        vector<Term> multiply(const vector<Term>& expr1, const vector<Term>& expr2) {
            if (expr1.empty() || expr2.empty()) return {};
            
            vector<Term> result;
            for (const Term& term1 : expr1) {
                for (const Term& term2 : expr2) {
                    Term newTerm(term1.coefficient * term2.coefficient);
                    newTerm.variables = term1.variables;
                    newTerm.variables.insert(newTerm.variables.end(), term2.variables.begin(), term2.variables.end());
                    sort(newTerm.variables.begin(), newTerm.variables.end());
                    
                    bool found = false;
                    for (Term& existing : result) {
                        if (existing.sameVars(newTerm)) {
                            existing.coefficient += newTerm.coefficient;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        result.push_back(newTerm);
                    }
                }
            }
            
            // Remove terms with zero coefficient
            result.erase(remove_if(result.begin(), result.end(), 
                                  [](const Term& t) { return t.coefficient == 0; }), 
                        result.end());
            
            return result;
        }
    };
    