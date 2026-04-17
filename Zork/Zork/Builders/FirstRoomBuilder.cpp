#include "FirstRoomBuilder.h"
#include "../Rooms/Room.h"
#include "../Entities/Entity.h"

Room* BuildFirstRoom()
{
    Room* room = new Room("Room",
        "Hello you are in a {room}... Yay?",
        0);

    room->AddEntity(new Entity("Object",
        "An {object} on the ground. Yay!",
        0));

    room->AddEntity(new Entity("Object",
        "A FURTHER AWAY {object} on the ground. Yay!!!",
        1));

    return room;
}
