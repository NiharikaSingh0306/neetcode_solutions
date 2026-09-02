class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int ,vector<int>, greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num<=left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }

        //balancing the halves

        //too many on left
        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }
        //too many on right
        else if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
        
    }
    
    double findMedian() {
        //odd
        if(left.size()>right.size()){
            return left.top();
        }
        //even no
        return (left.top()+right.top())/2.0;

       
    }
};
