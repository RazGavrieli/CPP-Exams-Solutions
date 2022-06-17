/**
 * @file Q4.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. The function sort (that is in the STL and included using #include <algorithm>) attempts to use the deafult compartor operator '<' on the type that the vector contains. 
 * So the error occures in a file that someone else wrote (STL) and the problem itself lies in the struct person that should have operator< function.
 * 
 * b. We added operatir< into struct person. 
 * c. We added lambda expression that compare the ages of Person
 */


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;

    bool operator<(const Person& other) {
        return this->age<other.age;
    }
};


int main() {
vector<Person> unsorted { {"bbb",11}, {"aaa",33}, {"ddd",22}, {"CCC",44}};
vector<Person> sorted_by_age = unsorted; 
sort (sorted_by_age.begin(), sorted_by_age.end()); 
//sort (sorted_by_age.begin(), sorted_by_age.end(), [](const Person& lhs, const Person& rhs) { return lhs.age<rhs.age;});  // < Uncomment this for c

for (Person p: sorted_by_age)
    cout << p.age << " ";
}