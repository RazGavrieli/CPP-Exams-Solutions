/**
 * @file Q5.cpp
 * @author Raz Gavrieli
 * @brief 
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int best_sum(vector<int> grades) {
    int max = -1;
    int currsum; 
    int i;
    sort(grades.begin(), grades.end()); 
    do {
        currsum = 0;
        i = 0;
        while (currsum<=48) {
            currsum += grades.at(i);
            i++;
        }
        if (currsum>max) {
            max = currsum;
        }

    } while(next_permutation(grades.begin(), grades.end()));
    return max;
}

int main() {
    cout << best_sum({10,20,30,40,50}) << endl;
    cout << best_sum({50,40,30,20,10}) << endl;
    cout << best_sum({40,50,30,20,10}) << endl;
    cout << best_sum({10,10,32,10,10,33,10,10}) << endl;

}