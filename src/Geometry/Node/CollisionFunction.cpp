#include "collision_function.hpp"

namespace lattice_boltzmann_method
{
    template<int dim>
    void CollisionFunction<dim>::ApplyCollision(Node<dim> &node) {
        double density = node.GetDensity();          
        const auto velocity = node.GetVelocity();     
        double velocity_norm = velocity.norm();

        double relaxation_factor = 1.0 / tau_;
        double equilibrium_density = density;        

        node.SetDensity((1 - relaxation_factor) * density + relaxation_factor * equilibrium_density);
        node.UpdateVelocity((1 - relaxation_factor) * velocity);
    }
}
