#https://leetcode.com/problems/invalid-transactions/
#A transaction is possibly invalid if:
#	the amount exceeds $1000, or;
#	if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
#You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
#Return a list of transactions that are possibly invalid. You may return the answer in any order.
# 
#Example 1:
#Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
#Output: ["alice,20,800,mtv","alice,50,100,beijing"]
#Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
#Example 2:
#Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
#Output: ["alice,50,1200,mtv"]
#Example 3:
#Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
#Output: ["bob,50,1200,mtv"]
# 
#Constraints:
#	transactions.length <= 1000
#	Each transactions[i] takes the form "{name},{time},{amount},{city}"
#	Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
#	Each {time} consist of digits, and represent an integer between 0 and 1000.
#	Each {amount} consist of digits, and represent an integer between 0 and 2000.
class Solution(object):
    def invalidTransactions(self, transactions):
        """
        :type transactions: List[str]
        :rtype: List[str]
        """
        # 1. 使用字典存储交易记录
        transactions_dict = {}
        for transaction in transactions:
            name, time, amount, city = transaction.split(',')
            time = int(time)
            amount = int(amount)
            if name not in transactions_dict:
                transactions_dict[name] = []
            transactions_dict[name].append((time, amount, city))

        # 2. 找到无效交易
        invalid_transactions = []
        for transaction in transactions:
            name, time, amount, city = transaction.split(',')
            time = int(time)
            amount = int(amount)

            # 3. 检查金额是否超过1000
            if amount > 1000:
                invalid_transactions.append(transaction)
                continue

            # 4. 检查是否在60分钟内有相同姓名的交易
            for t, a, c in transactions_dict[name]:
                if t != time and abs(t - time) <= 60 and c != city:
                    invalid_transactions.append(transaction)
                    break

        return invalid_transactions   