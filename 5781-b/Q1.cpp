/**
 * @file Q1.cpp
 * @author Raz Gavrieli
 * @brief 
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

void printKMax(vector<double> input, int k) {
    deque<double> currK;
    for (size_t i = 0; i < k; i++) // insert the first K elements of input to currK deque.
    {
        currK.push_back(input.at(i));
    }
    vector<double> res; 
    auto it = max_element(currK.begin(), currK.end());
    double currMax = *it;
    res.push_back(currMax);

    for (size_t i = k; i < input.size(); i++)
    {
        double popped = currK.front();
        currK.pop_front();

        if (input.at(i)>res.at(i-k)) {
            res.push_back(input.at(i));
        } else if (popped==res.at(i-k)) {
            it = max_element(currK.begin(), currK.end());
            res.push_back(*it);
        } else {
            res.push_back(res.at(i-k));
        }
        currK.push_back(input.at(i));

    }

    for (size_t i = 0; i < res.size(); i++)
        cout << res.at(i) << " ";
    cout << endl; 
}

int main() {
    printKMax({11,22,33,44,33,22,11}, 3);
    printKMax({55,44,33,22,11,22,33,44,55}, 4);
}