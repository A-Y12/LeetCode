class Solution {
public:
    int f(int n1, int n2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        // if str1 is exhausted
        // remaining characters of str2 needs to be inserted
        if(n1 == 0)
            return n2;
        
        // if str2 is exhausted
        // remaining characters of str1 have to be deleted so n1 operations
        if(n2 == 0)
            return n1;
            
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
        
        if(s1[n1 - 1] == s2[n2 - 1])
        {
            // if both characters match, shrink both the strings
            return dp[n1][n2] = 0 + f(n1 - 1, n2 - 1, s1, s2, dp);
        }
        else
        {
            // if the character does not match, we have 3 operations to perform
            // insert, delete, replace
            // we will take min of them
            return dp[n1][n2] = 1 + min( f(n1 - 1, n2 - 1, s1, s2, dp), min( f(n1 - 1, n2, s1, s2, dp), f(n1, n2 - 1, s1, s2, dp) ));
        }
    }
    
    int minDistance(string word1, string word2) 
    {
        int n1 = word1.size();
        int n2 = word2.size();
        
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        return f(n1, n2, word1, word2, dp);        
    }
};