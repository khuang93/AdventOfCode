#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

bool react(char a, char b){
    return (a-b==32 || b-a==32);
}

void readIn(ifstream& in, char& var, int letter){
    do{
        in >> var;
    }while(var==letter || var == letter+32);
}

int checkEndLength(string fileName, int letter){
    cout<<(char)letter<<endl;
    int res = 0;
    ifstream in;
    in.open(fileName);
    char curr;
    char next;
    stack<char> output;
    
    readIn(in, curr, letter);

    while(!in.eof()){
        readIn(in, next, letter);

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
            readIn(in, curr, letter);
        }
    }

    res = output.size();
    // std::cout<<output.size();
    // while(!output.empty()){
    //      std::cout<<output.top();
    //     output.pop();
    // }


    return res;
}

int main(){


int maxLength = 2147483647;

for(int i = 65; i <= 90; i++){
    int tmp = checkEndLength("input.txt", i);
    cout<<tmp<<endl;
    if(maxLength>tmp) maxLength = tmp;
}


cout<< endl<<"best = " <<maxLength<<endl;
   

return 0;
}