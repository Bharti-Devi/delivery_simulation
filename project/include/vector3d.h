/**
 *@file vector3d.h
 */
#ifndef VECTOR3D_H_
#define VECTOR3D_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <math.h>

namespace csci3081 {
/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
 * @brief A class that stores 3D vector information to use it to do vector math.
 */
class Vector3D {
    public:
        /**
        * @brief Constructor: sets up Vector3D by instantiating all of its values.
        *
        * Sets up a zero Vector where all values are 0.
        */
        Vector3D();

        /**
        * @brief Constructor: sets up Vector3D by instantiating all of its values.
        *
        * If given a vector takes the values and stores them in x y and z.
        *
        * @param vector Vector of coordinates.
        *
        * @return 3D vector.
        */
        Vector3D(std::vector<float> vector);

        /**
        * @brief Constructor: sets up Vector3D by instantiating all of its values.
        * 
        * Takes in three values and sets them as x y and z respectively. It also sets the vector
        * to have those three values in the correct order.
        *
        * @param x X coordinate.
        * @param y Y coordinate.
        * @param z Z coordinate.
        *
        * @return 3D vector.
        */
        Vector3D(float x, float y, float z);

        /**
        * @brief Operator Overloaded '-' for subtraction.
        * 
        * Subtracts one vector from another such that:
        * new x = x - x
        * new y = y - y
        * new z = z - z
        * and sets the vector to the correct values.
        *
        * @param rhs Right hand side.
        * 
        * @return 3D vector.
        */
        Vector3D operator-(Vector3D rhs);

        /**
        * @brief Operator Overloaded '+' for addition.
        * 
        * Adds one vector to another such that:
        * new x = x + x
        * new y = y + y
        * new z = z + z
        * and sets the vector to the correct values.
        *
        * @param rhs Right hand side.
        * 
        * @return 3D vector.
        */
        Vector3D operator+(Vector3D rhs);

        /**
         * @brief Operator Overloaded '*' for scalar multiplication
         */
        Vector3D operator*(float rhs);

        /**
        * @brief Gets the vector in a vector.
        *
        * @return Vector.
        */
        std::vector<float>& GetVector();

        /**
        * @brief Gets X.
        *
        * @return X coordinate.
        */
        float GetX();

        /**
        * @brief Gets Y.
        *
        * @return Y coordinate.
        */
        float GetY();

        /**
        * @brief Gets Z.
        *
        * @return Z coordinate.
        */
        float GetZ();

        /**
        * @brief Sets the vector to the given vector as well as x and y.
        *
        * Sets the vector as the current vector.
        * It also sets X, Y, and Z to their respective values from the given vector.
        *
        * @param vector Current vector.
        */
        void SetVector(std::vector<float> vector);

        /**
        * @brief Sets X to the given value.
        *
        * Sets the X to the given value and changes the float at the front of the vector
        * to the given value.
        *
        * @param x X coordinate.
        */
        void SetX(float x);

        /**
        * @brief Sets Y to the given value.
        *
        * Sets the Y to the given value and changes the second float of the vector
        * to the given value.
        *
        * @param y Y coordinate.
        */
        void SetY(float y);

        /**
        * @brief Sets Z to the given value.
        *
        * Sets the Y to the given value and changes the third float of the vector
        * to the given value.
        *
        * @param z Z coordinate.
        */
        void SetZ(float z);

        /**
        * @brief Calculates and returns the magnitude of the vector.
        *
        * @return Magnitude.
        */
        float Magnitude();

        /**
        * @brief Normalizes the vector to its Unit Vector form.
        * 
        * Calculates the magnitude then uses it to find the unit vector values and
        * replaces the current values with the unit vector values.
        */
        void Normalize();

    private:
        std::vector<float> vector;
        float x;
        float y;
        float z;
};

}//namespace csci3081

#endif    // VECTOR3D_H_