#include<bits/stdc++.h>
#include<thread>
#include<chrono>
#include<fstream>
using namespace std;
char source[20];
char destination[20];
FILE *fs, *ft;
int res;
string output;
int main(){
    // making three functions for 
    // 1. input
    // 2. copying 
    // 3. termination message
    
    // for input names
    output="";
    res = 0;
    auto f1 = [](){
    cout<<"\nEnter the Name of Source File: ";
    cin>>source;
    fs = fopen(source,"r"); // read pointer
    if(fs==NULL){
        cout<<"\nCould not open source file!";
        res = -1;
    }
    else
        cout<<"***INPUT OPENED SUCCESSFULLY***\n"; 
    };

    // for copying files
    auto f2 = [](){
         ft = fopen("output.txt","w"); // write pointer
         cout<<"***OUTPUT OPENED SUCCESSFULLY***\n";
         return;
    };

    // for termination
    auto f3 = [](){
        char ch = fgetc(fs); // get character
        while(ch != EOF)
        {
            fputc(ch, ft); // put character
            ch = fgetc(fs);
        }
        cout<<"\nFile copied successfully.";
        fclose(fs);
        fclose(ft);
        cout<<endl;
    };
    thread t2(f2);
    thread::id t2_id = t2.get_id();
    thread t1(f1);
    thread::id t1_id = t1.get_id();
    
    t1.join();
    t2.join();
    cout<<"\nInput Thread with id "<<t1_id<<" completed";
    cout<<"\nOutput Thread with id "<<t2_id<<" completed";
    
    if(res!=-1)
    {
    thread t3(f3);
    thread::id t3_id = t3.get_id();
    t3.join();
    cout<<"\nCopy & Termination Thread with id "<<t3_id<<" completed";
    // cout<<"Output :"<<output<<endl;
    }
    else
        {cout<<"\nCould not open file name "<<source<<endl;
        cout<<"\nIncomplete execution.";}
    return 0;
}