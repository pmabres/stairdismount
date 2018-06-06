#include "EventSubscriber.h"

namespace Game
{
void EventSubscriber::subscribed(EventModule *manager, int hash)
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
}
