// Find the winner of the circular game
int findTheWinner(int n, int k) {
        queue<int>qt;
        for(int i = 1;i<=n;i++)
        {
            qt.push(i);
        }
        
        int step;
        while(qt.size()!=1)
        {
            step = k;
            while(step>1)
            {
                step--;
                int x = qt.front();
                qt.pop();
                qt.push(x);
            }
            qt.pop();
        }

        return qt.front();
    }




//Reveal the cards in increasing order
 vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size());
        sort(deck.begin(),deck.end());
        deque<int>dq;

        for(int i = 0;i<deck.size();i++)
        {
            dq.push_back(i);
        }
        int index = 0;
        int flag = 0;
        while(!dq.empty())
        {
            if(flag==0)
            {
                ans[dq.front()] = deck[index++];
                dq.pop_front();
            }
            else
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            flag^=1;
        }
    return ans;
    }




//Flatten nested list iterator
class NestedIterator {
    queue<int>qt;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
    }

    void flattenList(vector<NestedInteger> &nestedList)
    {
        for(auto& it : nestedList)
        {
            if(it.isInteger())
            {
                qt.push(it.getInteger());
            }
            else
            {
                flattenList(it.getList());
            }
        }
    }
    
    int next() {
        int t = qt.front();
        qt.pop();
        return t;
    }
    
    bool hasNext() {
        return !qt.empty();
    }
};





//Design circular deque
class MyCircularDeque {
public:
    int max;
    deque<int>dq;
    MyCircularDeque(int k) {
        max=k;
    }
    
    bool insertFront(int value) {
        if(dq.size()<max)
        {
            dq.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(dq.size()<max)
        {
            dq.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!dq.empty())
        {
            dq.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!dq.empty())
        {
            dq.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(dq.empty()) return -1;
        return dq.front();
    }
    
    int getRear() {
        if(dq.empty())return -1;
        return dq.back();
    }
    
    bool isEmpty() {
       return dq.empty();
    }
    
    bool isFull() {
        if(dq.size()==max)
            return true;
        return false;
    }
};





