/*
ID: iCoder0020
PROG: Find Median from Data Stream
LANG: C++                  
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(max_heap.empty() || num <= max_heap.top())
            max_heap.push(num);
        else
            min_heap.push(num);
        if(max_heap.size() < min_heap.size())
        {
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
        else if(max_heap.size() > min_heap.size()+1)
        {
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
    }
    
    double findMedian() {
        double median = (double)(max_heap.top());
        
        if((max_heap.size() + min_heap.size()) %2 == 0)
        {
            median += (double)(min_heap.top());
            median /= 2.0;
        }
        return median;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */