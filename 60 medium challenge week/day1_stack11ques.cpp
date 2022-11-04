// minimum add to make paranthesis valid
 int minAddToMakeValid(string s) {
        int count = 0;
        stack<char>st;

        for(int i = 0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                if(st.empty()||st.top()==')')
                    count++;
                else if(st.top()=='(')
                    st.pop();
            }
        }

        return count+st.size();
    }




// Design Browser History
 stack<string>st1,st2;
    BrowserHistory(string homepage) {
        st1.push(homepage);
    }
    
    void visit(string url) {
        while(!st2.empty())
        {
            st2.pop();
        }
        st1.push(url);
    }
    
    string back(int steps) {
        while(st1.size()>1 && steps >0)
        {
            steps--;
            st2.push(st1.top());
            st1.pop();
        }
        return st1.top();
    }
    
    string forward(int steps) {
        while(!st2.empty() && steps>0)
        {
            steps--;
            st1.push(st2.top());
            st2.pop();
        }
        return st1.top();
    }
};




//Construct smallest Number from DI string
 string smallestNumber(string pattern) {
        string ans;
        stack<int>st;
        for(int i = 0;i<=pattern.size();i++)
        {
            st.push(i+1);

            if(i == pattern.size() || pattern[i]=='I')
            {
                while(!st.empty())
                {
                    ans+= to_string(st.top());
                    st.pop();
                }
            }
        }

        return ans;
    }



//maximum nesting depth of two valid paranthesis
vector<int> maxDepthAfterSplit(string seq) {
     vector<int> res (seq.size());
     int lvl = 0;
     for(int i = 0;i<seq.size();i++)
     {
         if(seq[i]=='(')
         {
             lvl++;
             res[i] = lvl%2;
         }
         else
         {
             res[i]= lvl%2;
             lvl--;
         }
     }
    return res;
    }



//Build an array with stack operations
vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        // stack<int>st;
        int k = 1,i=0;
        while(i<target.size())
        {   
            res.push_back("Push");
            
            if(target[i]==k)
            {
                i++;
                k++;
            }
            else
            {
                res.push_back("Pop");
                k++;
            }
        }
        return res;
    }



// minimum number of swaps to make string balanced
int minSwaps(string s) {
        int maxi  = 0;
        int extraClose= 0;

        for(int i = 0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                extraClose++;
            }
            else
            {
                extraClose--;
            }
            maxi = max(maxi,extraClose);
        }
        return (maxi+1)/2;
       
    }




//validate Stack sequence
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int>st;
    
        int i = 0,j=0;
        while(i<n)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            i++;
        }

        if(st.empty())
        {
            return true;
        }

        return false;
    }



//Daily temperature (based on next greater element)\
vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>waitDays(n);
        stack<pair<int,int>>st;

        for(int i = n-1; i>=0;i--)
        {
            while(!st.empty() && st.top().first <= temperatures[i])
            {
                st.pop();
            }

            if(i<n)
            {
                if(!st.empty())
                {
                    waitDays[i] = st.top().second-i;

                }
                else
                {
                    waitDays[i] = 0;
                }
            }

            st.push({temperatures[i],i});
        }
        return waitDays;
    }


// reverse substring between each pair of parenthesis
string reverseParentheses(string s) {
        stack<char>st;
        
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                queue<char>qt;
                while(st.top()!='(')
                {
                    qt.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!qt.empty())
                {
                    st.push(qt.front());
                    qt.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        s.clear();
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }


//Maximum twin sum of a linked list
 int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;
        int maxi = 0;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }

        temp=head;
        while(temp!=NULL)
        {
            maxi = max(maxi, temp->val+st.top());
            st.pop();
            temp=temp->next;
        }


        return maxi;
    }


//Desgin a stack with increment operation
int max;
    stack<int>st,temp;
    CustomStack(int maxSize) {
       max = maxSize; 
    }
    
    void push(int x) {
        if(st.size()<max)
            st.push(x);
    }
    
    int pop() {
        if(st.empty())
            return -1;
        int t = st.top();
        st.pop();
        return t;
    }
    
    void increment(int k, int val) {
        int l = st.size();
        if(l>k)
        {
            for(int i=l ;i>k;i--)
            {
                temp.push(st.top());
                st.pop();
            }
        }

        for(int i = st.size();i>0;i--)
        {
            temp.push((st.top()+val));
            st.pop();
        }

        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
};
