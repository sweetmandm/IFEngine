//
//  ComputerNetworkInterface.hpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#ifndef ComputerNetworkInterface_hpp
#define ComputerNetworkInterface_hpp

#include "Component.hpp"
#include <string>

NS_RAM_OPEN

class ComputerNetworkInterfaces;

class IPAddress {
    uint8_t _octets[4];
public:
    IPAddress(uint8_t octet0, uint8_t octet1, uint8_t octet2, uint8_t octet3);
    std::string stringValue();
    uint8_t octetAt(int index);
    
    static IPAddress nullIP() { return IPAddress(192, 0, 2, 0); };
    bool isNullIP() { return
        _octets[0] == 192 && _octets[1] == 0 &&
        _octets[2] == 2 && _octets[3] == 0;
    };
};

class NetworkInterface {
    std::string _type;
    IPAddress _ip;
    ComputerNetworkInterfaces *_owner;
public:
    NetworkInterface(std::string type, IPAddress ip, ComputerNetworkInterfaces *owner);
    std::string getType() { return _type; };
    IPAddress getIP() { return _ip; };
    void setIP(IPAddress ip) { _ip = ip; };
    ComputerNetworkInterfaces* getOwner() { return _owner; };
};

class ComputerNetworkInterfaces : public Component {
protected:
    NetworkInterface _loopback;
    std::vector<NetworkInterface> _interfaces;
public:
    ComputerNetworkInterfaces(std::vector<std::string> interfaceTypes);
    std::vector<NetworkInterface> getInterfaces() { return _interfaces; };
    NetworkInterface* getInterfaceNamed(std::string typeName);
    bool isWifiOnline();
    bool isEthernetOnline();
    bool isOnline();
};

class Router : public ComputerNetworkInterfaces {
    
    enum ConnetionResult {
        Connected,
        Failure,
        TooManyDevices
    };
    
    NetworkInterface _gateway;
    std::vector<NetworkInterface*> _devices;
    
    std::vector<uint8_t> _ipPool;
    IPAddress generateAddress();
    
public:
    Router();
    ConnetionResult connectDevice(ComputerNetworkInterfaces *interfaces);
    ConnetionResult connectDevice(NetworkInterface *device);
    void disconnectDevice(NetworkInterface *device);
};

NS_RAM_CLOSE

#endif /* ComputerNetworkInterface_hpp */
