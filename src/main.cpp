#include "Application.h"
#include "core/entity/Entity.h"
#include "components/MeshComponent.h"

using namespace Game;
int main()
{
    Application app;

    auto sampleEntity = GameCore::get().addEntity();
    sampleEntity->addComponent(new MeshComponent());
    sampleEntity->getComponent<MeshComponent>().loadMesh("suzanne.obj");

    app.start();
}