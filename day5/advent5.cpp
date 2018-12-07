#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

bool react(char a, char b){
    return (a-b==32 || b-a==32);
}

int main(){

ifstream in;


in.open("input.txt");
char curr;
char next;

    stack<char> output;

    in >> curr;

    while(!in.eof()){
        in >> next;
        // cout<<curr<<next<<endl;
        if(!react(curr, next)){
            if(!output.empty()&&react(curr, output.top())){
                output.pop();
                // in>>curr;
                curr=next; 
                // cout<<curr<<endl;
            }else{
                output.push(curr);
                curr=next;  
            }     
        }else if(react(curr,next)){
            in>>curr;
        }
    }

    std::cout<<output.size();
    while(!output.empty()){
        std::cout<<output.top();
        output.pop();
    }

return 0;
}