#pragma once //include guard
#include <utility>
#include <type_traits>
#include <cstddef>


namespace custom {
    //default deleter functor for single objects
    template <typename T>
    struct default_delete {
        void operator()(T* ptr) const {
            delete ptr;
        }
    };

    //default deleter specialization for arrays
    template <typename T>
    struct default_delete<T[]> {
        void operator()(T* ptr) const {
            delete[] ptr;
        }
    };

    
}