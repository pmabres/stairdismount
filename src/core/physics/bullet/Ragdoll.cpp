//#include "Ragdoll.h"
//#include "GrLinkerBoxShape.h"
//#include "GrLinkerCylinderShape.h"
//#include "GrLinkerSphereShape.h"
//
//#include <time.h>
//
//#define _USE_MATH_DEFINES
//#include <math.h>
//
//Ragdoll::Ragdoll()
//{
//}
//
//Ragdoll::Ragdoll(btDiscreteDynamicsWorld *world, btScalar heightOffset)
//{
//    this->world = world;
//
//    btScalar bodyMass = (btScalar) 70.0;
//
//    // feet definition
//    btScalar footLength = (btScalar) 0.24, footHeight = (btScalar) 0.08, footWidth = (btScalar) 0.15;
//    btScalar footTop = footHeight + heightOffset;
//    btScalar footXOffset = (btScalar) 0.04, footZOffset = (btScalar) 0.167;
//    btScalar footMass = bodyMass * (btScalar) 1.38 / 100;
//
//    // left foot
//    btCollisionShape *bpShape = new btBoxShape(btVector3(footLength / 2, footHeight / 2, footWidth / 2));
//    btQuaternion bpRotation(0, 0, 0, 1);
//    btVector3 bpTranslation(footXOffset, footTop - footHeight / 2, -footZOffset);
//    btDefaultMotionState *bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    btVector3 bpInertia(0, 0, 0);
//    btScalar bpMass = footMass;
//    bpShape->calculateLocalInertia(bpMass, bpInertia);
//    btRigidBody::btRigidBodyConstructionInfo rbInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    btRigidBody *body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_LEFT_FOOT] = new GrBulletObject(body);
//    addBoxLinker(footLength / 2, footHeight / 2, footWidth / 2, bodyParts[BODYPART_LEFT_FOOT]);
//
//    // right foot
//    bpShape = new btBoxShape(btVector3(footLength / 2, footHeight / 2, footWidth / 2));
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(footXOffset, footTop - footHeight / 2, footZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = footMass;
//    bpShape->calculateLocalInertia(bpMass, bpInertia);
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_RIGHT_FOOT] = new GrBulletObject(body);
//    addBoxLinker(footLength / 2, footHeight / 2, footWidth / 2, bodyParts[BODYPART_RIGHT_FOOT]);
//
//    // legs definition
//    btScalar legRadius = (btScalar) 0.055, legHeight = (btScalar) 0.34;
//    btScalar legTop = footTop + legHeight;
//    btScalar legMass = bodyMass * (btScalar) 5.05 / 100;
//
//    // left leg
//    bpShape = new btCapsuleShape(legRadius, legHeight - 2 * legRadius);
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, legTop - legHeight / 2, -footZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = legMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_LEFT_LEG] = new GrBulletObject(body);
//    addCylinderLinker(legRadius, legHeight, bodyParts[BODYPART_LEFT_LEG]);
//
//    // right leg
//    bpShape = new btCapsuleShape(legRadius, legHeight - 2 * legRadius);
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, legTop - legHeight / 2, footZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = legMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_RIGHT_LEG] = new GrBulletObject(body);
//    addCylinderLinker(legRadius, legHeight, bodyParts[BODYPART_RIGHT_LEG]);
//
//    // thighs definition
//    btScalar thighRadius = (btScalar) 0.07, thighHeight = (btScalar) 0.32;
//    btScalar thighAngle = (btScalar)(12 * M_PI / 180);
//    btScalar thighAngledHeight = thighHeight * btCos(thighAngle);
//    btScalar thighTop = legTop + thighAngledHeight;
//    btScalar thighZOffset = (btScalar) 0.1136;
//    btScalar thighMass = bodyMass * (btScalar) 11.125 / 100;
//
//    // left thigh  h=0.316
//    bpShape = new btCapsuleShape(thighRadius, thighHeight - 2 * thighRadius);
//    bpRotation = btQuaternion(1 * btSin(thighAngle / 2), 0, 0, btCos(thighAngle / 2));
//    bpTranslation = btVector3(0, thighTop - thighAngledHeight / 2, -thighZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = thighMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_LEFT_THIGH] = new GrBulletObject(body);
//    addCylinderLinker(thighRadius, thighHeight, bodyParts[BODYPART_LEFT_THIGH]);
//
//    // right thigh  h=0.316	, ends at 0.706
//    bpShape = new btCapsuleShape(thighRadius, thighHeight - 2 * thighRadius);
//    bpRotation = btQuaternion(-1 * btSin(thighAngle / 2), 0, 0, btCos(thighAngle / 2));
//    bpTranslation = btVector3(0, thighTop - thighAngledHeight / 2, thighZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = thighMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_RIGHT_THIGH] = new GrBulletObject(body);
//    addCylinderLinker(thighRadius, thighHeight, bodyParts[BODYPART_RIGHT_THIGH]);
//
//    // pelvis definition
//    btScalar pelvisLength = (btScalar) 0.19, pelvisHeight = (btScalar) 0.15, pelvisWidth = (btScalar) 0.35;
//    btScalar pelvisTop = thighTop + pelvisHeight;
//    btScalar pelvisMass = bodyMass * (btScalar) 14.81 / 100;
//
//    // pelvis
//    bpShape = new btBoxShape(btVector3(pelvisLength / 2, pelvisHeight / 2, pelvisWidth / 2));
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, pelvisTop - pelvisHeight / 2, 0);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = pelvisMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_PELVIS] = new GrBulletObject(body);
//    addBoxLinker(pelvisLength / 2, pelvisHeight / 2, pelvisWidth / 2, bodyParts[BODYPART_PELVIS]);
//
//    // abdomen definition
//    btScalar abdomenLength = (btScalar) 0.13, abdomenHeight = (btScalar) 0.113, abdomenWidth = (btScalar) 0.268;
//    btScalar abdomenTop = pelvisTop + abdomenHeight;
//    btScalar abdomenMass = bodyMass * (btScalar) 12.65 / 100;
//
//    // abdomen
//    bpShape = new btBoxShape(btVector3(abdomenLength / 2, abdomenHeight / 2, abdomenWidth / 2));
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, abdomenTop - abdomenHeight / 2, 0);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = abdomenMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_ABDOMEN] = new GrBulletObject(body);
//    addBoxLinker(abdomenLength / 2, abdomenHeight / 2, abdomenWidth / 2, bodyParts[BODYPART_ABDOMEN]);
//
//    // thorax definition
//    btScalar thoraxLength = (btScalar) 0.2, thoraxHeight = (btScalar) 0.338, thoraxWidth = (btScalar) 0.34;
//    btScalar thoraxTop = abdomenTop + thoraxHeight;
//    btScalar thoraxMass = bodyMass * (btScalar) 18.56 / 100;
//
//    // thorax
//    bpShape = new btBoxShape(btVector3(thoraxLength / 2, thoraxHeight / 2, thoraxWidth / 2));
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, thoraxTop - thoraxHeight / 2, 0);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = thoraxMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_THORAX] = new GrBulletObject(body);
//    addBoxLinker(thoraxLength / 2, thoraxHeight / 2, thoraxWidth / 2, bodyParts[BODYPART_THORAX]);
//
//    // upper arms definition
//    btScalar upperArmRadius = (btScalar) 0.04, upperArmHeight = (btScalar) 0.25;
//    btScalar upperArmAngle = (btScalar)(25 * M_PI / 180);
//    btScalar upperArmAngledHeight = upperArmHeight * btCos(upperArmAngle);
//    btScalar upperArmBottom = thoraxTop - upperArmAngledHeight;
//    btScalar upperArmZOffset = (btScalar) 0.223;
//    btScalar upperArmMass = bodyMass * (btScalar) 3.075 / 100;
//
//    // left upper arm
//    bpShape = new btCapsuleShape(upperArmRadius, upperArmHeight - 2 * upperArmRadius);
//    bpShape = new btBoxShape(btVector3(upperArmRadius, upperArmHeight / 2, upperArmRadius));
//    bpRotation = btQuaternion(1 * btSin(upperArmAngle / 2), 0, 0, btCos(upperArmAngle / 2));
//    bpTranslation = btVector3(0, upperArmBottom + upperArmAngledHeight / 2, -upperArmZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = upperArmMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_LEFT_UPPER_ARM] = new GrBulletObject(body);
//    addCylinderLinker(upperArmRadius, upperArmHeight, bodyParts[BODYPART_LEFT_UPPER_ARM]);
//
//    // right upper arm
//    bpShape = new btCapsuleShape(upperArmRadius, upperArmHeight - 2 * upperArmRadius);
//    bpRotation = btQuaternion(-1 * btSin(upperArmAngle / 2), 0, 0, btCos(upperArmAngle / 2));
//    bpTranslation = btVector3(0, upperArmBottom + upperArmAngledHeight / 2, upperArmZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = upperArmMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_RIGHT_UPPER_ARM] = new GrBulletObject(body);
//    addCylinderLinker(upperArmRadius, upperArmHeight, bodyParts[BODYPART_RIGHT_UPPER_ARM]);
//
//    // lower arms definition
//    btScalar lowerArmRadius = (btScalar) 0.035, lowerArmHeight = (btScalar) 0.28;
//    btScalar lowerArmTop = upperArmBottom;
//    btScalar lowerArmZOffset = (btScalar) 0.276;
//    btScalar lowerArmMass = bodyMass * (btScalar) 1.72 / 100;
//
//    // left lower arm
//    bpShape = new btCapsuleShape(lowerArmRadius, lowerArmHeight - 2 * lowerArmRadius);
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, lowerArmTop - lowerArmHeight / 2, -lowerArmZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = lowerArmMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_LEFT_LOWER_ARM] = new GrBulletObject(body);
//    addCylinderLinker(lowerArmRadius, lowerArmHeight, bodyParts[BODYPART_LEFT_LOWER_ARM]);
//
//    // right lower arm
//    bpShape = new btCapsuleShape(lowerArmRadius, lowerArmHeight - 2 * lowerArmRadius);
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, lowerArmTop - lowerArmHeight / 2, lowerArmZOffset);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = lowerArmMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_RIGHT_LOWER_ARM] = new GrBulletObject(body);
//    addCylinderLinker(lowerArmRadius, lowerArmHeight, bodyParts[BODYPART_RIGHT_LOWER_ARM]);
//
//    // neck definition
//    btScalar neckRadius = (btScalar) 0.05, neckHeight = (btScalar) 0.04;
//    btScalar neckTop = thoraxTop + neckHeight;
//    btScalar neckMass = (btScalar) 0.5;
//
//    // neck
//    bpShape = new btBoxShape(btVector3(neckRadius, neckHeight / 2, neckRadius));
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, neckTop - neckHeight / 2, 0);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = neckMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_NECK] = new GrBulletObject(body);
//    addCylinderLinker(neckRadius, neckHeight, bodyParts[BODYPART_NECK]);
//
//    // head definition
//    btScalar headRadius = (btScalar) 0.1, headHeight = (btScalar) 0.283;
//    btScalar headTop = neckTop + headHeight;
//    btScalar headMass = (btScalar) 5.0;
//
//    // head
//    bpShape = new btCapsuleShape(headRadius, headHeight - 2 * headRadius);
//    bpRotation = btQuaternion(0, 0, 0, 1);
//    bpTranslation = btVector3(0, headTop - headHeight / 2, 0);
//    bpMotionState = new btDefaultMotionState(btTransform(bpRotation, bpTranslation));
//    bpInertia = btVector3(0, 0, 0);
//    bpMass = headMass;
//    rbInfo = btRigidBody::btRigidBodyConstructionInfo(bpMass, bpMotionState, bpShape, bpInertia);
//    body = new btRigidBody(rbInfo);
//    world->addRigidBody(body);
//    bodyParts[BODYPART_HEAD] = new GrBulletObject(body);
//    addSphereLinker(headHeight / 2, bodyParts[BODYPART_HEAD]);
//
//    // create joints
//    btConeTwistConstraint *coneConstraint;
//    btHingeConstraint *hingeConstraint;
//
//    // head-neck
//    btTransform bodyA, bodyB;
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, 0, M_PI_2);
//    bodyA.setOrigin(btVector3(0, -(headHeight / 2 + 0.02), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, 0, M_PI_2);
//    bodyB.setOrigin(btVector3(0, neckHeight / 2 + 0.01, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_HEAD]->getRigidBody(),
//                                               *bodyParts[BODYPART_NECK]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, M_PI_2);
//    joints[JOINT_HEAD_NECK] = coneConstraint;
//    world->addConstraint(joints[JOINT_HEAD_NECK], false);
//
//    // neck-thorax
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, 0, M_PI_2);
//    bodyA.setOrigin(btVector3(0, -neckHeight / 2 - 0.02, 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, 0, M_PI_2);
//    bodyB.setOrigin(btVector3(0, thoraxHeight / 2 + 0.02, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_NECK]->getRigidBody(),
//                                               *bodyParts[BODYPART_THORAX]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_NECK_THORAX] = coneConstraint;
//    world->addConstraint(joints[JOINT_NECK_THORAX], true);
//
//    // thorax-leftupperarm
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, thoraxHeight / 2 - upperArmRadius, -(thoraxWidth / 2 + upperArmRadius)));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, upperArmHeight / 2 + upperArmRadius, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_THORAX]->getRigidBody(),
//                                               *bodyParts[BODYPART_LEFT_UPPER_ARM]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_2, M_PI_2, 0);
//    joints[JOINT_THORAX_LEFT_UPPER_ARM] = coneConstraint;
//    world->addConstraint(joints[JOINT_THORAX_LEFT_UPPER_ARM], true);
//
//    // left upper-lower arm
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(upperArmHeight / 2 + upperArmRadius / 2), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, lowerArmHeight / 2 + lowerArmRadius / 2, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_LEFT_UPPER_ARM]->getRigidBody(),
//                                               *bodyParts[BODYPART_LEFT_LOWER_ARM]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_2, M_PI_2, M_PI_4);
//    joints[JOINT_LEFT_ARM_UPPER_LOWER] = coneConstraint;
//    world->addConstraint(joints[JOINT_LEFT_ARM_UPPER_LOWER], true);
//
//    // thorax-rightupperarm
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, -M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, thoraxHeight / 2 - upperArmRadius, (thoraxWidth / 2 + upperArmRadius)));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, -M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, upperArmHeight / 2 + upperArmRadius, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_THORAX]->getRigidBody(),
//                                               *bodyParts[BODYPART_RIGHT_UPPER_ARM]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_2, M_PI_2, 0);
//    joints[JOINT_THORAX_RIGHT_UPPER_ARM] = coneConstraint;
//    world->addConstraint(joints[JOINT_THORAX_RIGHT_UPPER_ARM], true);
//
//    // right upper-lower arm
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(upperArmHeight / 2 + upperArmRadius / 2), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, lowerArmHeight / 2 + lowerArmRadius / 2, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_RIGHT_UPPER_ARM]->getRigidBody(),
//                                               *bodyParts[BODYPART_RIGHT_LOWER_ARM]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_2, M_PI_2, M_PI_4);
//    joints[JOINT_RIGHT_ARM_UPPER_LOWER] = coneConstraint;
//    world->addConstraint(joints[JOINT_RIGHT_ARM_UPPER_LOWER], true);
//
//    // thorax-abdomen
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(thoraxHeight / 2 - 0.05), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, abdomenHeight / 2 + 0.05, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_THORAX]->getRigidBody(),
//                                               *bodyParts[BODYPART_ABDOMEN]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_THORAX_ADBOMEN] = coneConstraint;
//    world->addConstraint(joints[JOINT_THORAX_ADBOMEN], true);
//
//    // abdomen-pelvis
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(abdomenHeight / 2 - 0.05), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, pelvisHeight / 2 + 0.05, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_ABDOMEN]->getRigidBody(),
//                                               *bodyParts[BODYPART_PELVIS]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_ABDOMEN_PELVIS] = coneConstraint;
//    world->addConstraint(joints[JOINT_ABDOMEN_PELVIS], true);
//
//    // pelvis-leftthigh
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(pelvisHeight / 2), -(pelvisWidth / 2 - thighRadius)));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, thighHeight / 2 + thighRadius, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_PELVIS]->getRigidBody(),
//                                               *bodyParts[BODYPART_LEFT_THIGH]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_PELVIS_LEFT_THIGH] = coneConstraint;
//    world->addConstraint(joints[JOINT_PELVIS_LEFT_THIGH], true);
//
//    // left thigh-leg
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(thighHeight / 2 + thighRadius), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, legHeight / 2 + legRadius, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_LEFT_THIGH]->getRigidBody(),
//                                               *bodyParts[BODYPART_LEFT_LEG]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_LEFT_THIGH_LEG] = coneConstraint;
//    world->addConstraint(joints[JOINT_LEFT_THIGH_LEG], true);
//
//    // left leg-foot
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(legHeight / 2 + legRadius), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(-footXOffset, footHeight + 0.03, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_LEFT_LEG]->getRigidBody(),
//                                               *bodyParts[BODYPART_LEFT_FOOT]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_LEFT_LEG_FOOT] = coneConstraint;
//    world->addConstraint(joints[JOINT_LEFT_LEG_FOOT], true);
//
//
//    // pelvis-rightthigh
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(pelvisHeight / 2), (pelvisWidth / 2 - thighRadius)));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, thighHeight / 2 + thighRadius, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_PELVIS]->getRigidBody(),
//                                               *bodyParts[BODYPART_RIGHT_THIGH]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_PELVIS_RIGHT_THIGH] = coneConstraint;
//    world->addConstraint(joints[JOINT_PELVIS_RIGHT_THIGH], true);
//
//    // RIGHT thigh-leg
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(thighHeight / 2 + thighRadius), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(0, legHeight / 2 + legRadius, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_RIGHT_THIGH]->getRigidBody(),
//                                               *bodyParts[BODYPART_RIGHT_LEG]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_RIGHT_THIGH_LEG] = coneConstraint;
//    world->addConstraint(joints[JOINT_RIGHT_THIGH_LEG], true);
//
//    // RIGHT leg-foot
//    bodyA.setIdentity();
//    bodyA.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyA.setOrigin(btVector3(0, -(legHeight / 2 + legRadius), 0));
//    bodyB.setIdentity();
//    bodyB.getBasis().setEulerZYX(0, M_PI_2, 0);
//    bodyB.setOrigin(btVector3(-footXOffset, footHeight + 0.03, 0));
//    coneConstraint = new btConeTwistConstraint(*bodyParts[BODYPART_RIGHT_LEG]->getRigidBody(),
//                                               *bodyParts[BODYPART_RIGHT_FOOT]->getRigidBody(),
//                                               bodyA,
//                                               bodyB);
//    coneConstraint->setLimit(M_PI_4, M_PI_4, 0);
//    joints[JOINT_RIGHT_LEG_FOOT] = coneConstraint;
//    world->addConstraint(joints[JOINT_RIGHT_LEG_FOOT], true);
//
//}
//
//Ragdoll::~Ragdoll()
//{
//    for (int i = 0; i < JOINT_COUNT; i++) {
//        // TODO: remove constraints and delete constraints
//        world->removeConstraint(joints[i]);
//        delete joints[i];
//    }
//
//    for (int i = 0; i < BODYPART_COUNT; i++) {
//        world->removeRigidBody(bodyParts[i]->rigidBody);
//        delete bodyParts[i];
//    }
//}
//
//void Ragdoll::draw()
//{
//    //bodyParts[0]->draw();
//    for (int i = 0; i < BODYPART_COUNT; i++) {
//        bodyParts[i]->draw();
//    }
//}
//
//void Ragdoll::update()
//{
//    //bodyParts[0]->update();
//    for (int i = 0; i < BODYPART_COUNT; i++) {
//        bodyParts[i]->update();
//    }
//}
//
//void Ragdoll::resetPosition()
//{
//    for (int i = 0; i < BODYPART_COUNT; i++) {
//        bodyParts[i]->resetPosition();
//        bodyParts[i]->activate();
//    }
//}
//
//void Ragdoll::RNJesus()
//{
//    // TODO : set RNG launch
//    srand((unsigned int) time(NULL));
//    int random = rand() % BODYPART_COUNT;
//    // choose body part, set launch
//    btScalar vx = rand() % 800 - 400;
//    btScalar vy = rand() % 800 - 400;
//    btScalar vz = rand() % 800 - 400;
//    bodyParts[random]->getRigidBody()->applyCentralImpulse(btVector3(vx, vy, vz));
//
//    //bodyParts[BODYPART_HEAD]->getRigidBody()->setLinearVelocity(btVector3(-15, 0, 0));
//    //bodyParts[BODYPART_RIGHT_LOWER_ARM]->getRigidBody()->setAngularVelocity(btVector3(0, 1, 0));
//
//    //bodyParts[BODYPART_HEAD]->getRigidBody()->activate(true);
//    //bodyParts[BODYPART_HEAD]->getRigidBody()->applyCentralForce(btVector3(-15000, 0, 0));
//    //bodyParts[BODYPART_HEAD]->getRigidBody()->applyCentralImpulse(btVector3(-1500, 0, 0));
//}
//
//void Ragdoll::addBoxLinker(btScalar halfX, btScalar halfY, btScalar halfZ, GrBulletObject *object)
//{
//    GrLinkerBoxShape *box = new GrLinkerBoxShape(halfX, halfY, halfZ);
//    object->setLinker(box);
//}
//
//void Ragdoll::addCylinderLinker(btScalar radius, btScalar height, GrBulletObject *object)
//{
//    GrLinkerCylinderShape *cylinder = new GrLinkerCylinderShape(radius, height);
//    object->setLinker(cylinder);
//}
//
//void Ragdoll::addSphereLinker(btScalar radius, GrBulletObject *object)
//{
//    GrLinkerSphereShape *sphere = new GrLinkerSphereShape(radius);
//    object->setLinker(sphere);
//}