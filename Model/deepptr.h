#ifndef DEEPPTR_H
#define DEEPPTR_H

class ReferenceCount {
public:
    ReferenceCount() : _ref_count(0) {

    }

    void Increment() {
        ++_ref_count;
    }

    int Decrement() {
        return --_ref_count;
    }

private:
    int _ref_count;
};

template <typename T>
class DeepPtr {

public:
    DeepPtr();
    DeepPtr(T* object);
    virtual ~DeepPtr();
    DeepPtr(const DeepPtr<T>& other);
    DeepPtr<T>& operator=(const DeepPtr<T>& other);
    T& operator*();
    T* operator->();
    const T* operator->() const;
    bool isValid() const;

//private:
    T* _object;
    ReferenceCount* _reference_count;
};

template <typename T>
DeepPtr<T>::DeepPtr() : _object(nullptr), _reference_count(nullptr) {

}

template <typename T>
DeepPtr<T>::DeepPtr(T* object) : _object(object) , _reference_count(new ReferenceCount()) {
    _reference_count->Increment();
}

template <typename T>
DeepPtr<T>::~DeepPtr() {
    if (_reference_count) {
        if (_reference_count->Decrement() <= 0) {
            delete _reference_count;
            delete _object;
            _reference_count = nullptr;
            _object = nullptr;
        }
    }
}

template <typename T>
DeepPtr<T>::DeepPtr(const DeepPtr<T>& other) : _object(other._object), _reference_count(other._reference_count) {
    _reference_count->Increment();
}

template <typename T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr<T>& other) {
    if (this != &other) {
        if (_reference_count && _reference_count->Decrement() == 0) {
            delete _reference_count;
            delete _object;
        }

        _object = other._object;
        _reference_count = other._reference_count;
        _reference_count->Increment();
    }
    return *this;
}

template <typename T>
T& DeepPtr<T>::operator*() {
    return *_object;
}

template <typename T>
T* DeepPtr<T>::operator->() {
    return _object;
}

template <typename T>
const T* DeepPtr<T>::operator->() const {
    return _object;
}

template<typename T>
bool DeepPtr<T>::isValid() const {
    return _object != nullptr;
}

#endif

