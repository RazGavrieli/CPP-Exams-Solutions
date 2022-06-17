/**
 * @file Q4.cpp
 * @author Raz Gavrieli
 * @brief 
 * a. Linking error - There is no implementation for plot() function in line 04. Upon linking the linker can't find the vtable (because it doesn't exists). 
 * b. You can declare the function as 'pure virtual', change line 04 to: 'virtual void plot() = 0;' 
 */

int main(int argc, char const *argv[])
{
    return 0;
}
