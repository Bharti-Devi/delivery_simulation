#include "vector2d.h"


namespace csci3081 {

Vector2D::Vector2D(std::vector<float> vector)   {
    this->vector = vector;
    x = vector[0];
    y = 0;
    z = vector[2];
    this->vector[1] = 0;
}

Vector2D::Vector2D(float x, float z)    {
    this->x = x;
    this->y = 0;
    this->z = z;

    std::vector<float> vector;
    vector.push_back(x);
    vector.push_back(0);
    vector.push_back(z);

    this->vector = vector;
}

std::vector<float>& Vector2D::GetVector()   {
    return vector;
}

float Vector2D::GetX()  {
    return x;
}

float Vector2D::GetY()  {
    return y;
}

float Vector2D::GetZ()  {
    return z;
}

void Vector2D::SetVector(std::vector<float> vector) {
    this->vector = vector;
    x = vector[0];
    y = 0;
    z = vector[2];
    this->vector[1] = 0;
}

void Vector2D::SetX(float x)    {
    this->x = x;
    vector[0] = x;
}

void Vector2D::SetZ(float z)    {
    this->z = z;
    vector[2] = z;
}

float Vector2D::Magnitude() {
    return sqrt(x*x + z*z);
}

void Vector2D::Normalize()  {
    // finds the magnitude to find the unit vector values.
    float magnitude = sqrt(x*x + z*z);
    float newX = x/magnitude;
    float newZ = z/magnitude;

    this->x = newX;
    this->z = newZ;
    
    vector[0] = newX;
    vector[2] = newZ;
}


}//namespace csci3081