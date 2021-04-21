// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

// Use the distance from the origin as the first element of a pair in heap
// The use max heap as, k 'minimum distances' are needed


typedef pair<double, pair<int, int>> pp;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
    priority_queue<pp> pq;
  
    for(auto it : points)
    {    
        int x=it[0], y=it[1];
        double dist = sqrt(x*x + y*y);
        pq.push({dist, {x, y}});
        
        if(pq.size()>k)
            pq.pop();
    }
  
    vector<vector<int>> ans;
  
    while(!pq.empty())
    {
        vector<int> dum;
        dum.push_back(pq.top().second.first);
        dum.push_back(pq.top().second.second);
        ans.push_back(dum);
        pq.pop();
    }
    
    return ans;
}