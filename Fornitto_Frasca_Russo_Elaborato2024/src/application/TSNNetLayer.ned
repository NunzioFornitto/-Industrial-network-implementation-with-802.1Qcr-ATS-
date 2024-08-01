package elaborato2024.application;

import inet.networklayer.contract.INetworkLayer;

simple TSNNetLayer like INetworkLayer {
    gates:
        input transportIn @labels(ITransportPacket/down);
        output transportOut @labels(ITransportPacket/up);
        input ifIn @labels(INetworkHeader/up);
        output ifOut @labels(INetworkHeader/down);
}
