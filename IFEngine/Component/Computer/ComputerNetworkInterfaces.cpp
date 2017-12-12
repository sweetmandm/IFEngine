//
//  ComputerNetworkInterfaces.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "ComputerNetworkInterfaces.hpp"
#include <algorithm>

NS_RAM_OPEN

IPAddress::IPAddress(uint8_t octet0, uint8_t octet1, uint8_t octet2, uint8_t octet3) {
    _octets[0] = octet0;
    _octets[1] = octet1;
    _octets[2] = octet2;
    _octets[3] = octet3;
}

std::string IPAddress::stringValue() {
    char fmt[12] = "%d.%d.%d.%d";
    char result[15];
    int len = sprintf(result, fmt, _octets[0], _octets[1], _octets[2], _octets[3]);
    result[len] = '\0';
    return std::string(result);
};
uint8_t IPAddress::octetAt(int index) {
    return _octets[std::min(0, std::max(3, index))];
}

NetworkInterface::NetworkInterface(std::string type, IPAddress ip, ComputerNetworkInterfaces *owner)
: _type(type)
, _ip(ip)
, _owner(owner)
{ }

ComputerNetworkInterfaces::ComputerNetworkInterfaces(std::vector<std::string> interfaceTypes)
: _loopback(NetworkInterface("loopback", IPAddress(127, 0, 0, 1), this))
{
    for (auto type : interfaceTypes) {
        _interfaces.push_back(NetworkInterface(type, IPAddress::nullIP(), this));
    }
}

NetworkInterface* ComputerNetworkInterfaces::getInterfaceNamed(std::string typeName) {
    for (size_t i = 0; i < _interfaces.size(); i++) {
        if (_interfaces[i].getType() == typeName) {
            return &_interfaces[i];
        }
    }
    return nullptr;
};

bool ComputerNetworkInterfaces::isWifiOnline() {
    auto result = std::find_if(_interfaces.begin(), _interfaces.end(), [](NetworkInterface interface) {
        bool isOnWifi = interface.getType() == "WiFi" && !interface.getIP().isNullIP();
        return isOnWifi;
    });
    return result != _interfaces.end();
}

bool ComputerNetworkInterfaces::isEthernetOnline() {
    auto result = std::find_if(_interfaces.begin(), _interfaces.end(), [](NetworkInterface interface) {
        bool isOnEthernet = interface.getType() == "Ethernet" && !interface.getIP().isNullIP();
        return isOnEthernet;
    });
    return result != _interfaces.end();
}

bool ComputerNetworkInterfaces::isOnline() {
    return isEthernetOnline() || isWifiOnline();
};

Router::Router()
: ComputerNetworkInterfaces::ComputerNetworkInterfaces({})
, _gateway(NetworkInterface("gateway", IPAddress(192, 168, 1, 1), this))
{
    _ipPool.reserve(UINT8_MAX - 2);
    for (int i = 2; i < UINT8_MAX; i++) {
        _ipPool.push_back(i);
    }
    
    _interfaces.push_back(_gateway);
    _devices.push_back(&_gateway);
}

IPAddress Router::generateAddress() {
    auto f = _ipPool.front();
    _ipPool.erase(_ipPool.begin());
    return IPAddress(192, 168, 1, f);
};

Router::ConnetionResult Router::connectDevice(NetworkInterface *device) {
    if (std::find(_devices.begin(), _devices.end(), device) != _devices.end()) {
        return Connected;
    }
    if (_ipPool.size() > 0) {
        IPAddress ip = generateAddress();
        device->setIP(ip);
        _devices.push_back(device);
        return Connected;
    } else {
        return TooManyDevices;
    }
}

Router::ConnetionResult Router::connectDevice(ComputerNetworkInterfaces *interfaces) {
    auto ether = interfaces->getInterfaceNamed("Ethernet");
    if (ether) {
        connectDevice(ether);
        return Connected;
    }
    auto wifi = interfaces->getInterfaceNamed("WiFi");
    if (wifi) {
        connectDevice(wifi);
        return Connected;
    }
    return Failure;
}

void Router::disconnectDevice(NetworkInterface *device) {
    auto found = std::find(_devices.begin(), _devices.end(), device);
    if (found != _devices.end()) {
        NetworkInterface *device = *found;
        _devices.erase(found);
        IPAddress ip = device->getIP();
        uint8_t octet3 = ip.octetAt(3);
        device->setIP(IPAddress::nullIP());
        _ipPool.push_back(octet3);
    }
}

NS_RAM_CLOSE
