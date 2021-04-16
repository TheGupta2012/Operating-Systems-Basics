#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
int n,bur,ind,arrived;

struct Process{
    int pid;
    int arrival_time;
    int burst_time;
};
map <int,int> waiting, turn_around;
vector<Process> process;

bool my_sorter(Process const &a, Process const &b){
    if(a.arrival_time != b.arrival_time )
        return a.arrival_time < b.arrival_time;
    else{
        return a.burst_time < b.burst_time ;
    }
}
// to get the current process
int get_curr_process(int time,set<int> done){
    if(time == 0)
        return 0;
    else{
        int min_arr,best_ind;
        bool found1 = false;
        bool found2 = false;
        int min_bur = 1e6;
        for(int i=0;i<n;i++){

            // get the best left over process 
            if(done.find(i) == done.end()){

                arrived = process[i].arrival_time;
                bur = process[i].burst_time;

                // min_arrival process  
                if(found1 == false){
                    min_arr = i;
                    found1 = true;
                }

                // if process present 
                if(arrived <= time ){
                    if(bur <= min_bur){
                        min_bur = bur;
                        best_ind = i;
                        found2 = true;
                    }
                }
            
            }
        }
        // if all processes have greater arrivals 
        if(found2 == false)
            return min_arr;
        
        // return shortest job within time
        return best_ind;
    }
}

float get_AWT(){
    // first sort the job according to arrival time 
    int time = 0;
    float awt = 0.0;

    set<int> done;
    while(done.size() != n){

        int curr = get_curr_process(time,done); // get the process 

        // then select the job with min arrival and min burst time 
        // such that the arrival time of the job is < current time stamp 
        ind = process[curr].pid;
        bur = process[curr].burst_time;
        arrived = process[curr].arrival_time;

        // now this process's waiting time is 
        waiting[ind] = max(time - arrived,0);

        // increment the time stamp
        time  = max(time + bur, arrived + bur);

        // process is done 
        done.insert(curr);
    }
   

    for(auto k:waiting)
        awt+= k.second;
    return awt/n;
    // execute it and then again do the same till you have no processes left 
}

float get_TAT(){
    float tat = 0.0;

    for (int i=0;i<n;i++)
        tat+= process[i].burst_time + waiting[i];
    
    return tat/n;
}

int main(){
    ios::sync_with_stdio(0);
    
    
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
    
    float awt = get_AWT();
    float tat = get_TAT();
    cout<<"AVERAGE WAITING TIME FOR SHORTEST JOB FIRST :"<<awt;
    cout<<"\nAVERAGE TURN AROUND TIME FOR SHORTEST JOB FIRST :"<<tat;
    
    
    return 0;
}