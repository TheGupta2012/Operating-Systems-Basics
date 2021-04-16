#include<bits/stdc++.h>
#define all(c) c.begin(),c.end()
using namespace std;
int main(){
    ios::sync_with_stdio(0);

    cout<<"Program to simulate BEST FIT CONTIGUOUS MEMORY ALLOCATION\n";
    cout<<"Enter the number of memory blocks available :";
    int n,mem;
    cin>>n;
    // define memory block 
    // {int : memory size }

    multiset <int> mem_blocks;
    multiset <int> used;
    cout<<"Enter available memory blocks : ";
    for(int i=0;i<n;i++){
        cin>>mem;
        mem_blocks.insert(mem);
    }
    
    // get the memory allocation array 
    int internal_frag  = 0;
    cout<<"\nEnter the memory requirement queue (-1 to exit):";
    while(true){
        cout<<"Available locations :";

        for(auto k:mem_blocks) 
            cout<<k<<" ";
        cout<<endl;
        cout<<"Required :";

        cin>>mem;
        if(mem == -1) break;

        else{
            // find upper & lower bound in the not used elements 
            auto it1 = mem_blocks.upper_bound(mem);
            auto it2 = mem_blocks.lower_bound(mem);
            if(it1 == mem_blocks.end() && *it2 != mem){
                cout<<"Request too large! Please enter valid request\n";
            } 
            else{
                
                if(*it2 == mem){

                    // best fit.
                    cout<<*it2<<" was allocated to the block.\n";
                    mem_blocks.erase(it2);
                    used.insert(*it2);
                    cout<<"Fragmentation :"<<0<<endl;
                }
                else {
                    cout<<*it1<<" was allocated to the block.\n";
                    mem_blocks.erase(it1);
                    used.insert(*it1);
                    cout<<"Fragmentation :"<<*it1-mem<<endl;
                    internal_frag += (*it1 - mem);
                }


            }
        }
    }

    cout<<"Total internal fragmentation caused :"<<internal_frag<<endl;
    return 0;
}