package elaborato2024.simulations;

import inet.node.ethernet.Eth100M;
import inet.node.tsn.TsnDevice;
import inet.node.inet.StandardHost;
import inet.networks.base.TsnNetworkBase;
import inet.node.tsn.TsnSwitch;
import ned.IdealChannel;

network TestNet extends TsnNetworkBase
{
    parameters:
        **.bitrate = default(100Mbps);

        @display("bgb=1739.952,780.192");
    submodules:
        device0: TsnDevice {
            @display("p=490.21875,50.11125");
        }
        switch0: TsnSwitch {
            @display("p=490.21875,200.445");
        }
        device1: TsnDevice {
            @display("p=610.05,50.11125");
        }
        switch1: TsnSwitch {
            @display("p=629.65875,200.445");
        }
        switch2: TsnSwitch {
            @display("p=750,200");
        }
        device2: TsnDevice {
            @display("p=750,52");
        }
        controller: TsnDevice {
            @display("p=343,195");
        }
        device4: TsnDevice {
            @display("p=1092.888,51.084");
        }
        switch3: TsnSwitch {
            @display("p=931.896,199.692");
        }
        device3: TsnDevice {
            @display("p=931.896,51.084");
        }
        device5: TsnDevice {
            @display("p=1270.908,51.084");
        }
        switch4: TsnSwitch {
            @display("p=1092.888,198.144");
        }
        switch5: TsnSwitch {
            @display("p=1270.908,199.692");
        }
        device6: TsnDevice {
            @display("p=1488.0863,34.86");
        }
        switch6: TsnSwitch {
            @display("p=1488.0863,191.73");
        }
        device7: TsnDevice {
            @display("p=1640.5988,34.86");
        }
        switch7: TsnSwitch {
            @display("p=1640.5988,196.0875");
        }


    connections:
        device1.ethg++ <--> Eth100M <--> switch1.ethg++;
        switch1.ethg++ <--> Eth100M <--> switch2.ethg++;
        switch2.ethg++ <--> Eth100M <--> device2.ethg++;
        controller.ethg++ <--> Eth100M <--> switch0.ethg++;
        switch0.ethg++ <--> Eth100M <--> switch1.ethg++;
        switch0.ethg++ <--> Eth100M <--> device0.ethg++;
        switch2.ethg++ <--> Eth100M <--> switch3.ethg++;
        switch3.ethg++ <--> Eth100M <--> device3.ethg++;
        switch3.ethg++ <--> Eth100M <--> switch4.ethg++;
        switch4.ethg++ <--> Eth100M <--> device4.ethg++;
        switch4.ethg++ <--> Eth100M <--> switch5.ethg++;
        switch5.ethg++ <--> Eth100M <--> device5.ethg++;
        switch5.ethg++ <--> Eth100M <--> switch6.ethg++;
        switch6.ethg++ <--> Eth100M <--> device6.ethg++;
        switch7.ethg++ <--> Eth100M <--> switch6.ethg++;
        switch7.ethg++ <--> Eth100M <--> device7.ethg++;

}
