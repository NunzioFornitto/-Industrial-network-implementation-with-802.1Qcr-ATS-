#ifndef __ELABORATO2024_ETHERNETAPPLICATION_H_
#define __ELABORATO2024_ETHERNETAPPLICATION_H_

#include <omnetpp.h>
#include "inet/applications/base/ApplicationBase.h"
#include "inet/linklayer/common/MacAddress.h"
#include "inet/networklayer/common/NetworkInterface.h"
#include "TSNSocket.h"

using namespace omnetpp;
using namespace inet;


class EthernetApplication : public ApplicationBase, public TSNSocket::ICallback {
  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void handleMessageWhenUp(cMessage *msg) override;

    virtual void handleStartOperation(LifecycleOperation *operation) override;
    virtual void handleStopOperation(LifecycleOperation *operation) override;
    virtual void handleCrashOperation(LifecycleOperation *operation) override;

    virtual void socketDataArrived(TSNSocket *socket, Packet *packet) override;
    virtual void socketErrorArrived(TSNSocket *socket, Indication *indication) { };
    virtual void socketClosed(TSNSocket *socket) { }

    virtual void generateFrames();
    virtual void transmitFrames();

    cPacketQueue queue;
    MacAddress localAddress;
    MacAddress remoteAddress;
    NetworkInterface *networkInterface = nullptr;
    TSNSocket socket;
};

#endif
