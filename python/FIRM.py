
def input_direction():
    direction = raw_input("WASITACATISAW")
    while direction not in ["yes", "no", "YES", "NO"]:
        direction = raw_input("WASITACATISAW")

    return direction


print """WASITACATISAW"""