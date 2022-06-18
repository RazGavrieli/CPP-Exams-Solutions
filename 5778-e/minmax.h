#include <algorithm>

template<typename it1, typename it2> 
void minmax(it1 begin1, it1 end1, it2 begin2, it2 end2) {
    if (begin1==end1 && begin2 == end2) {
        return;
    }
    if (begin1==end1) {
        throw;
    } else if (begin2==end2) {
        throw;
    }

    if (*begin1>*begin2) {
        std::swap(*begin1, *begin2);
    }
    begin1++; begin2++;
    minmax(begin1, end1, begin2, end2);
}