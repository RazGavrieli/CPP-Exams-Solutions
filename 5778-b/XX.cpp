#include "XX.h"

int XX::val() const {
    return myval;
}

std::ostream& operator<< (std::ostream& out, const XX& xx) {
    out << xx.myval;
    return out;
}