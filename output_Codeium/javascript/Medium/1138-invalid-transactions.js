/**https://leetcode.com/problems/invalid-transactions/ */
//A transaction is possibly invalid if:
//	the amount exceeds $1000, or;
//	if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
//You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
//Return a list of transactions that are possibly invalid. You may return the answer in any order.
// 
//Example 1:
//Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
//Output: ["alice,20,800,mtv","alice,50,100,beijing"]
//Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
//Example 2:
//Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
//Output: ["alice,50,1200,mtv"]
//Example 3:
//Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
//Output: ["bob,50,1200,mtv"]
// 
//Constraints:
//	transactions.length <= 1000
//	Each transactions[i] takes the form "{name},{time},{amount},{city}"
//	Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
//	Each {time} consist of digits, and represent an integer between 0 and 1000.
//	Each {amount} consist of digits, and represent an integer between 0 and 2000.
/**
 * @param {string[]} transactions
 * @return {string[]}
 */
var invalidTransactions = function(transactions) {
    const invalid = [];
    const map = {};
    transactions.forEach(transaction => {
        const [name, time, amount, city] = transaction.split(',');
        if (Number(amount) > 1000) {
            invalid.push(transaction);
        }
        if (!map[name]) {
            map[name] = [];
        }
        map[name].push(transaction);
    });
    Object.keys(map).forEach(name => {
        const transactionsByName = map[name];
        for (let i = 0; i < transactionsByName.length; i++) {
            const [_, time1, _, city1] = transactionsByName[i].split(',');
            for (let j = 0; j < transactionsByName.length; j++) {
                if (i !== j) {
                    const [__, time2, _, city2] = transactionsByName[j].split(',');
                    if (Math.abs(Number(time1) - Number(time2)) <= 60 && city1 !== city2) {
                        if (!invalid.includes(transactionsByName[i])) {
                            invalid.push(transactionsByName[i]);
                        }
                    }
                }
            }
        }
    });
    return invalid;
};