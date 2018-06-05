#include "EventSubscriber.h"

void EventSubscriber::subscribed(EventManager* manager, int hash)
{
    mManager = manager;
    mHash = hash;
}

EventSubscriber::~EventSubscriber()
{
    if (mManager != NULL) {
        mManager->unsubscribe(mHash);
    }

}