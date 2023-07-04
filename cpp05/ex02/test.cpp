#include <iostream>

void *operator new(std::size_t size) {
    if (size == 0)
        size++;
    if (void *ptr = std::malloc(size))
        return ptr;
    throw std::bad_alloc{};
}

void operator delete(void *ptr) noexcept {
    std::free(ptr);
}

int main()
{
    int *ptr = new int;
    if (nullptr == ptr)
        std::cout << "Whoops";
    else
        delete ptr;
    return 0;
}