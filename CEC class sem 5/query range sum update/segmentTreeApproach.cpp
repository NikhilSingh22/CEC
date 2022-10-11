#include<bits/stdc++.h>
using namespace std;

size_t calculateSize(size_t n) // calculatin the size of tree i.e total nodes in the tree.
{
    size_t ans = 2 * pow(2,ceil(log2(n))) -1;
    return ans;
}

void buildTreeUtils(vector<int>&arr, vector<int> &res,int sl , int sr , int index) // actual recursive function for building tree.
{
    if(sl == sr)
    {
        res[index] = arr[sl];
        return;
    }

    int mid = (sl+sr)/2;

    buildTreeUtils(arr,res,sl,mid,2*index+1);
    buildTreeUtils(arr,res,mid+1,sr,2*index+2);

    res[index] = res[2*index + 1] + res[2*index +2];
    return;
}

vector<int> buildTree(vector<int>&arr,int n , int ts)  // for building tree
{
    vector<int> res(ts);
    buildTreeUtils(arr,res,0,n-1,0);
    return res;
}


void update(vector<int> &segTree,int index, int changeval, int sl , int sr , int si) // updating the node value(recursive)
{
    if(sl == sr && index == sl) // when the leaf node 
    {
        segTree[si]+=changeval;
        return;
    }
    else if(index >= sl && index <=sr) 
    {
        segTree[si]+=changeval; 
        int mid = (sl+sr)/2; // deciding where the node will lie is left of right.

        if(index <= mid)
        {
            update(segTree,index,changeval,sl,mid,2*si+1);
        }
        else 
        {
            update(segTree,index,changeval,mid+1,sr,2*si+2);
        }
    }
    return;
}

int rangeSum(vector<int>&segTree, int ql,int qr, int sl ,int sr,int si) // si is the starting index of that tree recursion
{
    if(qr<sl || ql>sr) // non overlapping case
    return 0;
    else if(sl>=ql && sr<=qr)// complete overlapping case 
    return segTree[si];
    else // partial overlapping case
    {
        int mid = (sl+sr)/2;
        return rangeSum(segTree,ql,qr,sl,mid,2*si+1)+rangeSum(segTree,ql,qr,mid+1,sr,2*si+2);
    }
}

int main()
{
    size_t n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    size_t ts = calculateSize(n); // calculating tree size 

    vector<int> segTree = buildTree(arr,n,ts);

    int Q;
    cin>>Q;
    while(Q--)
    {
        int t;
        cin>>t;

        switch(t)
        {
            case 1:
            int index, value,changeval;
            cin>>index>>value;
            changeval = value-arr[index];
            arr[index]=value;
            update(segTree,index,changeval,0,n-1,0);
            break;

            case 2:
            int l , r;
            cin>>l>>r;
            cout<<"Range sum: "<<rangeSum(segTree,l,r,0,n-1,0)<<"\n";
            break;
        
        }
    }
}