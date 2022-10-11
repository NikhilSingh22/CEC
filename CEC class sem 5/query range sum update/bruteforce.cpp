#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }


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
             break;

            case 2:
            int i,j,sum=0;
            cin>> i>> j;
            for(i ;i<=j;i++)
            {
                sum+=arr[i];
            }
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