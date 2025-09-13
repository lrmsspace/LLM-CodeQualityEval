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
    const invalid = new Set();
    const transactionsMap = new Map();

    for (const transaction of transactions) {
        const [name, time, amount, city] = transaction.split(',');
        const key = `${name},${city}`;

        if (parseInt(amount) > 1000) {
            invalid.add(transaction);
        }

        if (!transactionsMap.has(key)) {
            transactionsMap.set(key, []);
        }
        transactionsMap.get(key).push({ time: parseInt(time), transaction });
    }

    for (const [key, transList] of transactionsMap.entries()) {
        for (let i = 0; i < transList.length; i++) {
            for (let j = i + 1; j < transList.length; j++) {
                if (Math.abs(transList[i].time - transList[j].time) <= 60) {
                    invalid.add(transList[i].transaction);
                    invalid.add(transList[j].transaction);
                }
            }
        }
    }

    return Array.from(invalid);    
};