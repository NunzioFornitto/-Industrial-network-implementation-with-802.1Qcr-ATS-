import inet.common.INETDefs;
import inet.common.packet.chunk.Chunk;
import inet.common.Protocol;
import inet.common.socket.SocketCommand;
import inet.linklayer.common.MacAddress;

namespace inet;

class EthernetDataPayload extends inet::FieldsChunk {
    int frame_num;
    int burst_size;
    simtime_t genTime;
}

class TSNBindCommand extends SocketBindCommand {
    string flowName;
}