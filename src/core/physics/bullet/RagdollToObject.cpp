#include "GrBulletObject.h"
#include "SFML/OpenGL.hpp"
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

GrBulletObject::GrBulletObject()
{
}

GrBulletObject::GrBulletObject(btRigidBody * rigidBody)
{
    this->rigidBody = rigidBody;

    {
        btTransform transform;
        rigidBody->getMotionState()->getWorldTransform(transform);
        origin.x = transform.getOrigin().getX();
        origin.y = transform.getOrigin().getY();
        origin.z = transform.getOrigin().getZ();
    }
    startOrigin = origin;

    {
        btTransform transform;
        rigidBody->getMotionState()->getWorldTransform(transform);
        rotationAxis.x = transform.getRotation().getAxis().getX();
        rotationAxis.y = transform.getRotation().getAxis().getY();
        rotationAxis.z = transform.getRotation().getAxis().getZ();
        rotationAngle = transform.getRotation().getAngle() * 180 / M_PI;
    }
    startRotationAxis = rotationAxis;
    startRotationAngle = rotationAngle;
}


GrBulletObject::~GrBulletObject()
{
    // TODO: remove shapes and objects and motion states
    delete rigidBody->getCollisionShape();
    delete rigidBody->getMotionState();
    delete rigidBody;
    delete linker;
}

void GrBulletObject::draw()
{
    glColor3f(0, 1, 0);
    glPushMatrix();

    linker->drawTransform(origin, rotationAxis, rotationAngle);
    glPopMatrix();
}

void GrBulletObject::update()
{
    updateOrigin();
    updateRotation();
}

void GrBulletObject::updateOrigin()
{
    btTransform transform;
    rigidBody->getMotionState()->getWorldTransform(transform);
    origin.x = transform.getOrigin().getX();
    origin.y = transform.getOrigin().getY();
    origin.z = transform.getOrigin().getZ();
}

void GrBulletObject::updateRotation()
{
    btTransform transform;
    rigidBody->getMotionState()->getWorldTransform(transform);
    rotationAxis.x = transform.getRotation().getAxis().getX();
    rotationAxis.y = transform.getRotation().getAxis().getY();
    rotationAxis.z = transform.getRotation().getAxis().getZ();
    rotationAngle = transform.getRotation().getAngle() * 180 / M_PI;
}

void GrBulletObject::resetPosition()
{
    // http://bulletphysics.org/Bullet/phpBB3/viewtopic.php?t=11000

    rigidBody->clearForces();
    btVector3 zeroVector(0, 0, 0);
    rigidBody->setLinearVelocity(zeroVector);
    rigidBody->setAngularVelocity(zeroVector);

    btQuaternion rotation(btVector3((btScalar) startRotationAxis.x, (btScalar)startRotationAxis.y, (btScalar)startRotationAxis.z), (btScalar)(startRotationAngle * M_PI / 180));
    btVector3 translate((btScalar) startOrigin.x, (btScalar) startOrigin.y, (btScalar) startOrigin.z);

    btTransform startTransform;
    startTransform.setIdentity();
    startTransform.setOrigin(translate);
    startTransform.setRotation(rotation);

    rigidBody->setWorldTransform(startTransform);
    rigidBody->getMotionState()->setWorldTransform(startTransform);
}

void GrBulletObject::activate()
{
    rigidBody->activate(true);
}

void GrBulletObject::setLinker(GrLinkerObject *linker)
{
    this->linker = linker;
}

btRigidBody *GrBulletObject::getRigidBody()
{
    return rigidBody;
}