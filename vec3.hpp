#ifndef VEC_3
#define VEC_3

#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

class vec3{
    public:
    float data[3];
    vec3()
    {
        data[0] = 0;
        data[1] = 0;
        data[2] = 0;
    }
    vec3(float d0, float d1, float d2)
    {
        data[0] = d0;
        data[1] = d1;
        data[2] = d2;
    }
    inline float x() const
    {
        return data[0];
    }
    inline float y() const
    {
        return data[1];
    }
    inline float z() const
    {
        return  data[2];
    }
    inline float r() const
    {
        return data[0];
    }
    inline float g() const
    {
        return data[1];
    }
    inline float b() const
    {
        return data[2];
    }

    inline float &x()
    {
        return data[0];
    }
    inline float &y()
    {
        return data[1];
    }
    inline float &z()
    {
        return data[2];
    }
    inline float &r()
    {
        return data[0];
    }
    inline float &g()
    {
        return data[1];
    }
    inline float &b()
    {
        return data[2];
    }
    inline const vec3& operator+() const
    {
        return *this;
    }
    inline vec3 operator-() const
    {
        return vec3(-data[0], -data[1], -data[2]);
    }

    inline vec3 operator/(float t) const
    {
        return vec3(data[0]/t, data[1]/t, data[2]/t);
    }
    inline vec3 operator*(float t) const
    {
        return vec3(data[0]*t, data[1]*t, data[2]*t);
    }

    inline vec3 operator+(const vec3 &v2)const
    {
        return vec3(data[0] + v2.data[0], data[1] + v2.data[1], data[2] + v2.data[2]);
    }
    inline vec3 operator-(const vec3 &v2)const
    {
        return vec3(data[0] - v2.data[0], data[1] - v2.data[1], data[2] - v2.data[2]);
    }

    inline float operator [](int i) const
    {
        return data[i];
    }
    inline float& operator [](int i)
    {
        return data[i];
    }

    inline vec3& operator +=(const vec3 &v2)
    {
        data[0] += v2.data[0];
        data[1] += v2.data[1];
        data[2] += v2.data[2];
        return *this;
    }
    inline vec3& operator -=(const vec3 &v2)
    {
        data[0] -= v2.data[0];
        data[1] -= v2.data[1];
        data[2] -= v2.data[2];
        return *this;
    }
    inline vec3& operator *=(const vec3 &v2)
    {
        data[0] *= v2.data[0];
        data[1] *= v2.data[1];
        data[2] *= v2.data[2];
        return *this;
    }
    inline vec3& operator /=(const vec3 &v2)
    {
        data[0] /= v2.data[0];
        data[1] /= v2.data[1];
        data[2] /= v2.data[2];
        return *this;
    }
    inline vec3& operator *=(const float t)
    {
        data[0] *= t;
        data[1] *= t;
        data[2] *= t;
        return *this;
    }
    inline vec3& operator /=(const float t)
    {
        data[0] /= t;
        data[1] /= t;
        data[2] /= t;
        return *this;
    }

    inline float length() const
    {
        return sqrt(data[0]*data[0] + data[1]*data[1] + data[2]*data[2]);
    }
    inline float squared_lenght() const
    {
        return data[0]*data[0] + data[1]*data[1] + data[2]*data[2];
    }
    inline void make_unit_vector()
    {
        float len = length();
        data[0] /= len;
        data[1] /= len;
        data[2] /= len;
    }
    inline std::string toString() const
    {
        std::stringstream ss;
        ss << int(data[0]);
        ss << " ";
        ss << int(data[1]);
        ss << " ";
        ss << int(data[2]);
        return ss.str();
    }
    inline std::string toString_() const 
    {
         std::stringstream ss;
        ss << float(data[0]);
        ss << " ";
        ss << float(data[1]);
        ss << " ";
        ss << float(data[2]);
        return ss.str();
    }

};
std::istream& operator>>(std::istream &is, vec3 &t);
std::ostream& operator<<(std::ostream &os, vec3 &t);
vec3 unit_vector(vec3 v);
class vec3Int
{
    public:
    int data[3];
    vec3Int()
    {
        data[0] = 0;
        data[1] = 0;
        data[2] = 0;
    }
    vec3Int(int d1, int d2, int d3)
    {
        data[0] = d1;
        data[1] = d2;
        data[2] = d3;
    }
    inline vec3Int& operator =(const vec3 &tmp)
    {
        data[0] = int(tmp.data[0]);
        data[1] = int(tmp.data[1]);
        data[2] = int(tmp.data[2]);
        return *this;
    } 
};
std::istream& operator>>(std::istream &is, vec3Int &t);
std::ostream& operator<<(std::ostream &os, vec3Int &t);

#endif