/**
 * @file Q5.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. minmax_element returns a pair of iterators. So, @param min and @param max are instances of Iterator and not of Person.
 * b. In the main function we need to use the dereference operator ("*"). 
 * c. In order to print an instance of Person we need to overload the operator <<. 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Person {
    private:
        string _name;
        int _age;
    public:
        Person(const string& name, int age) : _name(name), _age(age) {}
        int age() const { return _age; }
        string name() const { return _name; } 
};
ostream& operator<<(ostream& out, const Person& self) {
    out << self.name() << ", " << self.age();
    return out;
}
vector<Person> v {{"Avi", 11},{"Beni", 22},{"Chana", 44},{"Dani", 33}};
int main() {
    auto [min, max] = minmax_element(v.begin(), v.end(), // Works from CPP 17+
    //auto m = minmax_element(v.begin(), v.end(), 
    [](Person A, Person B){return A.age()<B.age();});

    // cout << "The youngest persin is: " << *m.first << endl;
    // cout << "The oldest persin is: " << *m.second << endl;
    cout << "The youngest persin is: " << *min << endl;
    cout << "The oldest persin is: " << *max << endl;
    return 1;
}