#ifndef HITABLE_H
#define HITABLE_H

#include "ray.hpp"

struct hit_record{
    float t;
    vec3 p;
    vec3 normal;
};

class hitable
{
    public:
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};
float dot(const vec3& v1, const vec3& v2)
{
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

#endif