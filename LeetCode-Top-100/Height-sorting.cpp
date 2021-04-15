// You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order).
// Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
// Reconstruct and return the queue that is represented by the input array people.
// The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

// Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
// Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

// Sort vector according to descending order of heights, if same height then ascending order of number of people in front.
// Keep on adding to the index as per 'k' the number of people in front.
// [the insert function takes care of shifting the elements]


static bool hey(vector<int> &p1, vector<int> &p2)
{
    if(p1[0]!=p2[0]) 
        return p1[0]>p2[0];
    else 
        return p1[1]<p2[1];
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
    sort(people.begin(), people.end(), hey);

    vector<vector<int>> ans;
    
    for(auto per : people) 
        ans.insert(ans.begin()+per[1], per);
    
    return ans;
}