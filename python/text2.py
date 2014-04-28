# Python adventure game using dictionaries

# Validate their input direction

def input_direction():
    direction = raw_input("Which direction do you want to go? ")
    while direction not in ["north", "south", "east", "west", "exit"]:
        direction = raw_input("Which direction do you want to go ")

    return direction

# ---------------------------------------------
# Set up the rooms

compass = dict({ "north" : {0: 1, 1:2, 2:-1},
                 "south" : {0: -1, 1:0, 2:1}
                })

descr = dict({0: "You are in a small lobby type room.",
              1: "You are in a grand hall way",
              2: "You are in a huge palace"})

currentRoom = 0
newDir = ""

# Game loop
while( currentRoom != -1 ):

    # Describe the current room
    print descr[currentRoom]

    # Ask what they want to do
    newDir = input_direction()

    # If they wish to exit
    if newDir == "exit":
        print "See ya later, alligator!"
        currentRoom = -1
    else:

        # Otherwise look up whether there is a path that way
        if compass[newDir][currentRoom] != -1:
            currentRoom = compass[newDir][currentRoom]
        else:
            print "There is no path in that direction"