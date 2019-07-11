/*
ID: iCoder0020
PROG: Min Stack
LANG: C++                  
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>>S;
    MinStack() 
    {
        // stack<pair<int,int>>S;    
    }
    
    void push(int x) 
    {
        int m = x;
        if(!S.empty())
        {
            if(x > S.top().second)
                m = S.top().second;
        }
        S.push({x,m});   
    }
    
    void pop() 
    {
        S.pop();
    }
    
    int top() 
    {
        return S.top().first;
    }
    
    int getMin() 
    {
         return S.top().second;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */