#include "vector3d.h"

#include<iostream>

namespace csci3081 {

//made for the operator- overload.
Vector3D::Vector3D()    {
    this->vector.push_back(0);
    this->vector.push_back(0);
    this->vector.push_back(0);

    x = 0;
    y = 0;
    z = 0;
}

Vector3D::Vector3D(std::vector<float> vector)   {
    this->vector = vector;
    x = vector[0];
    y = vector[1];
    z = vector[2];
}

Vector3D::Vector3D(float x, float y, float z)   {
    this->x = x;
    this->y = y;
    this->z = z;

    std::vector<float> vector;
    vector.push_back(x);
    vector.push_back(y);
    vector.push_back(z);

    this->vector = vector;
}

Vector3D Vector3D::operator-(Vector3D rhs)  {
    Vector3D sum;

    sum.x = this->x - rhs.x;
    sum.y = this->y - rhs.y;
    sum.z = this->z - rhs.z;

    sum.vector[0] = this->x - rhs.x;
    sum.vector[1] = this->y - rhs.y;
    sum.vector[2] = this->z - rhs.z;

    return sum;
}

Vector3D Vector3D::operator+(Vector3D rhs)  {
    Vector3D sum;

    sum.x = this->x + rhs.x;
    sum.y = this->y + rhs.y;
    sum.z = this->z + rhs.z;
    
    sum.vector[0] = this->x + rhs.x;
    sum.vector[1] = this->y + rhs.y;
    sum.vector[2] = this->z + rhs.z;
    
    return sum;
}

Vector3D Vector3D::operator*(float rhs) {
    Vector3D product;
    
    product.x = this->x * rhs;
    product.y = this->y * rhs;
    product.z = this->z * rhs;
    
    product.vector[0] = this->x * rhs;
    product.vector[1] = this->y * rhs;
    product.vector[2] = this->z * rhs;
    
    return product;
}

std::vector<float>& Vector3D::GetVector()   {
    return vector;
}

float Vector3D::GetX()  {
    return x;
}

float Vector3D::GetY()  {
    return y;
}

float Vector3D::GetZ()  {
    return z;
}

void Vector3D::SetVector(std::vector<float> vector) {
    this->vector = vector;
    x = vector[0];
    y = vector[1];
    z = vector[2];
}

void Vector3D::SetX(float x)    {
    this->x = x;
    vector[0] = x;
}

void Vector3D::SetY(float y)    {
    this->y = y;
    vector[1] = y;
}

void Vector3D::SetZ(float z)    {
    this->z = z;
    vector[2] = z;
}

float Vector3D::Magnitude() {
    return sqrt(x*x + y*y + z*z);
}

void Vector3D::Normalize()  {
    //finds the magnitude to find the unit vector values.
    float magnitude = sqrt(x*x + y*y + z*z);
    float newX = x/magnitude;
    float newY = y/magnitude;
    float newZ = z/magnitude;

    this->x = newX;
    this->y = newY;
    this->z = newZ;
    
    vector[0] = newX;
    vector[1] = newY;
    vector[2] = newZ;
}

}//namespace csci3081