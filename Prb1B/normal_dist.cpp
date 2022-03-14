
#include<bits/stdc++.h>
using namespace std;

const int TOTAL_ELEMENTS = 10e6;
const int MAXIMUM = 100;
const int NO_OF_SUB_ELEMENTS = 10;
int main(){
    srand(time(0));
    ofstream outfile;
    outfile.open("normal_dist.txt");
    for(int i = 0; i < TOTAL_ELEMENTS; i++){
        int sum = 0;
        for (int j = 0; j < NO_OF_SUB_ELEMENTS; j++)
        {
            sum += rand() % (MAXIMUM / NO_OF_SUB_ELEMENTS);
        }
        outfile<< sum << endl;
    }
    outfile.close();
    return 0;
}

    
