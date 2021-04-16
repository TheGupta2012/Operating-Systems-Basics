#include<bits/stdc++.h>
#include<windows.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    
    cout<<"Program to simulate SECOND CHANCE ALGORITHM\n";
    int f_size,len;
    cout<<"Enter frame size : ";
    cin>>f_size;
    list <int> frame;
    set <int> frame_copy;
    map <int,bool> reference;
    cout<<"Enter the number of page references : ";
    cin>>len;
    cout<<"Simulating pages...\n";
    int c;
    list<int>::iterator it2;

    bool found;
    int hit,miss,count,page,to_replace;
    hit = count = miss = 0;
    while(len--){

        page = rand()%9 + 1;
        // page was referenced
        reference[page] = 1;

        if(frame_copy.find(page) != frame_copy.end()){
            cout<<"Hit! "<<page<<" found in frame\n";
            hit++;
        }
        else{
            miss++;


            if(frame.size() != f_size){
                // fifo insertion
                frame.push_back(page);
                frame_copy.insert(page);
            }

            else{

                // replacement needs to be done 
                found = false;
                auto it = frame.begin();
                while(found == false){

                    if(reference[*it] == 1){
                        reference[*it] = 0; 
                        //second chance given 
                        it++;
                        if(it==frame.end()) // loop back
                            it = frame.begin();
                    }
                    // found a page 
                    else{
                        found = true;
                        to_replace = *it;

                        //it2 is the iterator pointing to the 
                        // element before which we want to insert 
                        // new page 

                        it2 = frame.erase(it);
                        frame.insert(it2,page);

                        // update the copy
                        frame_copy.erase(to_replace);
                        frame_copy.insert(page);
                    }
                }

                cout<<to_replace<<" was replaced by "<<page<<endl;
            }
        }

    cout<<"Current frame : ";
    for(auto k:frame) cout<<k<<" ";
    cout<<endl;

    cout<<"Reference : ";
    for(auto k:frame) cout<<reference[k]<<" ";
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