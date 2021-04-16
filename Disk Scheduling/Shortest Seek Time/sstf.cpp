#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
int get_movement(vector<int> &Q, int curr){

    int ind = upper_bound(all(Q),curr) - Q.begin();

    // the first element > curr_head_pos 

    // just look at immediate left and immediate right 
    int n = Q.size();
    if(n == 0)
        return -1;

    bool visited[n] = {false};
    bool done = false;
    int ans,left,right;


    if(ind == n)  right = 1e6; // if the value is very big for current head
    else right = abs(curr - Q[ind]); // ind is the first index > current head

    if(ind == 0) left = 1e6;
    else left = abs(curr - Q[ind-1]);

    if(left <= right) // left has shorter seek time 
        {ans = left;
        ind--;
        curr = Q[ind];
        visited[ind] = true;}

    else 
        {ans = right; // no need to increment as already there...
        visited[ind] = true;
        curr = Q[ind];}

    int templ,tempr;

    while(done == false){
        
        templ = ind-1;
        while(visited[templ] == true && templ >=0)
            templ--;
        
        if(templ>=0)
            left = abs(curr - Q[templ]);
        else 
            left = 1e6;
        tempr = ind+1;
        while(visited[tempr] == true && tempr <n) 
            tempr++;

        if(tempr != n)
            right = abs(curr - Q[tempr]);
        else 
            right = 1e6;

        if(left < right ){
            ans+= left;
            cout<<Q[templ]<<" chosen for head at "<<curr<<endl;
            ind = templ;
            curr = Q[ind];
            visited[ind] = true;
        }
        else if(left > right){
            ans+= right;
            cout<<Q[tempr]<<" chosen for head at "<<curr<<endl;
            ind = tempr;
            curr = Q[ind];
            visited[ind] = true;
        }
        else if(left == right && left!= 1e6){
            ans+= left;
            ind= templ;
            curr = Q[ind];
            visited[ind] = true;
        }
        else 
            done = true;
    }

    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    int curr_head,size_disk;
    cout<<"SHORTEST SEEK TIME FIRST disk scheduling...\n";
    cout<<"Enter current head position :";
    cin>>curr_head;
    cout<<"Enter the disk size :";
    cin>>size_disk;

    cout<<"Enter the ready queue for DISK ACCESS :(-1 to end)\n";
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
    sort(disk_queue.begin(),disk_queue.end());

    // calculate the total head movement and average seek time 

    int head_move = get_movement(disk_queue,curr_head);

    float avg_head = (float(head_move)/disk_queue.size());

    cout<<"TOTAL HEAD MOVEMENT : "<<head_move<<endl;
    cout<<"AVERAGE HEAD MOVEMENT : "<<avg_head<<endl;

    return 0;
}