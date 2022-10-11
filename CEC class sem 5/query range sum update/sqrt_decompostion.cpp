#include<bits/stdc++.h>
using namespace std;

// update function for new value;
void update(vector<int>&arr,vector<int>&blocks,int i ,int val)
{
    int bs = blocks.size();
    int changeval = val -arr[i];
    arr[i] = val;
    blocks[i/bs]+=changeval;
    return;
}

// calculating sum 
int rangeSum(vector<int>&arr,vector<int>&blocks,int l,int r)
{
    int bs = blocks.size();
    int sb = l/bs , eb = r/bs;
    int sum = 0;
    if(sb==eb) // when start block and end block is same 
    {
        for(int i = l;i<=r;i++)
        {
            sum+=arr[i];
        }
        return sum;
    }

    // when start block and end block is different


    for(int i = sb+1;i<eb;i++) // calculating the sum where block is whole
    {
        sum+=blocks[i];
    }

    int i = l;
    while(i/bs == sb) // for the left most block which is not full
    {
        sum+=arr[i++];
    }
    i=r;
    while(i/bs == eb) // for the right most block which is not full.
    {
        sum+=arr[i--];
    }

    return sum;
}

int main()
{
    size_t n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    size_t bs;
    bs = ceil(sqrt(n));

    vector<int>blocks(bs,0);
    for(int i = 0;i<n;i++)
    {
        blocks[i/bs]+=arr[i];
    }

    int Q; // number of query
    cin>>Q;
    while(Q--)
    {
        int t;
        cin>> t;
        switch(t)
        {
            case 1: int index,value;
            cin>>index>>value;
            update(arr,blocks,index,value);
            break;

            case 2:
            int l,r;
            cin>>l>>r;
            cout<<rangeSum(arr,blocks,l,r)<<endl;
            break;
        }
    }

    return 0;
}