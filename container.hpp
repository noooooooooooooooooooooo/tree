//#pragma once

#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__

template <class T>
class Container
{public:
    // Виртуальные методы, будут реализованы далее 
    virtual void insert(int value) = 0;
    virtual bool exists(int value) = 0;
    virtual void remove(int value) = 0;
    // Это потом заменим на перегруженный оператор <<
    virtual void print() = 0;

    // Виртуальный деструктор
    virtual ~Container();
};

template <class T>
Container<T>::~Container() { }

#endif //__CONTAINER_HPP__