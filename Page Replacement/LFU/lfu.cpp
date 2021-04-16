#include<bits/stdc++.h>
#define for0(i,n) for(int i=0;i<n;i++)
#include<windows.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);

    //Declare frame
    set<int> frame;

    //Declare  hash table for frequencies 
    unordered_map <int,int> freq;

    cout<<"Program to simulate LEAST FREQUENTLY USED page replacement\n";
    int f_size,len,min,to_replace;

    //SIMULATION
    cout<<"Enter the frame size :";
    cin>>f_size;
    cout<<"Enter how many pages you want to simulate :";
    cin>>len;
    cout<<"Simulating page request queue :\n";

    int hit,miss,count,page;
    hit = count = miss = 0;
    for0(i,len){
        page = rand()%9 + 1;
        cout<<"Page :"<<page<<endl;

        // referenced 
        freq[page]++;

        if(frame.find(page) != frame.end()){
            // hit 
            cout<<"Hit! "<<page<<" found in frame\n";
            hit++;
        }
        else{
            //miss 
            miss++;
            cout<<"Miss! ";
            if(frame.size() != f_size){
                // some empty space available
                cout<<page<<" inserted\n"; 
                frame.insert(page);
            }

            else{
                // no empty space, replacement required 
                min = 1e7;

                // choose minimum used page
                for(auto k:frame){
                    if(freq[k] <= min){
                        min = freq[k];
                        to_replace = k;
                    }
                }
                cout<<to_replace<<" replace with "<<page<<endl;
                // replace the page 
                frame.erase(to_replace);
                frame.insert(page);
                freq[to_replace] = 0; // erased page
            }   
        }

    cout<<"Current frame : ";
    for(auto k:frame) cout<<k<<" ";

    cout<<endl;
    count++;
    _sleep(400);
    }

    cout<<"Total hits :"<<hit<<endl;
    cout<<"Total missed :"<<miss<<endl;
    float hr = float(hit)/count; 
    cout<<"Hit ratio :"<<hr<<endl;
    cout<<"Miss ratio :"<<1.0 - hr;
    return 0;
}