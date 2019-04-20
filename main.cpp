#include <iostream>
#include <fstream>
#include "vec3.hpp"
using namespace std;
int main()
{
    ofstream output("Picture.ppm");
    int nx = 1280;
    int ny = 720;
    output << "P3" << endl;
    output << nx << " " << ny << endl;
    output << 255 << endl;
    vec3Int tmp1;
    for(int i = ny - 1; i >= 0; i--)
    {
        for(int j = 0; j < nx; j++)
        {
            vec3 tmp(float(j)/float(nx), float(i)/float(ny), 0.2f);
            tmp *= 255.55;
            tmp1 = tmp;
            output << tmp1 << " ";
            //output << int(255.99*tmp.r()) << " " << int(255.99*tmp.g()) << " " << int(255.99*tmp.b()) << " ";
        }
        output << endl;
    }   
    output.close();
    return 0;
}