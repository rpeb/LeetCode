// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void helper(vector<int>& v, vector<int>& arr, int n, int i, int sum) {
        if (i == n) return;
        sum += arr[i];
        v.push_back(sum);
        helper(v, arr, n, i+1, sum);
        sum -= arr[i];
        helper(v, arr, n, i+1, sum);
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> v;
        v.push_back(0);
        helper(v, arr, n, 0, 0);
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends