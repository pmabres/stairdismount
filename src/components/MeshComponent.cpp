#include "MeshComponent.h"
#include "../core/resources/RenderObject.h"
#include "../core/GameCore.h"
#include "TransformComponent.h"
namespace Game
{

MeshComponent::MeshComponent() : mRenderObject()
{

}

void MeshComponent::loadMesh(const char *path)
{
    mRenderObject.load(path);
}

void MeshComponent::update()
{

}

void MeshComponent::draw()
{
    Transform transform = entity->getComponent<TransformComponent>().getTransform();
    GameCore::get().getModule<DrawModule>().drawMesh(mMeshId, transform);
}

void MeshComponent::start()
{
    mMeshId = GameCore::get().getModule<DrawModule>().addMesh(mRenderObject.getMesh());
}

void MeshComponent::stop()
{

}

void MeshComponent::configure()
{

}

void MeshComponent::cleanup()
{

}

MeshTransform& MeshComponent::getMeshData()
{
    mRenderObject.getMesh();
}
}

