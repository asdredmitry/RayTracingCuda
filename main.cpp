#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "vec3.hpp"
#include "ray.hpp"
#include "hitable.hpp"
#include "sphere.hpp"
#include "hitablelist.hpp"
#include "camera.hpp"
using namespace std;
void write_header(ofstream & out, int nx, int ny)
{
    out << "P3" << endl;
    out << nx << " " << ny << endl;
    out << 255 << endl;
}
vec3 color(const ray& r, hitable * world)
{
    hit_record rec;
    if(world->hit(r, 0.0f, MAXFLOAT, rec))
    {
        //return vec3(1.0f, 0.0f, 0.0f);
        return vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1)*0.5f;
    }
    else
    {
        vec3 unit_direction = unit_vector(r.direction());
        float t1 = 0.5*(unit_direction.y() + 1.0);
        return vec3(1.0f, 1.0f, 1.0f)*(1.0 - t1) + vec3(0.5f, 0.7f, 1.0f)*t1;   
    }
}
int main()
{
    ofstream output("Picture.ppm");
    int nx = 1920;
    int ny = 1080;
    int ns = 15;
    write_header(output, nx, ny);
    vec3 lower_left_corner(-2.0f, -1.0f, -1.0f);
    vec3 horizontal(4.0f, 0.0f, 0.0f);
    vec3 vertical(0.0f, 2.0f, 0.0f);
    vec3 origin(0.0f, 0.0f, 0.0f);
    hitable *list[2];
    list[0] = new sphere(vec3(0, 0, -1), 0.5);
    list[1] = new sphere(vec3(0.0f, -100.5f, -1.0f), 100.f);
    //list[2] = new sphere(vec3(-2.0f, 1.5f, -3.0f), 1.f);
    hitable *world = new hitable_list(list, 2);
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
                col += color(r, world);
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