#include "Color.hpp"
#include <cmath>

Color::int_color Color::toIntegerValues(){
    unsigned s = (1 << m_bits) - 1;
    return int_color(s * m_r, s * m_g, s * m_b, s * m_a);
}

void Color::fromIntegerValues(unsigned r, unsigned g, unsigned b, unsigned a){
    unsigned s = (1 << m_bits) - 1;
    m_r = (double)r / s;
    m_g = (double)g / s;
    m_b = (double)b / s;
    m_a = (double)a / s;
}

void Color::setOpacity(unsigned int t_alpha){
    unsigned s = (1 << m_bits) - 1;
    m_a = (double)t_alpha / s;
}
