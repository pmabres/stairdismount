#pragma once

#include "interfaces/Component.h"
#include "../core/structs/Transform.h"

namespace Game
{
class TransformComponent: public Component
{
public:
    TransformComponent();
    ~TransformComponent();

    Transform getTransform();
    void setTransform(Transform transform);
    void update() override;
    void draw() override;
    void start() override;
    void stop() override;
    void configure() override;
    void cleanup() override;
    void onCreate() override;
private:
    Transform mTransform;

};

}
