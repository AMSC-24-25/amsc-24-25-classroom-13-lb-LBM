#ifndef INNER_NODE_HPP
#define INNER_NODE_HPP

#include "../Geometry/Node/node.hpp"
#include "../Geometry/Domain/domain.hpp"
#include "node_callback.hpp"

namespace lattice_boltzmann_method
{
    template<int dim>
    class InnerNode : public Node<dim> {
    public:
        explicit InnerNode(const Point<double, dim>& position)
            : Node<dim>(position) {}

        virtual ~InnerNode() = default;

        virtual void Collide() override = 0;
        virtual void Propagate() override = 0;

        void RunCallbacks(const std::vector<std::unique_ptr<NodeCallback<dim>>>& node_callbacks) {
            for (const auto& callback : node_callbacks) {
                if (callback) {
                    callback->HandleNonConstNode(*this);
                }
            }
        }
    };
}

#endif // INNER_NODE_HPP
