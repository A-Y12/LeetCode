//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        vector<int> thief, police;
        
        // store the index of thief and policeman in their respective arrays
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 'P')
               police.push_back(i);
            else
               thief.push_back(i);
        }
        
        // now we use 2 pointer approach
        int p = 0, t = 0;
        int ans = 0;
        
        while(p < police.size() && t < thief.size())
        {
            // if police can catch thief, increase the count of answer and increment both the pointers
            if(abs(police[p] - thief[t]) <= k)
            {
                ans++;
                p++, t++;
            }
            
            // agar police jis index par hai wahan se nearest thief hi catch nahi kar paa rahi toh aage wale thiefs ko bhi nhi kar paayegi
            // so increment the index of police
            else if(police[p] < thief[t])
            {
                p++;
            }
            
            else
            {
                t++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends