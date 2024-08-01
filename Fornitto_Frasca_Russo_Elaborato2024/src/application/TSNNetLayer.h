#ifndef __ELABORATO2024_TSNNETLAYER_H_
#define __ELABORATO2024_TSNNETLAYER_H_

#include <omnetpp.h>
#include "inet/common/INETDefs.h"
#include "inet/common/packet/Packet.h"

using namespace omnetpp;
using namespace inet;

class TSNNetLayer : public cSimpleModule {
  protected:
    struct Socket {
        int socketId = -1;
        std::string flowName;

        Socket(int socketId) : socketId(socketId) {}
        bool matches(Packet *packet);
    };

    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;

    std::map<int, Socket *> socketIdToSocketMap;
};

#endif
