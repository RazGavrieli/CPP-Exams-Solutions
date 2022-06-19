/**
 * @file Q3.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. XX::bb, XX::cc -> Only BB and CC are virtual AND IMPLEMENTED. (dd is pure virtual and not implemented)
 * b. YY::bb, YY::cc, YY::dd, YY::ee -> All of which are virtual and implemented.
 * c. XX::aa, YY::bb, YY::cc, YY::dd, XX::ee
 * d&e. Not in the syllabus 
 */
class XX { 
    public:
    void aa() {} 
    virtual void bb() {} 
    virtual void cc() {} 
    virtual void dd ()=0; 
    static void ee() {}
};
class YY: public XX { 
    public:
    void aa() {} 
    virtual void bb() {} 
    void cc() {} 
    void dd() {}
    virtual void ee() {} 
}; 
int main() {
    XX* zz = new YY(); 
    zz->aa(); 
    zz->bb(); 
    zz->cc(); 
    zz->dd(); 
    zz->ee(); 
    return 0;
}
