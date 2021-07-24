#include <bits/stdc++.h>
using namespace std;
static int arrsize;

class SegmentTreeSum
{
public:
    int *treearr;
    int *arr;
    SegmentTreeSum(int n, int *a)
    {
        int x = (int)(ceil(log2(n)));
        //Maximum size of segment tree
        int max_size = 2 * (int)pow(2, x) - 1;
        treearr = new int[max_size];

        arrsize = n;
        //treearr = new int[4*n+1];
        arr = a;
    }
    void buildTree(int index = 1, int start = 1, int end = arrsize)
    {
        //Base Case
        if (start > end)
        {
            return;
        }
        //Base Case for Leaf Nodes
        if (start == end)
        {
            //cout<<"tree["<<index<<"]="<<arr[start]<<endl;
            treearr[index] = arr[start];
            return;
        }
        //Recursive Case
        int mid = (start + end) / 2;
        this->buildTree(index * 2, start, mid);
        this->buildTree(index * 2 + 1, mid + 1, end);

        //segment nodes are sum of left and right
        treearr[index] = max(treearr[index * 2], treearr[index * 2 + 1]);
        //cout<<"midtree["<<index<<"]="<<treearr[index*2]+treearr[index*2+1]<<endl;
    }

    int getMax(int start, int end, int treestart = 1, int treeend = arrsize, int index = 1)
    {
        //No Overlap
        if (treestart > end || treeend < start)
        {
            //cout<<"1 -- ("<<start<<","<<end<<") and ("<<treestart<<","<<treeend<<") index = "<<index<<endl;
            return INT_MIN;
        }
        //Complete Overlap
        if (treestart >= start && treeend <= end)
        {
            //cout<<"2 -- ("<<start<<","<<end<<") and ("<<treestart<<","<<treeend<<") index = "<<index<<endl;
            return treearr[index];
        }

        //cout<<"left"<<endl;
        //Partial Overlap
        int mid = (treestart + treeend) / 2;
        //Call on both sides
        int l = getMax(start, end, treestart, mid, index * 2);
        //cout<<"right"<<endl;
        int r = getMax(start, end, mid + 1, treeend, index * 2 + 1);
        //cout<<"3 -- ("<<start<<","<<end<<") and ("<<treestart<<","<<treeend<<") index = "<<index<<endl;
        return max(l, r);
    }

    // void update(int data,int start,int end,int treestart=1,int treeend=arrsize,int treeindex=1)
    // {

    //   if(start>treeend || end<treestart)return;
    //   //treearr[treeindex] +=(treearr[treeindex*2]+treearr[treeindex*2+1]);
    //   if(treestart<treeend){
    //   int mid = (treestart+treeend)/2;
    //   update(data,start,end,treestart,mid,treeindex*2);
    //   update(data,start,end,mid+1,treeend,treeindex*2+1);
    //   }

    //   if(treestart==treeend)
    //   {
    //     treearr[treeindex]+=data;
    //     return;
    //   }
    //   treearr[treeindex] =(treearr[treeindex*2]+treearr[treeindex*2+1]);
    // }
};

int main()
{
    int t;
    cin >> t;
    int n = t;
    int arr[100000] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    //int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    //int n=9;
    SegmentTreeSum s(n, arr);
    s.buildTree();

    // for(int i=1;i<18;i++)
    // cout<<"i = "<<i<<" : "<<s.treearr[i]<<endl;

    int q;
    cin >> q;
    //cout<<"Queries = "<<q<<endl;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        //cout<<"a = "<<a<<" b = "<<b<<endl;
        cout << s.getMax(a, b) << endl;
    }

    // cout<<"---------------"<<endl;
    // cout<<s.getMax(1, 9)<<endl;
    // cout<<"---------------"<<endl;
    // //s.update(4,2,7);

    return 0;
}