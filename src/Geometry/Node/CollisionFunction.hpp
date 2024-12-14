#ifndef COLLISION_FUNCTION_HPP
#define COLLISION_FUNCTION_HPP

#include "../Geometry/Node/node.hpp"

namespace lattice_boltzmann_method
{
    template<int dim>
    class CollisionFunction {
    public:
        CollisionFunction(double reynolds_number, double characteristic_velocity, double characteristic_length) 
            : Re_(reynolds_number), u_(characteristic_velocity), L_(characteristic_length) {
            
            // Calculate relaxation time tau from Reynolds number
            tau_ = 0.5 + (3.0 * u_ * L_) / Re_;
        }

        virtual void ApplyCollision(Node<dim> &node) = 0;

    protected:
        double Re_;
        double u_;
        double L_;
        double tau_;
    };
}

#endif // COLLISION_FUNCTION_HPP
