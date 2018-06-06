#include "Application.h"
#include "core/entity/Entity.h"
#include "components/MeshComponent.h"
#include "components/graphics/Camera.h"
#include "components/graphics/CameraController.h"

using namespace Game;
int main()
{
    Application app;

    auto sampleEntity = GameCore::get().addEntity();
    auto camera = GameCore::get().addEntity();
    sampleEntity->addComponent(new MeshComponent());
    camera->addComponent(new Camera());
    camera->addComponent(new CameraController());
    sampleEntity->getComponent<MeshComponent>().loadMesh("cube.obj");

    app.start();
}