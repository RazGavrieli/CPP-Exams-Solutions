/**
 * @file Q2.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. In line 3 the default assignment uses the 'new' keyword to allocate on the heap. 
 * In line 4, before the program enters the constructor itself, it allocates to the default assignment and then alloactes again inside the constructor.
 * Use initializaion list in line 4 to fix this. (Initializaion lists get called before default assignments).
 * b. We need to add copy constructor, copy assignment operator. (and destructor which is already in the implementation).
 * c. We need to add default constructor. 
 */

class Vector {
    int m_size=0;
    int* m_arr=new int[10];
        public:
    Vector(int size) : m_size(size), m_arr(new int[size]) {}
    Vector() = default; // << added deafult constructor
    Vector(const Vector& other): m_size(other.m_size), m_arr(new int[m_size]) {
        for (int i = 0; i < m_size; i++)
        {
            m_arr[i] = other.m_arr[i];
        }
        
    }
    Vector& operator=(const Vector& other) {
        if (this!=&other) {
            delete[] m_arr;
            m_size = other.m_size;
            m_arr = new int[m_size];
            for (int i = 0; i < m_size; i++)
            {
                m_arr[i] = other.m_arr[i];
            }
        }
        return *this;
    }

    ~Vector() { delete[] m_arr; } 
};

int main() {
    Vector matrix[10];
}