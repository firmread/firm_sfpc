# Python adventure game

# Define the direction variable
direction1 = ''

# Print out a statement setting the scene for the user
print """As you step into the cave you can smell musty cobwebs and the
dank odour of dripping water. At the back of the cave the path forks
and you can see two directions to travel, left and right."""

# Keep doing this until they have entered either left or right
while direction1 not in ["left","right"]:

    # Ask the user where they want to go
    direction1 = raw_input("Do you want to go left or right?: ")

    # Decide what happens 
    if direction1 == "left":
        print "\nYou have entered the bear's lair!"
        print "Sadly all that is left of you is a pile of bones."
    elif direction1 == "right":
        print "\nThe back of this passage seems to lead somewhere..."
    else:
        print "That is not a direction"