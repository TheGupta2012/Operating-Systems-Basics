#include<bits/stdc++.h>
#define tr(v,it) for(auto it = v.begin();it!=v.end();it++)
using namespace std;
int main(){
    ios::sync_with_stdio(0);

    cout<<"Program to simulate ENHANCED SECOND CHANCE ALGORITHM\n";
    int f_size,len;
    cout<<"Enter frame size : ";
    cin>>f_size;
    list <int> frame;
    set <int> frame_copy;
    map <int,bool> reference;
    map <int,bool> modify;
    cout<<"Enter the number of page references : ";
    cin>>len;
    cout<<"Simulating pages...\n";
    int c;
    list<int>::iterator it2;

    bool found;
    int hit,miss,count,page,to_replace,write,bit;
    hit = count = miss = 0;
    while(len--){

        page = rand()%9 + 1;
        cout<<"Page is :"<<page;
        
        write = rand()%2;

        //change modify bit
        if(write == 0) cout<<", Reading done...\n";
        else cout<<", Writing done...\n";
        modify[page] = write;

        // page was referenced
        reference[page] = 1;

        // page found
        if(frame_copy.find(page) != frame_copy.end()){
            cout<<"Hit! "<<page<<" found in frame\n";
            hit++;
        }

        //page not found
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
                 // 0,0 , then 0,1
                int c = 0;
                bit = 0;
                while(found == false)
                {       
                    // need to loop twice to for a bit 
                    // to incorporate the second chance
                        if(c == 2) {
                            bit = 1-bit;
                            c = 0; 
                        }
                        c++;
                        // now iterate the list 
                        tr(frame,it){
                            if(reference[*it] == 1){
                                // give a second chance 
                                reference[*it] = 0;
                            }
                            else{

                                if(modify[*it] == bit){
                                    // found a target 
                                    found = true;
                                    to_replace = *it;

                                    it2 = frame.erase(it);
                                    frame.insert(it2,page);

                                    // update the copy 
                                    frame_copy.erase(to_replace);
                                    frame_copy.insert(page);

                                    // update references
                                    reference[to_replace] = 0;
                                    modify[to_replace] = 0;
                                    
                                    break;
                                }

                            }
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
    cout<<"Modify : ";
    for(auto k:frame) cout<<modify[k]<<" ";
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