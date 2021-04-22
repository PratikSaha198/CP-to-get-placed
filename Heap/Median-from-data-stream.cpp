// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


// Solution -------------------------

// Two priority queues:

// A max-heap lo to store the smaller half of the numbers
// A min-heap hi to store the larger half of the numbers
// The max-heap lo is allowed to store, at worst, one more element more than the min-heap hi. Hence if we have processed kk elements:

// If k = 2*n + 1 \quad (\forall \, n \in \mathbb{Z})k=2∗n+1(∀n∈Z), then lo is allowed to hold n+1n+1 elements, while hi can hold nn elements.
// If k = 2*n \quad (\forall \, n \in \mathbb{Z})k=2∗n(∀n∈Z), then both heaps are balanced and hold nn elements each.
// This gives us the nice property that when the heaps are perfectly balanced, the median can be derived from the tops of both heaps. Otherwise, the top of the max-heap lo holds the legitimate median.

// Adding a number num:

// Add num to max-heap lo. Since lo received a new element, we must do a balancing step for hi. So remove the largest element from lo and offer it to hi.
// The min-heap hi might end holding more elements than the max-heap lo, after the previous operation. We fix that by removing the smallest element from hi and offering it to lo.

// Time complexity: O(5 \cdot \log n) + O(1) \approx O(\log n)O(5⋅logn)+O(1)≈O(logn).


priority_queue<int> lo;
priority_queue<int, vector<int>, greater<int>> hi;

MedianFinder() {
    
}

void addNum(int num) {
    lo.push(num);
    hi.push(lo.top());
    lo.pop();
    if(lo.size()<hi.size()){
        lo.push(hi.top());
        hi.pop();
    }
}

double findMedian() {
    if(lo.size()>hi.size()) return lo.top();
    else return (double)(lo.top()+hi.top())/2;
}