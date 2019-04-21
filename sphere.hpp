#ifndef SPHERE_H
#define SPHERE_H

#include "hitable.hpp"
#include "materials.hpp"

class sphere: public hitable
{
    public:
        sphere() {}
        sphere(vec3 cen, float r, material * mat1): center(cen), radius(r), mat(mat1) {};
        virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec)const;
        material* mat;
        vec3 center;
        float radius;
};
bool sphere::hit(const ray& r, float tmin, float tmax, hit_record& rec)const 
{
    vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = dot(oc, r.direction());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;
    if(discriminant > 0)
    {
        float temp = (-b - sqrt(discriminant))/a;
        if(temp < tmax && temp > tmin)
        {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) /radius;
            rec.mat_ptr = mat;
            return true;
        }
        temp = (-b + sqrt(discriminant))/a;
        if(temp < tmax && temp > tmin)
        {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center)/radius;
            rec.mat_ptr = mat;
            return true;
        }
    }
    return false;
}
#endif