#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

struct Colorf
{
    int r, g, b;

    Colorf(int bw) : r(bw), g(bw), b(bw) {}
    Colorf(int r, int g, int b) : r(r), g(g), b(b) {}

    Colorf operator+(Colorf const& colorf) {return Colorf(r + colorf.r, g + colorf.g, b + colorf.b);}
    Colorf operator-(Colorf const& colorf) {return Colorf(r - colorf.r, g - colorf.g, b - colorf.b);}
    Colorf operator*(Colorf const& colorf) {return Colorf(r * colorf.r, g * colorf.g, b * colorf.b);}
    Colorf operator/(Colorf const& colorf) {return Colorf(r / colorf.r, g / colorf.g, b / colorf.b);}
    
};

struct Vec2{
    float x, y;
 
    Vec2(float value) : x(value), y(value) {}
    Vec2(float _x, float _y) : x(_x), y(_y) {}
 
    Vec2 operator+(Vec2 const& vec2) {return Vec2(x + vec2.x, y + vec2.y);}
    Vec2 operator-(Vec2 const& vec2) {return Vec2(x - vec2.x, y - vec2.y);}
    Vec2 operator*(Vec2 const& vec2) {return Vec2(x * vec2.x, y * vec2.y);}
    Vec2 operator/(Vec2 const& vec2) {return Vec2(x / vec2.x, y / vec2.y);}
};


namespace draw{
    namespace v2{

        void point(Colorf color, int w, Vec2 point){
            glPointSize(w);
            glColor3f(color.r,color.g,color.b);
            glBegin(GL_POINTS);
            glVertex2f(point.x,point.y);
            glEnd();
        }

        void line(Colorf color, int w, Vec2 point1, Vec2 point2){
            glLineWidth(w);
            glColor3f(color.r,color.g,color.b);
            glBegin(GL_LINES);
            glVertex2d(point1.x,point1.y);
            glVertex2d(point2.x,point2.y);
            glEnd();
        }

        void triangle(Colorf color, Vec2 point1, Vec2 point2, Vec2 point3){
            glColor3f(color.r,color.g,color.b);
            glBegin(GL_TRIANGLES);
            glVertex2d(point1.x,point1.y);
            glVertex2d(point2.x,point2.y);
            glVertex2d(point3.x,point3.y);
            glEnd();
        }

        void quad(Colorf color, Vec2 point1, Vec2 point2, Vec2 point3, Vec2 point4){
            glColor3f(color.r,color.g,color.b);
            glBegin(GL_QUADS);
            glVertex2d(point1.x,point1.y);
            glVertex2d(point2.x,point2.y);
            glVertex2d(point3.x,point3.y);
            glVertex2d(point4.x,point4.y);
            glEnd();
        }

    }
}