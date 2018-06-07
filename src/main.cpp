#include "Application.h"
#include "components/MeshComponent.h"
#include "components/graphics/Camera.h"
#include "components/graphics/CameraController.h"
#include "components/PhysicsComponent.h"
#include "components/TransformComponent.h"
//Todo: this could be cleaned up a little bit.
using namespace Game;
int main()
{
    Application app;

    auto camera = GameCore::get().addEntity();
    camera->addComponent(new Camera());
    camera->addComponent(new CameraController());

    //Entity 1:
    auto sampleEntity = GameCore::get().addEntity();
    sampleEntity->addComponent(new MeshComponent());
    sampleEntity->getComponent<TransformComponent>().setTransform(Transform(glm::vec3(-5,-5,-20)));
    sampleEntity->getComponent<MeshComponent>().loadMesh("stairs.obj");
    sampleEntity->addComponent(new PhysicsComponent());
    sampleEntity->getComponent<PhysicsComponent>().setMass(0);
    sampleEntity->getComponent<PhysicsComponent>().setShape(CollisionShapes::STAIRS);
    //Entity2
    auto sampleEntity2 = GameCore::get().addEntity();
    sampleEntity2->addComponent(new MeshComponent());
    sampleEntity2->getComponent<TransformComponent>().setTransform(Transform(glm::vec3(0,10,-20)));
    sampleEntity2->getComponent<MeshComponent>().loadMesh("suzanne.obj");
    sampleEntity2->addComponent(new PhysicsComponent());
    sampleEntity2->getComponent<PhysicsComponent>().setMass(1);
    sampleEntity2->getComponent<PhysicsComponent>().setShape(CollisionShapes::RAGDOLL);




    app.start();
}