#include "vec3.hpp"
std::istream& operator>>(std::istream &is, vec3 &t)
{
    is >> t[0] >> t[1] >> t[2];
    return is;
}
std::ostream& operator<<(std::ostream &os, vec3 &t)
{
    os << t[0] << " " << t[1] << " " << t[2];
    return os;
}
std::istream& operator>>(std::istream &is, vec3Int &t)
{
    is >> t.data[0] >> t.data[1] >> t.data[2];
    return is;
}
std::ostream& operator<<(std::ostream &os, vec3Int &t)
{
    os << t.data[0] << " " << t.data[1] << " " << t.data[2];
    return os;
}
vec3 unit_vector(vec3 v)
{
    if(v.length() == 0)
    {
        std::cout << "fail divide in zero" << std::endl;
    }
    return v /= v.length();
}
float dot(const vec3& v1, const vec3& v2)
{
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}
vec3 reflect(const vec3& v, const vec3& n)
{
    return v - n*2*dot(v, n);
}