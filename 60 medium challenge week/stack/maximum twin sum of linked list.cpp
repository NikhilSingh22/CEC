// Input: head = [5,4,2,1]
// Output: 6
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
