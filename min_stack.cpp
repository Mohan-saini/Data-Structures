#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<long long> stk;
    long long minEle = 0;
    
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            minEle = val;
        }
        else {
            // Cast to long long to prevent overflow
            long long diff = (long long)val - minEle;
            stk.push(diff);
            if(diff < 0) {
                minEle = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        long long diff = stk.top();  // Changed from int to long long
        stk.pop();
        if(diff < 0) {
            minEle = minEle - diff;
        }
    }
    
    int top() {
        long long diff = stk.top();
        return diff < 0 ? minEle : minEle + diff;
    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack mn_stk;
    mn_stk.push(-2);
    mn_stk.push(0);
    mn_stk.push(-3);
    cout<<mn_stk.getMin()<<endl;
    mn_stk.pop();
    cout<<mn_stk.top()<<endl;
    cout<<mn_stk.getMin()<<endl;
    return 0;
}