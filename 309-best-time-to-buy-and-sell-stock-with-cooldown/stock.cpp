class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // idx -> 0 to (n - 1), buy -> 0 or 1
        // (n + 2) size is taken because in selling portion we are doing (idx + 2)
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;

                if (buy == 1)
                {
                    profit = max(-prices[idx] + dp[idx + 1][0], 0 + dp[idx + 1][1]);
                }
                else
                {
                    profit = max(prices[idx] + dp[idx + 2][1], 0 + dp[idx + 1][0]);
                }

                dp[idx][buy] = profit;
            }
        }

        return dp[0][1];
    }
};