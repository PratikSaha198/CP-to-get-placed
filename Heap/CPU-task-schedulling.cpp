// You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

// You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

// If the CPU is idle and there are no available tasks to process, the CPU remains idle.
// If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
// Once a task is started, the CPU will process the entire task without stopping.
// The CPU can finish a task then start a new one instantly.
// Return the order in which the CPU will process the tasks.

// Use a min-heap pq to keep track of available tasks, sorted first by processing time then by index.
// Sort the input array in ascending order of enqueue time.
// Let time be the current time. When time >= A[i][0], keep pushing A[i] into the min-heap.
// Then we pop a task from the min-heap and handle it. Increase the time by the processing time of this task and add its index to the answer.


typedef pair<int, int> T;

vector<int> getOrder(vector<vector<int>>& v)
{
    for(int i=0;i<v.size();i++){
        v[i].push_back(i);
    }

    sort(v.begin(), v.end());

    priority_queue<T, vector<T>, greater<>> pq;
    long n = v.size(), time=0, i=0;

    vector<int> ans;

    while(i<n || pq.size())
    {
        if(pq.empty())
            time = max(time, (long)v[i][0]);
        
        while(i<n && time>=v[i][0])
        {
            pq.push({v[i][1], v[i][2]});
            i++;
        }
        
        auto [pro, index] = pq.top();
        pq.pop();
        
        time+=pro;
        
        ans.push_back(index);
    }

    return ans;
}