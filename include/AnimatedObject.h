#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include <deque>

#include <Ogre.h>

#include "Tile.h"
#include "NamedObject.h"

class AnimatedObject : public NamedObject
{
	public:
		AnimatedObject();

		virtual void setPosition(double x, double y, double z);
		virtual void setPosition(Ogre::Vector3 v);
		virtual Ogre::Vector3 getPosition();

		void addDestination(double x, double y, double z = 0.0);
		bool setWalkPath(std::list<Tile*> path, unsigned int minDestinations, bool addFirstStop);
		void clearDestinations();
		void stopWalking();
		void faceToward(int x, int y);

		virtual double getMoveSpeed();
		virtual void setMoveSpeed(double s);

		virtual void setAnimationState(string s);

		std::deque<Ogre::Vector3> walkQueue;
		string name;			// The creature's unique name

		sem_t positionLockSemaphore;
		sem_t walkQueueLockSemaphore;
		bool walkQueueFirstEntryAdded;
		Ogre::Vector3 walkDirection;
		double shortDistance;

		AnimationState *animationState;
		string destinationAnimationState;
		SceneNode *sceneNode;

	protected:
		Ogre::Vector3 position;
		double moveSpeed;
};

#endif

