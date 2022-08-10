/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// BRUTE FORCE

/*
    class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head)
    {
        vector<int> ans;
        ListNode *curr = head;
        
        while(curr != NULL)
        {
            ListNode *N = curr->next;
            
            // Keep on updating N till you find strictly greater value
            while(N != NULL && N->val <= curr->val)
            {
                N = N->next;
            }
            
            if(N != NULL)
            {
                ans.push_back(N->val);
                curr = curr->next;
            }
            else
            {
                // No greater value present 
                ans.push_back(0);
                curr = curr->next;
            }
        }
        
        return ans;
    }
};

*/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        ListNode* curr = head;
        vector<int> arr;
        // Convert the linked list into array or vector
        while(curr)
        {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        // Apply Next Greater element to right
        for(int i = n - 1; i >= 0; i--)
        {
            if(st.size() > 0)
            {
                while(st.size() > 0 && st.top() <= arr[i])
                {
                    st.pop();
                }
            }
            
            if(st.size() > 0)
            {
                ans[i] = st.top();
            }
            else
            {
                ans[i] = 0;
            }
            
            st.push(arr[i]);
        }
        
        return ans;
    }
};