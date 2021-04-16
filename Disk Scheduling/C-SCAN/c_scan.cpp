#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
int get_movement(vector<int> &Q, int curr,char move,int disk_size){
    int ans = 0;

    if(move == 'R'){
        ans+= disk_size - 1 - curr;
        // if it moved right initially, 
        // would stop at the last index or 
        // LOWER BOUND OF curr after moving right again
        
        auto it = lower_bound(all(Q),curr) - Q.begin();
        it--;
        // if the smaller element exists
        // cout<<"Lower bound :"<<Q[it]<<endl;
        if(it>=0)
            ans+= Q[it];
    }
   
    else{
        // if it moved left initially, 
        // would stop at first element > curr 
        // or the UPPER BOUND
        ans+= curr;
        auto it = upper_bound(all(Q),curr);
        // if the bigger element exists
        if(it!=Q.end())
             ans+= disk_size - 1 - (*it);
    }

    ans+= (disk_size-1);

    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    int curr_head,size_disk;
    cout<<"C-SCAN disk scheduling...\n";
    // get current head pointer
    cout<<"Enter current head position :";
    cin>>curr_head;

    // get the disk size
    cout<<"Enter the disk size :";

    cin>>size_disk;

    // get the head movement
    char move;
    cout<<"Enter the initial head movement(L/R) :";
    cin>>move;
    cout<<"Enter the ready queue for DISK ACCESS :(-1 to end)";
    vector<int> disk_queue;
    int d;
    while(true){
        cin>>d;
        if(d == -1)
            break;
        if(d < 0 || d>=size_disk){
            cout<<"Invalid value\nEnter current element again\n";
            continue;
        }
        disk_queue.push_back(d);
    }

    // calculate the total head movement and average seek time 
    sort(all(disk_queue));
    int head_move = get_movement(disk_queue,curr_head,move,size_disk);

    float avg_head = (float(head_move)/disk_queue.size());

    cout<<"TOTAL HEAD MOVEMENT : "<<head_move<<endl;
    cout<<"AVERAGE HEAD MOVEMENT : "<<avg_head<<endl;

    return 0;
}