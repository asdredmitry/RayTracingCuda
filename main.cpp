#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "vec3.hpp"
#include "ray.hpp"
#include "hitable.hpp"
#include "sphere.hpp"
#include "hitablelist.hpp"
#include "materials.hpp"
#include "camera.hpp"
using namespace std;
void write_header(ofstream & out, int nx, int ny)
{
    out << "P3" << endl;
    out << nx << " " << ny << endl;
    out << 255 << endl;
}
vec3 color(const ray& r, hitable * world, int depth)
{
    hit_record rec;
    if(world->hit(r, 0.001f, MAXFLOAT, rec))
    {
        vec3 attenuation;
        ray scattered;
        if(depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
        {
            return attenuation*color(scattered, world, depth + 1);
        }
        else 
        {
            return vec3(0.0f, 0.0f, 0.0f);
        }
    }
    else
    {
        vec3 unit_direction = unit_vector(r.direction());
        float t1 = 0.5*(unit_direction.y() + 1.0);
        //return vec3(0.0f, 1.0f, 0.0f);
        return vec3(1.0f, 1.0f, 1.0f)*(1.0 - t1) + vec3(0.5f, 0.7f, 1.0f)*t1;   
    }
}
int main()
{
    ofstream output("Picture.ppm");
    int nx = 2000;
    int ny = 1000;
    int ns = 50;
    write_header(output, nx, ny);
    vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
    vec3 horizontal(4.0f, 0.0f, 0.0f);
    vec3 vertical(0.0f, 2.0f, 0.0f);
    vec3 origin(0.0f, 0.0f, 0.0f);
    hitable *list[5];
    list[0] = new sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.8f, 0.3f, 0.3f)));
    list[1] = new sphere(vec3(0.0f, -100.5f, -1.0f), 100.f, new metal(vec3(0.8f, 0.8f, 0.8f), 0.1f));
    list[2] = new sphere(vec3(1.0f, 0.0f, -1.0f), 0.5f, new metal(vec3(0.5f, 0.5f, 0.5f),0.3f));
    list[3] = new sphere(vec3(-1.0f, 0.0f, -1.0f), 0.5f, new metal(vec3(0.8f, 0.8f, 0.8f), 0.f));
    list[4] = new sphere(vec3(0.0f, 2.0f, -2.0f), 0.5f, new metal(vec3(0.6f, 0.6f, 0.6f), 0.f));
    hitable *world = new hitable_list(list, 5);
    camera cam;
    for(int i = ny - 1; i >= 0; i--)
    {
        for(int j = 0; j < nx; j++)
        {
            vec3 col(0.0f, 0.0f, 0.0f);
            for(int s = 0; s < ns; s++)
            {
                float u = float(j + drand48())/float(nx);
                float v = float(i + drand48())/float(ny);
                ray r = cam.get_ray(u, v);
                col += color(r, world, 0);
            }
            col /= float(ns);
            col *= float(255.99);
            output << col.toString() << " ";
        }
        output << endl;
    }   
    output.close();
    return 0;
}