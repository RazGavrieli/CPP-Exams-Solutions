/**
 * @file Q6.cpp
 * @author Raz Gavrieli
 * @brief 
 */
#include <memory>
#include <iostream>
using namespace std;
template<typename T> 
class Stack {
        struct Node{ 
            T value;
            shared_ptr<Node> next;
        };
    shared_ptr<Node> head = nullptr;
    public:
        class Iterator {
            shared_ptr<Node> curr;
        public:
            Iterator(shared_ptr<Node> newp) : curr(newp) {}
            bool operator!=(const Iterator& other)  {return curr!=other.curr;}
            Iterator& operator++()  {curr=curr->next; return *this;}
            Node& operator*() const {return *curr;}

        };
        friend ostream& operator<<(ostream& out, Node self) {
            out << self.value;
            return out;
        }
        void push(T v){
            shared_ptr<Node> newNode = make_shared<Node>();
            newNode->value=v;
            newNode->next = head;
            head = newNode;
        }
        T pop() {
            shared_ptr<Node> nodeToDel = head;
            T val = head->value;
            head = head->next;
            return val;
        }

        ~Stack() {
            while (head!=nullptr) { pop(); }
        }

        void del(T v) {
            auto it = begin();
            while (it!=end()) {
                if ((*it).value==v) {
                    (*it).next = nullptr;
                    break;
                }
                ++it;
            }
        }
        Iterator begin() {return Iterator(head);}
        Iterator end() { return Iterator(nullptr);} 
};


int main() {
    Stack<int> s;
    for (int i=1;i<5;i++) s.push(i);
    for(auto& i: s) cout << i << " ";
    cout<<endl;
    s.del(2);
    for(auto& i: s) cout << i << " ";
    cout<<endl;
}