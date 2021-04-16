#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
int get_movement(vector<int> &Q, int curr,char move,int disk_size){
    
    int min = Q[0];
    int max = Q.back();
    int ans = 0;
    if(move == 'R'){
        if(curr<min){
            ans = max - curr;
        }
        else if(curr > max){
            ans = curr - min;
        }
        else{
            ans+= abs(max-min) + abs(max - curr);
        }
    }
    // go left 
    else{
        if(curr < min){
            ans+= max - curr;
        }
        else if(curr > max){
            ans+= curr - min;
        }
        else{
            ans+= abs(curr-min) + abs(max-min);
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    int curr_head,size_disk;
    cout<<"LOOK disk scheduling...\n";
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