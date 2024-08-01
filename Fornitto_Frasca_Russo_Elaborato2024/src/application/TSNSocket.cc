#include "TSNSocket.h"
#include "EthernetDataFrames_m.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/common/socket/SocketTag_m.h"

void TSNSocket::sendOut(cMessage *msg) {
    SocketBase::sendOut(msg);
}

void TSNSocket::sendOut(Request *request) {
    request->addTag<DispatchProtocolReq>()->setProtocol(&Protocol::tsn);
    SocketBase::sendOut(request);
}

void TSNSocket::sendOut(Packet *packet) {
    packet->addTag<DispatchProtocolReq>()->setProtocol(&Protocol::tsn);
    SocketBase::sendOut(packet);
}

void TSNSocket::bind(const char *flowName) {
    auto request = new Request("BIND", SOCKET_C_BIND);
    TSNBindCommand *ctrl = new TSNBindCommand();
    ctrl->setFlowName(flowName);
    request->setControlInfo(ctrl);
    isOpen_ = true;
    sendOut(request);
}

void TSNSocket::processMessage(cMessage *msg) {
    ASSERT(belongsToSocket(msg));
    switch (msg->getKind()) {
        case SOCKET_I_DATA:
            if (callback)
                callback->socketDataArrived(this, check_and_cast<Packet *>(msg));
            else
                delete msg;
            break;
        case SOCKET_I_CLOSED:
            isOpen_ = false;
            if (callback)
                callback->socketClosed(this);
            delete msg;
            break;
        default:
            throw cRuntimeError("EthernetSocket: invalid msg kind %d, one of the ETHERNNET_I_xxx constants expected", msg->getKind());
            break;
    }
}
