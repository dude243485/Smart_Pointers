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

    //main unique_ptr class
    template <typename T, typename Deleter = default_delete<T>>
    class unique_ptr{
        private: 
        T* m_ptr;
        Deleter m_deleter;

        public:
        //constructor
        explicit unique_ptr(T* p =nullptr, Deleter d = Deleter())
            : m_ptr(p), m_deleter(std::move(d)) {}

        ~unique_ptr() {
            reset () ;
        }
    }

}