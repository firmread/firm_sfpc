# Python adventure game

# Define the direction variable
direction = ''

# Print out a statement setting the scene for the user
print """Welcome to sfpc
'look around' to see what you can interact with
interactive objects are capitalized
interact with them by 'use ITEM'
for example type 'use sfpc' to begin."""

# Keep doing this until they have entered either left or right
while direction not in ["left","right"]:

    # Ask the user where they want to go
    direction = raw_input("Do you want to go left or right?: ")

    # Decide what happens 
    if direction == "left":
        print "\nYou have entered the bear's lair!"
        print "Sadly all that is left of you is a pile of bones."
    elif direction == "right":
        print "\nThe back of this passage seems to lead somewhere..."
    else:
        print "That is not a direction"f