# Quaternion

Quaternion is an open-source modern C++ library that allow you to safely manipulate Quaternions.

# Examples

```cpp
#include <Quaternion/quaternion.hpp>

int main(){
    auto q1 = 1 + 2_i + 3_j - 1_k;
    std::cout << q1.b() << std::endl; // print 2
    auto q2 = 1 + 2_k;
    auto q3 = q1 * q2;
    std::cout << q3.m_d() << std::endl; // print 8
}

```
