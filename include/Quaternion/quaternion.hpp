#pragma once

namespace quaternion{
    template<typename T>
    class Quaternion{
    private:
        T m_a;
        T m_b;
        T m_c;
        T m_d;

    public:
        constexpr Quaternion(T a = T(), T b = T(), T c = T(), T d = T());
        constexpr T real();
        constexpr Quaternion<T> imag();
        constexpr T norm();

        constexpr Quaternion<T>& operator+=(const Quaternion<T>& rhs);
        constexpr Quaternion<T>& operator-=(const Quaternion<T>& rhs);
        constexpr Quaternion<T>& operator*=(const Quaternion<T>& rhs);
        constexpr Quaternion<T>& operator/=(const Quaternion<T>& rhs);
        
        constexpr Quaternion<T>& operator/=(const T& rhs);
        constexpr Quaternion<T>& operator=(const Quaternion<T>& x);

        constexpr T a() const{return m_a;}
        constexpr T b() const{return m_b;}
        constexpr T c() const{return m_c;}
        constexpr T d() const{return m_d;}
    };

    template<typename T>
    constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template<typename T>
    constexpr Quaternion<T> operator-(const Quaternion<T>& lhs, const Quaternion<T>& rhs);
    
    template<typename T>
    constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template<typename T>
    constexpr Quaternion<T> conj(const Quaternion<T>& q);

    template<typename T>
    bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs);        

}

#include "quaternion.tpp"
