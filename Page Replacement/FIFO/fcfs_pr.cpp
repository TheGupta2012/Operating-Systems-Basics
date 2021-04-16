#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cout<<"Program to simulate First in First out page replacement algorithm\n";
    int frame_size;
    cout<<"Enter the frame size in your system :";
    cin>>frame_size;

    set<int> frame;
    map<int,int> indices;
    int hits,misses;
    hits = misses = 0;
    // Page queue
    cout<<"Enter the page request queue (-1 to exit ):\n";
    int c = 0,min,to_replace,page;
    vector<int> pages;
    pages.reserve(100);

    while(true){
        cin>>page;
        if(page == -1) break;
        pages.push_back(page);
    }

    // Evaluate 
    for(auto page : pages){
        
        // associate earliest time stamps
        if(indices.find(page) == indices.end()){
            indices[page] = c;
        }

        // check if the page is in the frame or not 
        if(frame.find(page)!= frame.end()){
            // page is found 
            hits++;
            cout<<"Hit! "<<page<<" found in frame\n";
        }
        else{
            misses++;
            if(frame.size()!= frame_size){
                // no replacement required , just insert 
                frame.insert(page);
                cout<<"Free frame available!\n";
            }
            else{
                // replacement required 
                min = 1e5;
                for(auto k:frame){
                    if(indices[k] < min){
                        min = indices[k];
                        to_replace = k;
                    }
                }

                cout<<to_replace<<" is replaced by "<<page<<endl;

                // page is removed
                frame.erase(to_replace);
                indices.erase(to_replace);
                frame.insert(page);

            }
        }

        cout<<"Current Page Frame :\n";
        for(auto k:frame) cout<<k<<" ";
    
        cout<<endl;

        c++;

    }
    // Hit and miss ratio
    cout<<"Total numbers of hits :"<<hits<<endl;
    cout<<"Total number of misses :"<<misses<<endl;

    float hr,mr;
    hr = float(hits)/(c);
    mr = 1.0 - hr;
    cout<<"Hit ratio :"<<hr<<endl;
    cout<<"Miss ratio :"<<mr<<endl;

    return 0;
}