#include <cmath>
namespace quaternion{
   
    template<typename T>
    constexpr Quaternion<T>::Quaternion(T a, T b, T c, T d) : m_a(a), m_b(b), m_c(c), m_d(d){} 

    template<typename T>
    constexpr T Quaternion<T>::real() {
        return m_a;
    }


    template<typename T>
    constexpr Quaternion<T> Quaternion<T>::imag(){
        return Quaternion(0, m_b, m_c, m_d);
    }

    template<typename T>
    constexpr T Quaternion<T>::norm(){
        return std::sqrt(m_a*m_a + m_b*m_b + m_c*m_c + m_d*m_d);
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator+=(const Quaternion<T>& rhs){
        m_a += rhs.m_a;
        m_b += rhs.m_b;
        m_c += rhs.m_c;
        m_d += rhs.m_d;
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator-=(const Quaternion<T>& rhs){
        m_a -= rhs.m_a;
        m_b -= rhs.m_b;
        m_c -= rhs.m_c;
        m_d -= rhs.m_d;
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& rhs){
        Quaternion temp(
            m_a*rhs.m_a - m_b*rhs.m_b - m_c*rhs.m_c - m_d*rhs.m_d,
            m_a*rhs.m_b + m_b*rhs.m_a + m_c*rhs.m_d - m_d*rhs.m_c,
            m_a*rhs.m_c - m_b*rhs.m_d + m_c*rhs.m_a + m_d*rhs.m_b,
            m_a*rhs.m_d + m_b*rhs.m_c - m_c*rhs.m_b + m_d*rhs.m_a 
        );
        *this = temp;
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator/=(const Quaternion<T>& rhs){
        *this *= conj(rhs)/rhs.norm();
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator+=(const T& rhs){
        *this = Quaternion(m_a + rhs, m_b, m_c, m_d);
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator-=(const T& rhs){
        *this += -rhs; 
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator*=(const T& rhs){
        *this = Quaternion(m_a * rhs, m_b * rhs, m_c * rhs, m_d * rhs);
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator/=(const T& rhs){
        m_a /= rhs;
        m_b /= rhs;
        m_c /= rhs;
        m_d /= rhs;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator=(const Quaternion<T>& rhs){
        m_a = rhs.m_a;
        m_b = rhs.m_b;
        m_c = rhs.m_c;
        m_d = rhs.m_d;
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T>& Quaternion<T>::operator=(const T& x){
        m_a = x;
        m_b = 0; m_c = 0; m_d = 0;
        return *this;
    }

    template<typename T>
    constexpr Quaternion<T> operator+(const Quaternion<T>& val){
        return val; 
    }

    template<typename T>
    constexpr Quaternion<T> operator-(const Quaternion<T>& val){
        return -1 * val;
    }

    template<typename T>
    constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs){
        Quaternion<T> r = lhs;
        r += rhs;
        return r;
    }

    template<typename T>
    constexpr Quaternion<T> operator-(const Quaternion<T>& lhs, const Quaternion<T>& rhs){
        Quaternion<T> r = lhs;
        r -= rhs;
        return r;
    }

    template<typename T>
    constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs){
        Quaternion<T> r = lhs;
        r *= rhs;
        return r;
    }

    template<typename T>
    constexpr Quaternion<T> operator/(const Quaternion<T>& lhs, const Quaternion<T>& rhs){
        Quaternion<T> r = lhs;
        r /= rhs;
        return r;
    }

    template<typename T>
    constexpr Quaternion<T> conj(const Quaternion<T>& q){
        return Quaternion(
            +q.a(),
            -q.b(),
            -q.c(),
            -q.d()
        );
    }

    template<typename T>
    constexpr Quaternion<T> versor(const Quaternion<T>& q){
        return q/q.norm();
    } 

    template<typename T>
    constexpr Quaternion<T> exp(const Quaternion<T>& q){
        auto imag = imag(q);
        auto imaginaryNorm = norm(imag);

        return std::exp(q.real()) * (std::cos(imaginaryNorm) + imag * std::sin(imaginaryNorm) / imaginaryNorm);
    }


    template<typename T>
    constexpr Quaternion<T> log(const Quaternion<T>& q){
        auto imag = imag(q);
        auto imaginaryNorm = norm(imag);
        
        return std::log(imaginaryNorm) + imag * std::acos(q.real()/q.norm()) / imaginaryNorm;
    }

    template<typename T>
    constexpr Quaternion<T> log10(const Quaternion<T>& q){
        return log(q)/log(static_cast<T>(10));
    }

    template<typename T>
    constexpr Quaternion<T> pow(const Quaternion<T>& x, const Quaternion<T>& y){
        return exp(y * log(x));
    }

    template<typename T, typename U> 
    constexpr Quaternion<T> pow(const Quaternion<T>& q, const U& x){
        return exp(q * std::log(x));
    }

    template<typename T>
    constexpr Quaternion<T> sqrt(const Quaternion<T>& q){
        return pow(q, 0.5);
    }

    template<typename T>
    bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs){
        return  lhs.a() == rhs.a() &&
                lhs.b() == rhs.b() &&
                lhs.c() == rhs.c() &&
                lhs.d() == rhs.d();

    }

    template<typename T>
    bool operator!=(const Quaternion<T>& lhs, const Quaternion<T>& rhs){
        return !(rhs == lhs);
    }


}