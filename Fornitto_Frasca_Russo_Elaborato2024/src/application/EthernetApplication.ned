package elaborato2024.application;

import inet.applications.contract.IApp;

simple EthernetApplication like IApp
{
    parameters:
        double startTime @unit(s) = default(-1s);
        volatile double period @unit(s) = default(0s);
        volatile int payload @unit(B) = default(0B);
        int vlanid = default(0);
        int priority = default(0);
        double interarrivalTime @unit(s) = default(0s);
        string name = default("");
        string localAddress = default("");
        string remoteAddress = default("");
        string netInterface = default("eth0");
        int mtu @unit(B) = default(1500B);
        string interfaceTableModule = default("^.interfaceTable");
        @display("i=block/app2");
        
        @signal[BurstDelay];
        @signal[FrameDelay];
        @statistic[BurstDelay](record=vector);
        @statistic[FrameDelay](record=vector);
    gates:
        input socketIn;
        output socketOut;
}
