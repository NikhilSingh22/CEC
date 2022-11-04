// peak index in mountain array
int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        int l = 0;
        int h = n-1;

        while(l<=h)
        {
            int mid = l+(h-l)/2;

            if(mid>0 && mid<n-1)
            {
                if(arr[mid-1]<arr[mid]&& arr[mid]>arr[mid+1])
                    return mid;
                else if(arr[mid-1]> arr[mid])
                    h = mid-1;
                else
                    l = mid+1;
            }

            else if(mid == 0)
            {
                if(arr[0]>arr[1])
                 return 0;
                else 
                    return 1;
            }

            else if(mid == n-1)
            {
                if(arr[n-1]>arr[n-2])
                return n-1;
                else 
                return n-2;
            }
        }

        return 0;
    }




//Find positive integer solution for a given equation(hidden custom function 0-9)
  vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int x = 1,y=1000;
        while(x<=1000 && y>=1)
        {
            int val = customfunction.f(x,y);
            if(val == z)
            {
                res.push_back({x,y});
                x++;
                y--;
            }
            else if(val <z)
            {
                x++;
            }
            else 
            {
                y--;
            }

        }

        return res;
    }




//Maximum number of groups entering in a competetion
int maximumGroups(vector<int>& grades) {
     int n = grades.size();
     int l=0,h=1000;
    while(l<=h)
    {
        int mid = l+(h-l)/2;

        if((mid*(mid+1))/2 > n)
        {
            h=mid-1;
        }
        else
        {
            l= mid+1;
        }
    }
    return h;
    }



//maximum consequtive ones III (with option of flip k 0 bits)(sliding window)
int longestOnes(vector<int>& nums, int k) {
        int i =0,j=0,n=nums.size(),countzero = 0,ans=INT_MIN;

        while(j<n)
        {
            if(nums[j]==0)
            {
                countzero++;
            }
            while(countzero>k)
            {
                
                if(nums[i]==0)
                {
                    countzero--;
                }
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }




//My calender I
class MyCalendar {
    vector<pair<int,int>>v;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it: v)
        {
            if(it.first<end && start < it.second)
            {
                return false;
            }
        }
        v.push_back({start,end});
        return true;
    }
};




//MY calender II
class MyCalendarTwo {
    map<int,int>mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        for(auto it: mp)
        {
            sum+=it.second;
            if(sum>=3)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};


// kth smallest Element in a sorted matrix
int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];

        while(l<h)
        {
            int mid = l+(h-l)/2;
            int count  = 0;
            for(int i= 0;i<n;i++)
            {
                count+= upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin(); // upper bound gives number itself or just greater than it;
            }

            if(count<k)
            {
                l=mid+1;
            }
            else
            {
                h=mid;
            }
        }
        return l;
    }
