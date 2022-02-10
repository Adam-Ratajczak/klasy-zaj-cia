#pragma once

#include <ostream>
class Color{
    struct int_color{
        unsigned r, g, b, a;
        int_color(unsigned tr, unsigned tg, unsigned tb, unsigned ta) : r(tr), g(tg), b(tb), a(ta){}

        friend std::ostream& operator<<(std::ostream& out, int_color x){
            return out << "rgb(" << x.r << ", " << x.g << ", " << x.b << ", " << x.a << ")";
        }
    };

public:
    Color() : m_r(.0), m_g(.0), m_b(.0), m_a(1), m_bits(8){}
    Color(double r, double g, double b, double a = 1) : m_r(r), m_g(g), m_b(b), m_a(a), m_bits(8){}
    Color(unsigned bits, double r, double g, double b, double a = 1) : m_r(r), m_g(g), m_b(b), m_a(a), m_bits(bits){}

    void setOpacity(unsigned t_alpha);

    int_color toIntegerValues();
    void fromIntegerValues(unsigned r, unsigned g, unsigned b, unsigned a = 255);

    friend std::ostream& operator<<(std::ostream& out, Color x){
        if(x.m_a == 1)
            return out << "rgb(" << x.m_r << ", " << x.m_g << ", " << x.m_b << ")";
        return out << "rgb(" << x.m_r << ", " << x.m_g << ", " << x.m_b << ", " << x.m_a << ")";
    }

private:
    double m_r, m_g, m_b, m_a;
    unsigned m_bits;
};