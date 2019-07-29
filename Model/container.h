#ifndef CONTAINER_H
#define CONTAINER_H

#include <utility>

template <class T>
class Container {

public:
    typedef T* iterator;

    Container();
    Container(unsigned sz);

    void reserve(int n, unsigned offset = 0);
    unsigned size() const;
    unsigned capacity();
    bool empty();


    void push_back(const T& item);
    void push_back(T&& item);

    void push_front(const T& item);
    void push_front(T&& item);

    iterator begin() const;
    iterator end() const;

    T& back();
    const T& back() const;

    T& front();
    const T& front() const;

    T* data() noexcept;
    const T* data() const noexcept;

    T& at(unsigned index);
    const T& at(unsigned index) const;

    T& operator[](unsigned index);
    const T& operator[](unsigned index) const;

    void clear();
    void erase(unsigned index);
    void erase(const T& item);

private:
    unsigned _capacity;
    unsigned _size;
    T* _data;
};

template<typename T>
Container<T>::Container() {
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template<typename T>
Container<T>::Container(unsigned sz) {
    reserve(sz);
    _size = sz;
}

template <class T>
void Container<T>::reserve(int n, unsigned offset) {
    T* newArr = new T[n];

    for(unsigned i = offset; i < _size; ++i) {
        newArr[i] = _data[i];
    }

    if (_data != nullptr) {
        delete [] _data;
    }

    _data = newArr;
    _capacity = n;
}

template<class T>
unsigned Container<T>::size() const {
    return _size;
}

template<class T>
unsigned Container<T>::capacity() {
    return _capacity;
}

template<class T>
bool Container<T>::empty() {
    return _size == 0;
}

template <class T>
void Container<T>::push_back(const T& item) {
  if (_size == _capacity) {
      if (_capacity == 0) {
        reserve(1);
      }
      else {
        reserve(2 * _capacity);
      }
    }

  _data[_size] = item;
  ++_size;
}

template <class T>
void Container<T>::push_back(T&& item) {
  if (_size == _capacity) {
      if (_capacity == 0) {
        reserve(1);
      }
      else {
        reserve(2 * _capacity);
      }
    }

  _data[_size] = std::move(item);
  ++_size;
}

template <class T>
void Container<T>::push_front(const T& item) {
  if (_size == _capacity) {
      if (_capacity == 0) {
        reserve(1);
      }
      else {
        reserve(2 * _capacity, 1);
      }
    }

  _data[0] = item;
  ++_size;
}

template <class T>
void Container<T>::push_front(T&& item) {
  if (_size == _capacity) {
      if (_capacity == 0) {
        reserve(1);
      }
      else {
        reserve(2 * _capacity, 1);
      }
    }

  _data[0] = std::move(item);
  ++_size;
}

template<class T>
typename Container<T>::iterator Container<T>::begin() const {
    return _data;
}

template<class T>
typename Container<T>::iterator Container<T>::end() const {
    return _data+_size;
}

template<class T>
T& Container<T>::back() {
    return _data[_size - 1];
}

template<class T>
const T& Container<T>::back() const {
    return _data[_size - 1];
}

template<class T>
T& Container<T>::front() {
    return _data[0];
}

template<class T>
const T& Container<T>::front() const {
    return _data[0];
}

template<class T>
T* Container<T>::data() noexcept {
    return _data;
}

template<class T>
const T* Container<T>::data() const noexcept {
    return _data;
}

template<class T>
T& Container<T>::at(unsigned index) {
    return _data[index];
}

template<class T>
const T& Container<T>::at(unsigned index) const {
    return _data[index];
}

template<class T>
T& Container<T>::operator[](unsigned index) {
    return _data[index];
}

template<class T>
const T& Container<T>::operator[](unsigned index) const {
    return _data[index];
}

template<class T>
void Container<T>::clear() {
    delete [] _data;
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template<class T>
void Container<T>::erase(unsigned index) {
    for (unsigned i = index; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }

    --_size;
}

template<class T>
void Container<T>::erase(const T &item) {
    for (int i = 0; i < _size; ++i) {
        if (_data[i] == item) {
            erase(i);
            return;
        }
    }
}

#endif // CONTAINER_H
