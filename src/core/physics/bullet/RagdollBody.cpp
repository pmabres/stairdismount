//#include "RagdollBody.h"
//RagdollBody::RagdollBody(btDynamicsWorld *ownerWorld, const btVector3 &positionOffset,
//                         btScalar RagdollBody)
//    : mPhysicsWorld(ownerWorld)
//{
//    // Setup the geometry
//    mShapes[BODYPART_PELVIS] = new btCapsuleShape(
//        btScalar(scale_ragdoll * 0.15), btScalar(scale_ragdoll * 0.20));
//    mShapes[BODYPART_SPINE] = new btCapsuleShape(
//        btScalar(scale_ragdoll * 0.15), btScalar(scale_ragdoll * 0.28));
//    mShapes[BODYPART_HEAD] = new btCapsuleShape(btScalar(scale_ragdoll * 0.10), btScalar(scale_ragdoll * 0.05));
//    mShapes[BODYPART_LEFT_UPPER_LEG] =
//        new btCapsuleShape(btScalar(scale_ragdoll * 0.07), btScalar(scale_ragdoll * 0.45));
//    mShapes[BODYPART_LEFT_LOWER_LEG] =
//        new btCapsuleShape(btScalar(scale_ragdoll * 0.05), btScalar(scale_ragdoll * 0.37));
//    mShapes[BODYPART_RIGHT_UPPER_LEG] =
//        new btCapsuleShape(btScalar(scale_ragdoll * 0.07), btScalar(scale_ragdoll * 0.45));
//    mShapes[BODYPART_RIGHT_LOWER_LEG] =
//        new btCapsuleShape(btScalar(scale_ragdoll * 0.05), btScalar(scale_ragdoll * 0.37));
//    mShapes[BODYPART_LEFT_UPPER_ARM] =
//        new btCapsuleShape(btScalar(scale_ragdoll * 0.05), btScalar(scale_ragdoll * 0.33));
//    mShapes[BODYPART_LEFT_LOWER_ARM] =
//        new btCapsuleShape(btScalar(scale_ragdoll * 0.04), btScalar(scale_ragdoll * 0.25));
//    mShapes[BODYPART_RIGHT_UPPER_ARM] =
//        new btCapsuleShape(btScalar(scale_ragdoll * 0.05), btScalar(scale_ragdoll * 0.33));
//    mShapes[BODYPART_RIGHT_LOWER_ARM] =
//        new btCapsuleShape(btScalar(scale_ragdoll * 0.04), btScalar(scale_ragdoll * 0.25));
//
//    // Setup all the rigid bodies
//    btTransform offset;
//    offset.setIdentity();
//    offset.setOrigin(positionOffset);
//
//    btTransform transform;
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(0.), btScalar(scale_ragdoll * 1.), btScalar(0.)));
//    mBodies[BODYPART_PELVIS] = localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_PELVIS]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(0.), btScalar(scale_ragdoll * 1.2), btScalar(0.)));
//    mBodies[BODYPART_SPINE] = localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_SPINE]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(0.), btScalar(scale_ragdoll * 1.6), btScalar(0.)));
//    mBodies[BODYPART_HEAD] = localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_HEAD]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(-0.18 * scale_ragdoll), btScalar(0.65 * scale_ragdoll),
//                                  btScalar(0.)));
//    mBodies[BODYPART_LEFT_UPPER_LEG] =
//        localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_LEFT_UPPER_LEG]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(-0.18 * scale_ragdoll), btScalar(0.2 * scale_ragdoll), btScalar(0.)));
//    mBodies[BODYPART_LEFT_LOWER_LEG] =
//        localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_LEFT_LOWER_LEG]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(0.18 * scale_ragdoll), btScalar(0.65 * scale_ragdoll), btScalar(0.)));
//    mBodies[BODYPART_RIGHT_UPPER_LEG] =
//        localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_RIGHT_UPPER_LEG]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(0.18 * scale_ragdoll), btScalar(0.2 * scale_ragdoll), btScalar(0.)));
//    mBodies[BODYPART_RIGHT_LOWER_LEG] =
//        localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_RIGHT_LOWER_LEG]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(-0.35 * scale_ragdoll), btScalar(1.45 * scale_ragdoll), btScalar(0.)));
//    transform.getBasis().setEulerZYX(0, 0, SIMD_HALF_PI);
//    mBodies[BODYPART_LEFT_UPPER_ARM] =
//        localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_LEFT_UPPER_ARM]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(-0.7 * scale_ragdoll), btScalar(1.45 * scale_ragdoll), btScalar(0.)));
//    transform.getBasis().setEulerZYX(0, 0, SIMD_HALF_PI);
//    mBodies[BODYPART_LEFT_LOWER_ARM] =
//        localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_LEFT_LOWER_ARM]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(0.35 * scale_ragdoll), btScalar(1.45 * scale_ragdoll), btScalar(0.)));
//    transform.getBasis().setEulerZYX(0, 0, -SIMD_HALF_PI);
//    mBodies[BODYPART_RIGHT_UPPER_ARM] =
//        localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_RIGHT_UPPER_ARM]);
//
//    transform.setIdentity();
//    transform.setOrigin(btVector3(btScalar(0.7 * scale_ragdoll), btScalar(1.45 * scale_ragdoll), btScalar(0.)));
//    transform.getBasis().setEulerZYX(0, 0, -SIMD_HALF_PI);
//    mBodies[BODYPART_RIGHT_LOWER_ARM] =
//        localCreateRigidBody(btScalar(1.), offset * transform, mShapes[BODYPART_RIGHT_LOWER_ARM]);
//
//    // Setup some damping on the mBodies
//    for (int i = 0; i < BODYPART_COUNT; ++i) {
//        mBodies[i]->setDamping(0.05f, 0.85f);
//        mBodies[i]->setDeactivationTime(0.8f);
//        mBodies[i]->setSleepingThresholds(1.6f, 2.5f);
//    }
//
/////////////////////////////// SETTING THE CONSTRAINTS /////////////////////////////////////////////7777
//    // Now setup the constraints
//    btGeneric6DofConstraint *joint6DOF;
//    btTransform localA, localB;
//    bool useLinearReferenceFrameA = true;
///// ******* SPINE HEAD ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(0.), btScalar(0.30 * scale_ragdoll), btScalar(0.)));
//
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(-0.14 * scale_ragdoll), btScalar(0.)));
//
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_SPINE],
//                                                *mBodies[BODYPART_HEAD],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_PI * 0.3f, -SIMD_EPSILON, -SIMD_PI * 0.3f));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_PI * 0.5f, SIMD_EPSILON, SIMD_PI * 0.3f));
//#endif
//        mJoints[JOINT_SPINE_HEAD] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_SPINE_HEAD], true);
//    }
///// *************************** ///
//
//
//
//
///// ******* LEFT SHOULDER ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(-0.2 * scale_ragdoll), btScalar(0.15 * scale_ragdoll), btScalar(0.)));
//
//        localB.getBasis().setEulerZYX(SIMD_HALF_PI, 0, -SIMD_HALF_PI);
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(-0.18 * scale_ragdoll), btScalar(0.)));
//
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_SPINE],
//                                                *mBodies[BODYPART_LEFT_UPPER_ARM],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_PI * 0.8f, -SIMD_EPSILON, -SIMD_PI * 0.5f));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_PI * 0.8f, SIMD_EPSILON, SIMD_PI * 0.5f));
//#endif
//        mJoints[JOINT_LEFT_SHOULDER] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_LEFT_SHOULDER], true);
//    }
///// *************************** ///
//
//
///// ******* RIGHT SHOULDER ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(0.2 * scale_ragdoll), btScalar(0.15 * scale_ragdoll), btScalar(0.)));
//        localB.getBasis().setEulerZYX(0, 0, SIMD_HALF_PI);
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(-0.18 * scale_ragdoll), btScalar(0.)));
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_SPINE],
//                                                *mBodies[BODYPART_RIGHT_UPPER_ARM],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_PI * 0.8f, -SIMD_EPSILON, -SIMD_PI * 0.5f));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_PI * 0.8f, SIMD_EPSILON, SIMD_PI * 0.5f));
//#endif
//        mJoints[JOINT_RIGHT_SHOULDER] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_RIGHT_SHOULDER], true);
//    }
///// *************************** ///
//
///// ******* LEFT ELBOW ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(0.), btScalar(0.18 * scale_ragdoll), btScalar(0.)));
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(-0.14 * scale_ragdoll), btScalar(0.)));
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_LEFT_UPPER_ARM],
//                                                *mBodies[BODYPART_LEFT_LOWER_ARM],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON, -SIMD_EPSILON, -SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_PI * 0.7f, SIMD_EPSILON, SIMD_EPSILON));
//#endif
//        mJoints[JOINT_LEFT_ELBOW] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_LEFT_ELBOW], true);
//    }
///// *************************** ///
//
///// ******* RIGHT ELBOW ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(0.), btScalar(0.18 * scale_ragdoll), btScalar(0.)));
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(-0.14 * scale_ragdoll), btScalar(0.)));
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_RIGHT_UPPER_ARM],
//                                                *mBodies[BODYPART_RIGHT_LOWER_ARM],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON, -SIMD_EPSILON, -SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_PI * 0.7, SIMD_EPSILON, SIMD_EPSILON));
//#endif
//
//        mJoints[JOINT_RIGHT_ELBOW] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_RIGHT_ELBOW], true);
//    }
///// *************************** ///
//
//
///// ******* PELVIS ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.getBasis().setEulerZYX(0, SIMD_HALF_PI, 0);
//        localA.setOrigin(btVector3(btScalar(0.), btScalar(0.15 * scale_ragdoll), btScalar(0.)));
//        localB.getBasis().setEulerZYX(0, SIMD_HALF_PI, 0);
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(-0.15 * scale_ragdoll), btScalar(0.)));
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_PELVIS],
//                                                *mBodies[BODYPART_SPINE],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_PI * 0.2, -SIMD_EPSILON, -SIMD_PI * 0.3));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_PI * 0.2, SIMD_EPSILON, SIMD_PI * 0.6));
//#endif
//        mJoints[JOINT_PELVIS_SPINE] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_PELVIS_SPINE], true);
//    }
///// *************************** ///
//
///// ******* LEFT HIP ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(-0.18 * scale_ragdoll), btScalar(-0.10 * scale_ragdoll), btScalar(0.)));
//
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(0.225 * scale_ragdoll), btScalar(0.)));
//
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_PELVIS],
//                                                *mBodies[BODYPART_LEFT_UPPER_LEG],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_HALF_PI * 0.5, -SIMD_EPSILON, -SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_HALF_PI * 0.8, SIMD_EPSILON, SIMD_HALF_PI * 0.6f));
//#endif
//        mJoints[JOINT_LEFT_HIP] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_LEFT_HIP], true);
//    }
///// *************************** ///
//
//
///// ******* RIGHT HIP ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(0.18 * scale_ragdoll), btScalar(-0.10 * scale_ragdoll), btScalar(0.)));
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(0.225 * scale_ragdoll), btScalar(0.)));
//
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_PELVIS],
//                                                *mBodies[BODYPART_RIGHT_UPPER_LEG],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_HALF_PI * 0.5, -SIMD_EPSILON, -SIMD_HALF_PI * 0.6f));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_HALF_PI * 0.8, SIMD_EPSILON, SIMD_EPSILON));
//#endif
//        mJoints[JOINT_RIGHT_HIP] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_RIGHT_HIP], true);
//    }
///// *************************** ///
//
//
///// ******* LEFT KNEE ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(0.), btScalar(-0.225 * scale_ragdoll), btScalar(0.)));
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(0.185 * scale_ragdoll), btScalar(0.)));
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_LEFT_UPPER_LEG],
//                                                *mBodies[BODYPART_LEFT_LOWER_LEG],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
////
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON, -SIMD_EPSILON, -SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_PI * 0.7f, SIMD_EPSILON, SIMD_EPSILON));
//#endif
//        mJoints[JOINT_LEFT_KNEE] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_LEFT_KNEE], true);
//    }
///// *************************** ///
//
///// ******* RIGHT KNEE ******** ///
//    {
//        localA.setIdentity();
//        localB.setIdentity();
//
//        localA.setOrigin(btVector3(btScalar(0.), btScalar(-0.225 * scale_ragdoll), btScalar(0.)));
//        localB.setOrigin(btVector3(btScalar(0.), btScalar(0.185 * scale_ragdoll), btScalar(0.)));
//        joint6DOF = new btGeneric6DofConstraint(*mBodies[BODYPART_RIGHT_UPPER_LEG],
//                                                *mBodies[BODYPART_RIGHT_LOWER_LEG],
//                                                localA,
//                                                localB,
//                                                useLinearReferenceFrameA);
//
//#ifdef RIGID
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON,-SIMD_EPSILON,-SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_EPSILON,SIMD_EPSILON,SIMD_EPSILON));
//#else
//        joint6DOF->setAngularLowerLimit(btVector3(-SIMD_EPSILON, -SIMD_EPSILON, -SIMD_EPSILON));
//        joint6DOF->setAngularUpperLimit(btVector3(SIMD_PI * 0.7f, SIMD_EPSILON, SIMD_EPSILON));
//#endif
//        mJoints[JOINT_RIGHT_KNEE] = joint6DOF;
//        mPhysicsWorld->addConstraint(mJoints[JOINT_RIGHT_KNEE], true);
//    }
///// *************************** ///
//
//}
//
//RagdollBody::~RagdollBody()
//{
//    int i;
//
//    // Remove all constraints
//    for (i = 0; i < JOINT_COUNT; ++i) {
//        mPhysicsWorld->removeConstraint(mJoints[i]);
//        delete mJoints[i];
//        mJoints[i] = 0;
//    }
//
//    // Remove all bodies and shapes
//    for (i = 0; i < BODYPART_COUNT; ++i) {
//        mPhysicsWorld->removeRigidBody(mBodies[i]);
//
//        delete mBodies[i]->getMotionState();
//
//        delete mBodies[i];
//        mBodies[i] = 0;
//        delete mShapes[i];
//        mShapes[i] = 0;
//    }
//}
//
//btRigidBody *
//RagdollBody::localCreateRigidBody(btScalar mass, const btTransform &startTransform, btCollisionShape *shape)
//{
//    bool isDynamic = (mass != 0.f);
//
//    btVector3 localInertia(0, 0, 0);
//    if (isDynamic)
//        shape->calculateLocalInertia(mass, localInertia);
//
//    btDefaultMotionState *myMotionState = new btDefaultMotionState(startTransform);
//    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, shape, localInertia);
//    rbInfo.mAdditionalDamping = true;
//    btRigidBody *body = new btRigidBody(rbInfo);
//
//    mPhysicsWorld->addRigidBody(body);
//
//    return body;
//}