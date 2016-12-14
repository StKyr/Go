#ifndef UITL_H
#define UITL_H

#include <ostream>
#include <cstdlib>

namespace util{

    void _assertNotNull(void * obj, ostream out = std::cerr){
        if (obj == nullptr){
            out << "Object "<<obj<<" is NULL."<< std::endl;

            exit(666); // todo: change exit to an exception probably
        }
    }
}

#endif // UITL_H
