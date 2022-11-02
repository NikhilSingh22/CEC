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
