
Nel file EthernetApplication.cc alla riga 46:

pkt->addTag<PacketProtocolTag>()->setProtocol(&Protocol::unknown);

L'errore per cui non funzionava stava nel file omnetpp.ini perchè non avevamo impostato il local address.
Vedere riga 14 e riga 18 del file omnetpp.ini
