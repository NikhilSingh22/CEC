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
