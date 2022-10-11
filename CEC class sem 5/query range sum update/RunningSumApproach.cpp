#include<bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>&arr,int n)
{
    vector<int>ans(n);
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum+=arr[i];
        ans[i]=sum;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int>runsum(n);
    runsum = runningSum(arr,n);

    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>t;
        switch(t)
        {
            case 1: 
             int index,value;
             cin>>index>>value;
             arr[index]=value;

             runsum = runningSum(arr,n);
             break;

            case 2:
            int i,j,sum;
            cin>> i>> j;
            if(i == 0)
            {
                sum = runsum[j];
            }
            else   sum= runsum[j]-runsum[i-1];
            cout<<sum<<endl;
            break;
        }
    }

    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}