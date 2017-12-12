//
//  ComputerGenerator.cpp
//  Ramshackle-iOS
//
//  Created by sweetman on 12/10/17.
//  Copyright © 2017 tinfish. All rights reserved.
//

#include "ComputerGenerator.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "Powerable.hpp"
#include "ComputerCPU.hpp"
#include "ComputerMemory.hpp"
#include "ComputerDiskInterface.hpp"
#include "ComputerNetworkInterfaces.hpp"
#include "Type.hpp"
#include "Physical.hpp"
#include "OperatingSystem.hpp"

NS_RAM_OPEN

Entity* ComputerGenerator::generateComputer() {
    Entity *computer = new Entity();
    
    Type *type = new Type("computer");
    computer->addComponent(type);
    
    Physical *body = new Physical();
    computer->addComponent(body);
    
    Powerable *powerable = new Powerable();
    computer->addComponent(powerable);
    
    ComputerCPU *cpu = new ComputerCPU(4, 2.6);
    computer->addComponent(cpu);
    
    ComputerMemory *memory = new ComputerMemory(4096);
    computer->addComponent(memory);
    
    ComputerDiskInterface *disk = new ComputerDiskInterface({new ComputerSSD(256)});
    computer->addComponent(disk);
    
    ComputerNetworkInterfaces *iface = new ComputerNetworkInterfaces({"Ethernet"});
    computer->addComponent(iface);
    
    OperatingSystem *os = new OperatingSystem(400, 400);
    computer->addComponent(os);
    os->installOn(computer);
    
    return computer;
}

Entity* ComputerGenerator::generateRouter() {
    Entity *router = new Entity();
    
    Type *type = new Type("router");
    router->addComponent(type);
    
    Physical *body = new Physical();
    router->addComponent(body);
    
    Router *routerComponent = new Router();
    router->addComponent(routerComponent);
    
    return router;
}

void ComputerGenerator::connect(Router *router,
                                std::vector<Entity*> computers)
{
    for (auto computer : computers) {
        auto interface = computer->getComponent<ComputerNetworkInterfaces>();
        router->connectDevice(interface);
    }
}

NS_RAM_CLOSE
