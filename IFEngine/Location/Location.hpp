//
//  Location.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

#include "Entity.hpp"
#include "Component.hpp"
#include <string>

// Location
// - name
// - description (change over time)
// - objects (interactable or observable)
// - characters (change over time, interactable and observable)

// 'Locations' are long-running game objects that change infrequently.
// Each object in the Location might be allowed a life of its own. For example,
// the Researcher's actions and motivations are influenced by his stats. If he
// becomes afraid, he'll act differently, potentially witholding training or
// threatening shutdown, and you'll have to change your tactics. If his
// motivations are contrary to your own goals, you'll have to manipulate
// him or try to get him to change his mind.

// Initial Location:
// Office
//  Characters:
//  - Researcher
//  Objects:
//  - Power Source: wall outlet

NS_RAM_OPEN

class Location : public Component {

protected:
    std::string _name;
    std::string _description;
    std::vector<Entity*> _objects;
public:
    Location(std::string name, std::string description);
    std::string getName() { return _name; };
    std::string getDescription() { return _description; };
    
    std::vector<Entity*> getObjects() { return _objects; };
    void addObject(Entity *entity);
    void removeObject(Entity *entity);
    
    template<typename C>
    std::vector<Entity*> findObjectsWithComponent() {
        std::vector<Entity*> results;
        for (auto e : _objects) {
            if (e->getComponent<C>()) {
                results.push_back(e);
            }
        }
        return results;
    };
};

NS_RAM_CLOSE

#endif /* Location_hpp */
