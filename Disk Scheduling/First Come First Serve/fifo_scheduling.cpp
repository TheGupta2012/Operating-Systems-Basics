#include<bits/stdc++.h>
using namespace std;
int get_movement(list<int> &Q, int curr){
    int ans = 0;
    for(auto k:Q){
        ans+= abs(k-curr);
        curr = k;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    int curr_head,size_disk;
    cout<<"FIRST COME FIRST SERVE disk scheduling...\n";
    cout<<"Enter current head position :";
    cin>>curr_head;
    cout<<"Enter the disk size :";
    cin>>size_disk;

    cout<<"Enter the ready queue for DISK ACCESS :(-1 to end)";
    list<int> disk_queue;
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

    int head_move = get_movement(disk_queue,curr_head);

    float avg_head = (float(head_move)/disk_queue.size());

    cout<<"TOTAL HEAD MOVEMENT : "<<head_move<<endl;
    cout<<"AVERAGE HEAD MOVEMENT : "<<avg_head<<endl;

    return 0;
}