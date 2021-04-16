#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main(){
    pid_t x = fork();
    pid_t y = fork();
    if(x > 0 && y > 0)
    {cout<<"In the parent function of both :\n";
    cout<<"Current x and y are :"<<x<<","<<y<<endl;}
    else if(x==0 && y>0){
        cout<<"In the child process x\n";
    cout<<"Current x and y are :"<<x<<","<<y<<endl;}
    
    else if(y==0 && x>0){
    cout<<"In the child process y\n";
    cout<<"Current x and y are :"<<x<<","<<y<<endl;
    }
    else{
    cout<<"In the child's child\n";
    cout<<"Current x and y are :"<<x<<","<<y<<endl;}
        
    return 0;
}
