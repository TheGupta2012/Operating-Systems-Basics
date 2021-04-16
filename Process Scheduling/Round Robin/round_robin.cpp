#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
int n,bur;

struct Process{
    int pid;
    int arrival_time;
    int burst_time;
};

bool my_sorter(Process const &a, Process const &b){
    return a.arrival_time < b.arrival_time;
}
map <int,int> waiting, turn_around;

vector<Process> process;
float get_awt(int time_slice){
    // variables
    int time = 0;
    float awt = 0;
    int left = n;
    int remaining[n] = {0};

    // copy burst time
    for(int i=0;i<n;i++){
        remaining[i] = process[i].burst_time;
    }

    // iterate till atleast one process left 
    while(left > 0){

        for(int i=0;i<n;i++){
            bur = remaining[i] ;

            if(bur == 0) continue;
           
            if(bur > time_slice){
                time+= time_slice;
                remaining[i] -= time_slice;
            }
            else{
                // total time counter
                time += remaining[i];
                waiting[i] = time - process[i].burst_time;// because this is the time for which process waited
                remaining[i] = 0;
                left--;
            }
        }
    }

    for(auto k:waiting)
        awt+= k.second;

    return awt/n;
}
float get_tat(){
    float tat = 0;
    for(int i=0;i<n;i++){
        turn_around[i] = waiting[i] + process[i].burst_time;
    }

    for(auto k:turn_around)
        tat+= k.second;

    return tat/n;
}
int main(){
    
    cout<<"Enter the number of processes :";
    cin>>n;
    int arrival,burst;
    Process P;
    for(int i=0;i<n;i++){
        cout<<"Arrival time "<<i+1<<":";
        cin>>arrival;
        cout<<"Burst time "<<i+1<<":";
        cin>>burst;
        P.pid = i;
        P.arrival_time = arrival;
        P.burst_time = burst;
        process.push_back(P);
    }
    
    int time_slice;
    cout<<"Enter the time slice :";
    cin>>time_slice;

    sort(all(process),my_sorter);
    cout<<"PROCESS\t\t ARRIVAL TIME\t\tBURST TIME\n";
    
    for(auto k: process)
        cout<<"  "<<k.pid<<"\t\t "<<k.arrival_time<<"\t\t\t"<<k.burst_time<<endl;
    

    float awt = get_awt(time_slice);
    float tat = get_tat();
    cout<<"AVERAGE WAITING TIME FOR ROUND ROBIN :"<<awt;
    cout<<"\nAVERAGE TURN AROUND TIME FOR ROUND ROBIN :"<<tat;
    return 0;

}