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