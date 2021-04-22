/**
 *@file vector2d.h
 */
#ifndef VECTOR2D_H_
#define VECTOR2D_H_

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
 * @brief A class that stores 2D vector information to use it to do vector math.
 */
class Vector2D {
    public:
        /**
        * @brief Constructor: sets up Vector2D by instantiating all of its values.
        *
        * If given a vector takes the first and third values and stores them in x
        * and z. Y is given 0 no matter what the second value.
        */
        Vector2D(std::vector<float> vector);

        /**
        * @brief Constructor: sets up Vector2D by instantiating all of its values.
        * 
        * Takes in two values and sets x as x and z as z as well as creates a vector with
        * an x y and z where the y is 0 and the x and z are their respective values.
        */
        Vector2D(float x, float z);

        /**
        * @brief Returns the vector in a vector.
        *
        * @return 2D Vector.
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
        * Sets the vector as the current vector and sets the float in the second position to
        * 0. It also sets X and Z to their respective values from the given vector.
        *
        * @param vector Current vector to set.
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
        * @brief Sets Z to the given value.
        *
        * Sets the Z to the given value and changes the third float of the vector
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

#endif    // VECTOR2D_H_