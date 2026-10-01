class MedianFinder {
private:
priority_queue<int> maxheap;
priority_queue<int,vector<int>,greater<int>> minheap;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxheap.push(num);
        
        if(!minheap.empty() && (maxheap.top() > minheap.top())){
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        if(minheap.size() + 1 < maxheap.size()){
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        if(maxheap.size() + 1 < minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }

    }
    
    double findMedian() {
        if(minheap.size()>maxheap.size()) return minheap.top();
        else if(minheap.size()<maxheap.size()) return maxheap.top();
        else return (minheap.top()+maxheap.top())/2.0;
    }
};
