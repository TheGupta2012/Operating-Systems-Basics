#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
using namespace std;
typedef vector<int> vi;
int main(){

    /*
    Least Recently use page replacement algorithm
    */

   cout<<"LEAST RECENTLY USED PAGE REPLACEMENT ....\n";
   cout<<"Please enter the page request queue ( -1 to exit ) :\n";
    int miss,hits;
    hits = miss = 0;
    vi pages;
    int f_size;
    set<int> frame;

    cout<<"Enter the frame size of the system :";
    cin>>f_size;
    int ele;
    while(ele!=-1){
        cin>>ele;
        if(ele == -1) break;
        
        pages.pb(ele);
    }
    // GOALS 
    // 1.Find the number of page faults encountered 
    // 2.Find the hit rate and miss rate 
    int c = 0;
    map< int,int > indices; 
    int i,min_ind;
    for(auto k:pages){

        indices[k] = c;
        // if frame contains element 

        // hit 
        if(frame.find(k) != frame.end()){
            // got a hit 
            cout<<"\nHit! Page "<<k<<" found in the frame.";
            hits++;
            c++;
            continue;
        }
        
// 
        
        //else 
        miss++;
        // frame does not have the page
        if(frame.size()!= f_size){
            // atleast 1 page can be appended to the frame 
            frame.insert(k);
            // if I found ;the page, then it is not a page fault 

        }
        else{
            // element has not been found in the frame 

            
            // Frame is full 
            
                min_ind = 1e6;
                for(auto j:frame){
                    // get the minimum index of that page reference in the current queue
                    i = indices[j];
                    if(i < min_ind){
                        // get the minimum index element to replace from the 
                        // o frame 
                        ele = j;
                        min_ind = i;
                    }
                }

                // at this point I have the minimum index element 
                cout<<endl<<ele<<" is replaced with "<<k;
                // replace it 
                frame.erase(ele);
                indices.erase(ele);
                // insert the current page 
                frame.insert(k);
            }
        

    c++;
    cout<<endl;
    cout<<"Current Frame :\n";
    for(auto k:frame) cout<<k<<" ";
    
    }

    cout<<"\nNumber of misses :"<<miss<<endl;
    cout<<"Number of hits :"<<hits<<endl;
    float hr = float(hits)/(hits + miss);
    cout<<"The hit ratio of the algorithm :"<<hr<<endl;
    cout<<"Miss ratio of the algorithm :"<<1.0 - hr;

    return 0;

}
