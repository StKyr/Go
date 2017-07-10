#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <cstdlib>


void _assertNotNull(void * obj, std::ostream out = std::cerr){
        if (obj == NULL){
            out << "Object "<<obj<<" is NULL."<< std::endl;

            exit(666); // todo: change exit to an exception probably
        }
    }

#endif // UTIL_H
