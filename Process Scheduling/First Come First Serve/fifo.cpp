#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
int n,bur,arr,ind;

struct Process{
    int pid;
    int arrival_time;
    int burst_time;
};
vector< Process > process;
map <int,int> waiting, turn_around;

bool my_sorter(Process const &a, Process const &b){
    return a.arrival_time < b.arrival_time;
}


float get_awt(){
    int time = 0;
    float awt = 0.0;
    for(int i=0; i<n; i++){
        ind = process[i].pid;
        arr = process[i].arrival_time;
        bur = process[i].burst_time;

        if(i==0)
            waiting[ind] = 0;
        else
            waiting[ind] = max(time - arr,0);
        
        time = max(time + bur, arr + bur);
    }

    for(auto k:waiting)
        awt+= k.second;

    return awt/n;
}

float get_tat(){
    float tat = 0.0;
    for(int i=0;i<n;i++){
       ind = process[i].pid;
       bur = process[i].burst_time;
       turn_around[ind] = waiting[ind] + bur;
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
    

    sort(all(process),my_sorter);
    cout<<"PROCESS\t\t ARRIVAL TIME\t\tBURST TIME\n";
    
    for(auto k: process)
        cout<<"  "<<k.pid<<"\t\t "<<k.arrival_time<<"\t\t\t"<<k.burst_time<<endl;
    

    float awt = get_awt();
    float tat = get_tat();

    cout<<"AVERAGE WAITING TIME FOR FIFO  :"<<awt;
    cout<<"\nAVERAGE TURN AROUND TIME FOR FIFO :"<<tat;
    return 0;

}