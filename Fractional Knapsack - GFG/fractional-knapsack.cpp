// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, [&](Item a, Item b) -> bool {
           return (double)a.weight/a.value < (double)b.weight/b.value; 
        });
        double maxVal = 0;
        for (int i = 0; i < n; ++i) {
            if (W >= arr[i].weight) {
                maxVal += arr[i].value;
                // cout << "maxVal = " << maxVal << "\n";
                W -= arr[i].weight;
            } else {
                maxVal += ((double)W/arr[i].weight) * arr[i].value;
                W = 0;
            }
        }
        return maxVal;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends