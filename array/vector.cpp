#include<iostream>
#include<vector>
using namespace std;


int main(){

//   vector<int> vec = {1,2,3};

//     vector<char> charVec = {'a','b','c'};
//   vector<int> vec(3,0);


    // for(char i : charVec){
    //     cout<<i<<endl;
    // }


    vector<int> vec;


    cout<<"size = "<<vec.size()<<endl;

    vec.push_back(23);
    vec.push_back(24);
    vec.push_back(25);


    //     for(int i : vec){
    //     cout<<i<<endl;
    // }

    cout<<"size = "<<vec.size()<<endl;


    vec.pop_back(); //deletes element from last

    
    //     for(int i : vec){
    //     cout<<i<<endl;
    // }

    cout<<"size = "<<vec.size()<<endl;

    cout<<vec.front()<<endl;;
    cout<<vec.at(1);

    return 0;
}