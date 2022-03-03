# Quaternion

Quaternion is an open-source modern C++ library that allow you to safely manipulate Quaternions.

# Examples

```cpp
#include <Quaternion/quaternion.hpp>

int main(){
    using namespace quaternion::literals;

    auto q1 = 1 + 2_i + 3_j - 1_k;
    std::cout << q1.b() << std::endl; // print 2
    auto q2 = 1 + 2_k;
    auto q3 = q1 * q2;
    std::cout << q3.d() << std::endl; // print 8
}

```

# Building

```sh
~$ git clone https://github.com/Gryfenfer97/Quaternion
~$ cd Quaternion
~$ conan install . --install-folder-build
~$ cmake . -Bbuild
~$ cmake --build build
```