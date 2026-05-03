class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # create a dp to record current number of coins
        # and a curr to record the current amount
        # run a for loop start for 0 and use 0 ~ i and see what is the number to make the amount

        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for c in coins:
                if i - c >= 0:
                    dp[i] = min(dp[i], 1 + dp[i - c])

        return dp[amount] if dp[amount] != amount + 1 else -1