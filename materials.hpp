#ifndef MATERIALSHPP
#define MATERIALSHPP

#include "ray.hpp"
#include "hitable.hpp"


class material {
    public:
        virtual bool scatter(const ray& in, const hit_record& rec, vec3& attenuation, ray& scatter) const = 0;
};


vec3 random_in_unit_sphere()
{
    vec3 p;
    do{
        p = vec3( drand48(), drand48(), drand48())*2.0f - vec3(1.0f, 1.0f, 1.0f);
    } while(p.squared_lenght() >= 1.0f);
    return p;
}

class lambertian: public material
{
    public:
        lambertian(const vec3& a): albedo(a){}
        virtual bool scatter(const ray& in, const hit_record& rec, vec3& attenuation, ray& scattered) const 
        {
            vec3 target = rec.p + rec.normal + random_in_unit_sphere();
            scattered = ray(rec.p, target-rec.p);
            attenuation = albedo;
            return true;
        }
        vec3 albedo;
};

class metal : public material
{
    public:
        metal(const vec3& a): albego(a){}
        virtual bool scatter(const ray& in, const hit_record& rec, vec3& attenuation, ray& scattered) const
        {
            vec3 reflected = reflect(unit_vector(in.direction()), rec.normal);
            scattered = ray(rec.p, reflected);
            attenuation = albego;
            return (dot(scattered.direction(), rec.normal) > 0);
        }
        vec3 albego;
};
#endif