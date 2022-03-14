
#include<bits/stdc++.h>
using namespace std;

const int TOTAL_ELEMENTS = 10e6;
const int MAXIMUM = 100;
int main(){
    srand(time(0));
    ofstream outfile;
    outfile.open("uniform_dist.csv");
    for(int i = 0; i < TOTAL_ELEMENTS; i++){
        outfile << rand()%MAXIMUM << "\n";
    }
    outfile.close();
    
    
    return 0;
}
