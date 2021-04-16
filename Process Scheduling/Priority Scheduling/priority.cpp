#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
int n,burst,priority,arrival,ind;

struct Process{
    int pid;
    int burst_time;
    int priority;
};

bool my_sorter(Process const &a, Process const &b){
    return a.priority < b.priority;
}
map <int,int> waiting, turn_around;

vector<Process> process;
float get_awt(){
    // variables
    int time = 0;
    float awt = 0;
    for(int i=0;i<n;i++){
        ind = process[i].pid;
        priority = process[i].priority;
        burst = process[i].burst_time;
        // waiting time for process
        waiting[ind] = time;
        time+= burst;
    }

    for(auto k:waiting)
        awt+= k.second;
    
    return awt/n;
}
float get_tat(){
    float tat = 0;
    
    for(int i=0;i<n;i++){
        ind = process[i].pid;
        burst = process[i].burst_time;

        turn_around[ind] = waiting[ind] + burst;
    }

    for(auto k:turn_around)
        tat+= k.second;
    return tat/n;
}
int main(){
    
    cout<<"Enter the number of processes :";
    cin>>n;
    Process P;
    for(int i=0;i<n;i++){
        
        cout<<"Burst time "<<i+1<<":";
        cin>>burst;
        cout<<"Priority "<<i+1<<":";
        cin>>priority;
        P.pid = i;
        P.priority = priority;
        P.burst_time = burst;
        process.push_back(P);
    }
    
    // ASSUMPTION - lower absolute value of priority is having higher actual priority

    // priority 1 -> highest 
    // priority n -> lowest
    cout<<"ORDER OF PROCESSES IN PRIOIRITY SCHEDULING:\n";
    sort(all(process),my_sorter);
    cout<<"PROCESS\t\t PRIORITY\t\tBURST TIME\n";
    
    for(auto k: process)
        cout<<"  "<<k.pid<<"\t\t "<<k.priority<<"\t\t\t"<<k.burst_time<<endl;
    
    

    float awt = get_awt();
    float tat = get_tat();
    cout<<"AVERAGE WAITING TIME FOR PRIORITY SCHEDULING:"<<awt;
    cout<<"\nAVERAGE TURN AROUND TIME FOR PRIORITY SCHEDULING :"<<tat;
    return 0;

}