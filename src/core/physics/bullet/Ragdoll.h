#pragma once
//#include "BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h"
//#include "GrBulletObject.h"
//class Ragdoll
//{
//private:
//    enum bodyParts
//    {
//        BODYPART_HEAD = 0,
//        BODYPART_NECK,
//        BODYPART_THORAX,
//        BODYPART_ABDOMEN,
//        BODYPART_PELVIS,
//        BODYPART_LEFT_UPPER_ARM,
//        BODYPART_RIGHT_UPPER_ARM,
//        BODYPART_LEFT_LOWER_ARM,
//        BODYPART_RIGHT_LOWER_ARM,
//        BODYPART_LEFT_THIGH,
//        BODYPART_RIGHT_THIGH,
//        BODYPART_LEFT_LEG,
//        BODYPART_RIGHT_LEG,
//        BODYPART_LEFT_FOOT,
//        BODYPART_RIGHT_FOOT,
//
//        BODYPART_COUNT
//    };
//
//    enum joints
//    {
//        JOINT_HEAD_NECK = 0,
//        JOINT_NECK_THORAX,
//        JOINT_THORAX_ADBOMEN,
//        JOINT_ABDOMEN_PELVIS,
//        JOINT_THORAX_LEFT_UPPER_ARM,
//        JOINT_LEFT_ARM_UPPER_LOWER,
//        JOINT_THORAX_RIGHT_UPPER_ARM,
//        JOINT_RIGHT_ARM_UPPER_LOWER,
//        JOINT_PELVIS_LEFT_THIGH,
//        JOINT_LEFT_THIGH_LEG,
//        JOINT_LEFT_LEG_FOOT,
//        JOINT_PELVIS_RIGHT_THIGH,
//        JOINT_RIGHT_THIGH_LEG,
//        JOINT_RIGHT_LEG_FOOT,
//
//        JOINT_COUNT
//    };
//
//    btDiscreteDynamicsWorld *world;
//    GrBulletObject *bodyParts[BODYPART_COUNT];
//    btTypedConstraint *joints[JOINT_COUNT];
//
//    void addBoxLinker(btScalar halfX, btScalar halfY, btScalar halfZ, GrBulletObject *object);
//    void addCylinderLinker(btScalar radius, btScalar height, GrBulletObject *object);
//    void addSphereLinker(btScalar radius, GrBulletObject *object);
//public:
//    Ragdoll();
//    Ragdoll(btDiscreteDynamicsWorld *world, btScalar heightOffset);
//    ~Ragdoll();
//    void draw();
//    void update();
//    void resetPosition();
//    void RNJesus();
//};