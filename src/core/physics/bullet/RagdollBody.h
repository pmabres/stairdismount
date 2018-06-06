//#pragma once
//
//#include "LinearMath/btAlignedObjectArray.h"
//#include "btBulletDynamicsCommon.h"
//
//class RagdollBody
//{
//    enum
//    {
//        BODYPART_PELVIS = 0,
//        BODYPART_SPINE,
//        BODYPART_HEAD,
//
//        BODYPART_LEFT_UPPER_LEG,
//        BODYPART_LEFT_LOWER_LEG,
//
//        BODYPART_RIGHT_UPPER_LEG,
//        BODYPART_RIGHT_LOWER_LEG,
//
//        BODYPART_LEFT_UPPER_ARM,
//        BODYPART_LEFT_LOWER_ARM,
//
//        BODYPART_RIGHT_UPPER_ARM,
//        BODYPART_RIGHT_LOWER_ARM,
//
//        BODYPART_COUNT
//    };
//
//    enum
//    {
//        JOINT_PELVIS_SPINE = 0,
//        JOINT_SPINE_HEAD,
//
//        JOINT_LEFT_HIP,
//        JOINT_LEFT_KNEE,
//
//        JOINT_RIGHT_HIP,
//        JOINT_RIGHT_KNEE,
//
//        JOINT_LEFT_SHOULDER,
//        JOINT_LEFT_ELBOW,
//
//        JOINT_RIGHT_SHOULDER,
//        JOINT_RIGHT_ELBOW,
//
//        JOINT_COUNT
//    };
//
//    btDynamicsWorld* mPhysicsWorld;
//    btCollisionShape* mShapes[BODYPART_COUNT];
//    btRigidBody* mBodies[BODYPART_COUNT];
//    btTypedConstraint* mJoints[JOINT_COUNT];
//
//    btRigidBody* localCreateRigidBody (btScalar mass, const btTransform& startTransform, btCollisionShape* shape);
//
//public:
//    RagdollBody (btDynamicsWorld* physicsWorld,
//             const btVector3& positionOffset,
//             btScalar scaleRagdoll = btScalar(1.0));
//
//    ~RagdollBody ();
//};
