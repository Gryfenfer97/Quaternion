#pragma once
#include <type_traits>
#include <concepts>

namespace quaternion{

    namespace internal{
        template<typename T>
        concept Number = std::is_integral_v<T> || std::is_floating_point_v<T>;
    }
    template<internal::Number T>
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

        constexpr Quaternion<T>& operator+=(const T& rhs);
        constexpr Quaternion<T>& operator-=(const T& rhs);
        constexpr Quaternion<T>& operator*=(const T& rhs);
        constexpr Quaternion<T>& operator/=(const T& rhs);

        constexpr Quaternion<T>& operator=(const Quaternion<T>& x);
        constexpr Quaternion<T>& operator=(const T& x);

        constexpr T a() const{return m_a;}
        constexpr T b() const{return m_b;}
        constexpr T c() const{return m_c;}
        constexpr T d() const{return m_d;}
    };

    template<internal::Number T>
    constexpr Quaternion<T> operator+(const Quaternion<T>& val);

    template<internal::Number T>
    constexpr Quaternion<T> operator-(const Quaternion<T>& val);

    template<internal::Number T>
    constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator-(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator/(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const T& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator+(const T& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator-(const Quaternion<T>& lhs, const T& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator-(const T& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const T& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator*(const T& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator/(const Quaternion<T>& lhs, const T& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> operator/(const T& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    constexpr Quaternion<T> conj(const Quaternion<T>& q);

    template<internal::Number T>
    constexpr Quaternion<T> versor(const Quaternion<T>& q);

    template<internal::Number T>
    constexpr Quaternion<T> inv(const Quaternion<T>& q);

    template<internal::Number T>
    constexpr Quaternion<T> exp(const Quaternion<T>& q);

    template<internal::Number T>
    constexpr Quaternion<T> log(const Quaternion<T>& q);

    template<internal::Number T>
    constexpr Quaternion<T> log10(const Quaternion<T>& q);

    template<internal::Number T>
    constexpr Quaternion<T> pow(const Quaternion<T>& x, const Quaternion<T>& y);

    template<internal::Number T, internal::Number U>
    constexpr Quaternion<T> pow(const Quaternion<T>& q, const U& x);

    template<internal::Number T>
    constexpr Quaternion<T> sqrt(const Quaternion<T>& q);

    template<internal::Number T, internal::Number U>
    constexpr T geodesicNorm(const Quaternion<T>& p, const Quaternion<U>& q);

    template<internal::Number T>
    bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template<internal::Number T>
    bool operator!=(const Quaternion<T>& lhs, const Quaternion<T>& rhs);


    namespace literals{
        constexpr Quaternion<int> operator""_i(unsigned long long arg);

        constexpr Quaternion<int> operator""_j(unsigned long long arg);

        constexpr Quaternion<int> operator""_k(unsigned long long arg);

        constexpr Quaternion<float> operator""_i(long double arg);

        constexpr Quaternion<float> operator""_j(long double arg);

        constexpr Quaternion<float> operator""_k(long double arg);
    }

}

#include "quaternion.tpp"
