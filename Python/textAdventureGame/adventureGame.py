#Text adventure game
import random as r
import sys

#Ideally, add a little bit of story.
#room info assigning functions
def set_room_desc(gridmap, x, y, text): #Need to call this when changing room description; aka the text you see upon entering a room.
    gridmap[x][y]["Description"] = [text]

def remove_room_item(gridmap, x, y, item): #Need to call this when removing items from a room.
    if item in gridmap[x][y]["Items"]:
        gridmap[x][y]["Items"].remove(item)

#win/lose condition functions
def win_condition():
    print("Congratulations, you have finished the adventure.")
    sys.exit()

def fail_condition():
    if Player.Health <= 0:
        print('Game Over! Run the code to try again.')
        sys.exit()
    else:
        return

#Defining the map layout; 5 rows, 5 columns.
gridmap = [[{"Items": [], "Encounter": [], "Interactables": [], "Description": [], "Valid": True, "Action": None}for _ in range(5)] for _ in range(5)]

#Defining possible Encounters, Interactables, traps, and consumable items.
encounter_list = ['Ghost', 'Orc', 'Slime', 'Treasure Hunter', 'Seer']
interactable_list = ['Mirror', 'Chest', 'Sofa']
trap_list = ['Mimic', 'Bear Trap', 'Swinging Axes']
cons_list = ["Potion", "Teleportation Scroll"] #Consumable items. Remember to append this to gridmap variables for random item gen.
trivia_solved = False #Declaring False to use later in trivia_room.

#Assigning room functionality:
def spawn_room(Player, gridmap, command):

    x, y = 2, 2,
    room = gridmap[x][y]

    if command.strip().lower() in ['torch', 'pick up', 'pick up torch']:

        if "Torch x1" in room["Items"]:
            Player.Inventory.append("Torch x1")
            remove_room_item(gridmap, x, y, "Torch x1")
            set_room_desc(gridmap, x, y, "The room seems darker without the torch. Bozo.")
            print("You picked up the Torch.")

        else:
            print("You already picked up the Torch.")

def trivia_room(Player, gridmap, command):

    global trivia_solved
    room = gridmap[3][4]

    if "Key #1" in Player.Inventory or trivia_solved == True:
        if command.strip().lower() in ['read', 'inspect', 'look', 'wall', 'text', 'squint', 'read closely', 'squint and read closely']:
            command = 'n'
        room_info(Player, gridmap)
        return

    if command.strip().lower() in ['read', 'inspect', 'look', 'wall', 'text', 'squint', 'read closely', 'squint and read closely']:
        sel_quest = r.randint(1, 3)

        if sel_quest == 1:
            question = "What is the boiling point of water in Fahrenheit?"
            answers = ["212°", "100°", "373°"]
            correct = "1"

        elif sel_quest == 2:
            question = "Which Latin phrase translates to, 'Out of many, one?'"
            answers = ["Incepto ne Desistam", "Caveat Emptor", "E Pluribus Unum"]
            correct = "3"

        else:
            question = "In The Elder Scrolls V: Skyrim, which Skill has the most amount of Skill Books without a named author?"
            answers = ["Sneak", "Two Handed", "Alteration"]
            correct = "2"
        print(question)

        for i, choice in enumerate(answers, 1):
            print(f"{i}. {choice}")
        answer = input("Your answer (1, 2, or 3): ").strip()

        if answer == correct:
            print("Correct! I have heard that this knowledge is difficult to... compartmentalize.")
            trivia_solved = True
            set_room_desc(gridmap, 2, 4, "A small compartment has opened, revealing a key. Do you want to pick it up?")
            room["Description"] = ["The text on the wall has faded. Was it ever truly there?"]

        else:
            print("Incorrect.")
            Player.player_take_damage(10)
    else:
        room["Description"] = ["The wall illuminates with text, asking: (You must squint and read closely)."]
        room_info(Player, gridmap)

def ladder_room(Player, gridmap, command):

    x, y = Player.Current_Position
    print("Who put this here?")

    if command.strip().lower() in ['ladder', 'pick up', 'pick up ladder', 'take', 'take ladder']:
        Player.Inventory.append("Ladder x1")
        remove_room_item(gridmap, x, y, "Ladder x1")
        print("You picked up the Ladder. Heavy as.")

    else:
        set_room_desc(gridmap, x, y, "You already picked up the Ladder. Don't eat it all in one sitting.")

    room_info(Player, gridmap)

def gift_item_room(Player, gridmap, command):

    x, y = Player.Current_Position
    room = gridmap[x][y]

    if command.strip().lower() in ['work', 'rig', 'oil rig']:
        print("You slaved away at the oil rig for the rest of your life.")
        print("You got the oil rig ending!")
        win_condition()

    if command.strip().lower() in ['pick up', 'staff', 'pick up staff', 'take', 'take staff', 'aged wooden staff']:
        if "Aged Wooden Staff x1" in room["Items"]:
            Player.Inventory.append("Aged Wooden Staff x1")
            remove_room_item(gridmap, x, y, "Aged Wooden Staff x1")
            print("You picked up the Staff. It hums with pure holy energy.")
            set_room_desc(gridmap, x, y, "The wild oil rig cries about high overhead and low profit margins now that it is understaffed.")

        else:
            print("You already picked up the Staff.")

    room_info(Player, gridmap)

def healer_npc_room(Player, gridmap, command):

    if command.strip().lower() in ['talk', 'speak', 'robed man', 'man', 'hi', 'hello', 'interact']:
        print('"Have you seen my wooden staff?"')

        if "Aged Wooden Staff x1" in Player.Inventory:
            print('"Is that my staff you are holding?"')

    elif command.strip().lower() in ['yes', 'staff', 'give', 'give staff']:
        print('"Thank you for retrieving my staff. Let me reward you with a full heal."')
        print("As the robed man casts an incantation, his staff resonates with the altar. Suddenly, you feel like a million bucks.")
        Player.Inventory.remove("Aged Wooden Staff x1")
        Player.Health = 20
        set_room_desc(gridmap, x, y, "You have returned the staff.")
    else:
        print("You have nothing for me.")

    room_info(Player, gridmap)


def key_1_room(Player, gridmap, command):

    global trivia_solved
    x, y = Player.Current_Position
    room = gridmap[x][y]

    if trivia_solved == True:
        if "Key #1" not in Player.Inventory:

            if command.strip().lower() in ['pick up', 'pick up key', 'key', 'loot', 'take', 'take key', 'compartment', 'yes', 'pick it up']:
                Player.Inventory.append("Key #1")
                set_room_desc(gridmap, x, y, "You pick up the key. The room seems lonelier without it.")

        else:
            set_room_desc(gridmap, x, y, "You have already taken the key here. Thief.")
    else:
        set_room_desc(gridmap, x, y, "There is a sealed compartment. Who knows how to open it?")

    if all(key in Player.Inventory for key in ['Key #1', 'Key #2', 'Key #3']):
        set_room_desc(gridmap, 0, 4, "A strange door has materialized. Maybe you can unlock it?")

    room_info(Player, gridmap)

def key_2_room(Player, gridmap, command):

    #Alternate ending
    if command.strip().lower() in ['look', 'look up', 'look around', 'search'] and "Key #2" in Player.Inventory:
        print("You find a book that describes the history of the dungeon. Seems like some evil ass wizard teleported you here.")
        print("You set off to kill the wizard and achieve the vengeance ending.")
        win_condition()

    if command.strip().lower() in ['torch', 'use torch', 'light', 'light up']:
        if "Torch x1" in Player.Inventory:
            print("You use the torch to light up your surroundings. You spot a nearby key and pick it up.")
            Player.Inventory.remove('Torch x1')
            Player.Inventory.append('Key #2')

        else:
            print("You already used the torch. Poof.")

        if all(key in Player.Inventory for key in ['Key #1', 'Key #2', 'Key #3']):
            set_room_desc(gridmap, 0, 4, "A strange door has materialized. Maybe you can unlock it?")

def key_3_room(Player, gridmap, command):

    #Alternate ending
    if command.strip().lower() in ['talk', 'look', 'search', 'inspect'] and "Key #3" in Player.Inventory:
        print('"You should not be here."')
        print("You got stabbed by the underground maniac and earned the London ending!")
        Player.player_take_damage(20)

    if command.strip().lower() in ['ladder', 'use ladder', 'place ladder']:
        if "Ladder x1" in Player.Inventory:
            print("You explore the underground passage. On the table sits a key, which you pick up.")
            Player.Inventory.remove('Ladder x1')
            Player.Inventory.append('Key #3')

        else:
            print("You already ate the entire ladder. Fatass.")

        if all(key in Player.Inventory for key in ['Key #1', 'Key #2', 'Key #3']):
            set_room_desc(gridmap, 0, 4, "A strange door has materialized. Maybe you can unlock it?")

def final_room(Player, gridmap, command): #Defines the final room, available only upon getting all 3 keys.

    x, y = Player.Current_Position
    room = gridmap[x][y]

    #Alternate ending
    if command.strip().lower() in ['ponder', 'admire', 'behold', 'look', 'stare', 'inspect']:
        print("You are drawn to the aura. You spend the rest of your life staring down the enigmatic corridor.")
        print("You got the mysterious door ending.")
        win_condition()

    #Checks for all keys in player inventory before allowing further interaction
    if all(key in Player.Inventory for key in ['Key #1', 'Key #2', 'Key #3']):
        if command.strip().lower() in ['door', 'unlock', 'unlock door', 'use door', 'key', 'keys', 'use key', 'use keys']:
            print ("You use the keys you've collected so far.")
            win_condition()

    room_info(Player, gridmap)

def encounter_room(Player, gridmap, command): #Defines behavior for random mob encounters.

    x, y = Player.Current_Position
    room = gridmap[x][y]
    global trivia_solved

    if not room["Encounter"]:
        print("The room is now quiet.")
        return

    if room["Encounter"]:
        mob = room["Encounter"][0]
        if isinstance(mob, list):
            mob = mob[0]

    if mob == "Ghost":
        if command.strip().lower() in ['run', 'dodge', 'avoid', 'escape', 'run away'] and "Potion" in Player.Inventory:
            Player.Inventory.remove('Potion')
            print("You have escaped from the Ghost, but it has taken something from you...")
        else:
            Player.player_take_damage(r.randint(5, 8))
            set_room_desc(gridmap, x, y, "You have had a haunting encounter, but the ghost is nowhere to be found.")

    elif mob == "Orc":
        Player.player_take_damage(r.randint(5, 8))
        set_room_desc(gridmap, x, y, "The orc had bigger fish to fry.")

    elif mob == "Slime":
        if command.strip().lower() in ['run', 'dodge', 'avoid', 'escape', 'run away'] and "Teleportation Scroll" in Player.Inventory:
            Player.Inventory.remove('Teleportation Scroll')
            print("You have escaped the slime, but it has stolen a scroll and will soon cause mischief.")
            set_room_desc(gridmap, x, y, "You have no idea where the slime is, and that worries you.")
        else:
            Player.player_take_damage(r.randint(5, 8))
            set_room_desc(gridmap, x, y, "The slime has sauntered off, but you still feel sticky.")

    elif mob == "Treasure Hunter":
        prob_msg = r.randint(1, 2)
        if command in ['hi', 'talk', 'hunter', 'treasure hunter', 'interact', 'speak']:
            if prob_msg == 1:
                print('"I have heard of a great threat locked away at (0, 0). But I have not been able to get in there."')
            elif prob_msg == 2:
                print('"I have heard of a great treasure locked away at (0, 2)."')

    elif mob == "Seer":
        if trivia_solved == True:
            print("He mutters nonsense to himself before wandering off.")

        else:
            hint_pool = r.randint(1, 3)
            if hint_pool == 1:
                print('The seer says:')
                print('"Feels like two hundred degrees in here."')

            elif hint_pool == 2:
                print('The seer says:')
                print('"Plural means Many."')

            else:
                print('The seer says:')
                print('"At least I still have both hands."')

    room["Encounter"].clear()
    print("The entity you encountered has wandered off.")
    room_info(Player, gridmap)


def interactable_room(Player, gridmap, command): #Defines behavior for random interactables.

    x, y = Player.Current_Position
    room = gridmap[x][y]

    if room["Interactables"] and isinstance(room["Interactables"][0], list):
        room["Interactables"][0] = room["Interactables"][0][0]

    if not room["Interactables"]:
        print("The room is now barren.")
        return

    int_obj = room["Interactables"][0]

    if room["Interactables"]:

        if int_obj == "Mimic":
            if command.strip().lower() in ['avoid', 'ignore', 'dodge', 'run', 'walk away', 'run away']:
                print("The Mimic contemplates his life choices and walks off.")
                set_room_desc(gridmap, x, y, "You made the Mimic have an existential crisis.")

            elif command.strip().lower() in ['mimic', 'open', 'interact', 'inspect', 'open', 'open mimic', 'attack', 'hit', 'kill', 'damage'] and "Potion" in Player.Inventory:
                Player.Inventory.remove("Potion")
                print("The Mimic took a bite out of your ass, causing you to drop a potion.")
                Player.player_take_damage(r.randint(5, 8))
                set_room_desc(gridmap, x, y, "The Mimic found someone else to munch on.")

            elif command.strip().lower() in ['mimic', 'open', 'interact', 'inspect', 'open', 'open mimic', 'attack', 'hit', 'kill', 'damage'] and "Teleportation Scroll" in Player.Inventory:
                Player.Inventory.remove("Teleportation Scroll")
                print("The Mimic took a bite out of your ass, causing you to drop a scroll.")
                Player.player_take_damage(r.randint(5, 8))
                set_room_desc(gridmap, x, y, "The Mimic found someone else to munch on.")

            else:
                Player.player_take_damage(r.randint(5, 8))
                print("The mimic took a bite out of your ass as you round the corner. Chomp.")

            room["Interactables"].clear()

        elif int_obj == "Swinging Axes":
            if command.strip().lower() in ['dodge', 'avoid', 'axes', 'swinging axes', 'axe', 'wait', 'ignore', 'interact']:
                print("You successfully avoid getting swiss cheese'd.")
                set_room_desc(gridmap, x, y, "The axes swung and missed.")

            else:
                Player.player_take_damage(r.randint(5, 8))
                set_room_desc(gridmap, x, y, "The swinging axes miss your company.")
            room["Interactables"].clear()

        elif int_obj == "Bear Trap":
            if command.strip().lower() in ['disarm', 'avoid', 'wait', 'ignore', 'bear trap', 'trap']:
                print("The bear trap snaps shut upon catching a skittering rodent. You were lucky to avoid it.")
                set_room_desc(gridmap, x, y, "The bear trap has closed shut and is now harmless.")

            else:
                Player.player_take_damage(r.randint(10, 13))
                set_room_desc(gridmap, x, y, "The bear trap got your ass; lmao.")
            room["Interactables"].clear()

        elif int_obj == "Mirror":
            if command.strip().lower() in ['mirror', 'look', 'inspect', 'look in mirror', 'inspect mirror']:
                if "Potion" in Player.Inventory:
                    print("The mirror takes a good, long look into your inventory and leaves a gift.")
                    Player.Inventory.append("Potion")
                elif "Teleportation Scroll" in Player.Inventory:
                    print("The mirror takes a good, long look into your inventory and leaves a gift.")
                    Player.Inventory.append("Teleportation Scroll")
                print('As you gaze into the mirror, the mirror gazes right back.')
            room["Interactables"].clear()

        elif int_obj == "Sofa":

            #Alternate ending
            sofa_ending = r.randint(1, 6)
            if command.strip().lower() in ['sofa', 'sit', 'sit on sofa',] and sofa_ending == 1:
                print("You sink into the sofa and sleep until the heat death of the universe.")
                print("You got the sofa ending!")
                win_condition()
            elif command.strip().lower() in ['sofa', 'sit', 'sit on sofa',] and sofa_ending != 1:
                print("You sofa the sofa. Very sofa. You sofa the sofa so sofa that the sofa runs away to sofa alone.")
            room["Interactables"].clear()

        elif int_obj == "Chest":
            if command.strip().lower() in ['chest', 'open', 'open chest']:
                print("You open the chest, only to find that it is a prop. You kick it down the stairs out of frustration and disappointment.")
            room["Interactables"].clear()

    room_info(Player, gridmap)

def item_room(Player, gridmap, command): #Defines behavior for rooms with random consumables.

    x, y, = Player.Current_Position
    room = gridmap[x][y]

    if "Potion" in room["Items"]:
        if command.strip().lower() in ['take potion', 'pick up', 'pick up potion', 'take']:
            print("You take the potion.")
            Player.Inventory.append("Potion")
            remove_room_item(gridmap, x, y, "Potion")

    elif "Teleportation Scroll" in room["Items"]:
        if command.strip().lower() in ['take teleportation scroll', 'pick up', 'pick up teleportation scroll', 'take', 'scroll', 'teleportation scroll']:
            Player.Inventory.append("Teleportation Scroll")
            remove_room_item(gridmap, x, y, "Teleportation Scroll")

    room_info(Player, gridmap)

def consume_potion(Player, command): #Handles consumption of the potion.

    if "Potion" in Player.Inventory:

        Player.Health += 6
        if Player.Health > 20:
            Player.Health = 20
        Player.Inventory.remove("Potion")
        print("You drank the sussy among us potion at 3 AM and restored 6 Health.")
        print(f'You currently have {Player.Health} Health.')

    else: #flavor text if using a nonexistent potion
        prob_err_msg = r.randint(1, 5)
        if prob_err_msg == 1:
            print("You don't have any potions.")

        elif prob_err_msg == 2:
            print("You have a crippling and severe lack of bitches and potions.")

        elif prob_err_msg == 3:
            print("Error 404: potion not found.")

        elif prob_err_msg == 4:
            print("There is a time and a potion for everything. But not now.")

        elif prob_err_msg == 5:
            print("You scared all the potions away.")

def consume_tpscroll(Player, gridmap, command): #Handles consumption of the scroll.

    x, y = Player.Current_Position
    room = gridmap[x][y]

    if "Teleportation Scroll" in Player.Inventory:
        locations = r.randint(1, 4)

        if locations == 1:
            Player.Inventory.remove("Teleportation Scroll")
            Player.Current_Position = (2, 4)
            print("Space bends around you as you eat the scroll. You sense an important item must be nearby.")

        elif locations == 2:
            Player.Inventory.remove("Teleportation Scroll")
            Player.Current_Position = (4, 2)
            print("Space bends around you as you eat the scroll. You sense an important item must be nearby.")

        elif locations == 3:
            Player.Inventory.remove("Teleportation Scroll")
            Player.Current_Position = (0, 2)
            print("Space bends around you as you eat the scroll. You sense an important item must be nearby.")

        #Secret boss. 25% chance to tp to boss room, which is only accessible via scroll. Enables the room to be valid.
        elif locations == 4:
            Player.Inventory.remove("Teleportation Scroll")
            gridmap[0][0]["Valid"] = True
            Player.Current_Position = (0, 0)
            print('The Fallen Monarch stands up from his throne and announces, "So, the pest has finally found a way out of its cage."')
            print("You teleported and found the secret boss! Type 'attack' to do damage!")


    else: #flavor text if using a nonexistent scroll
        prob_err_msg = r.randint(1, 5)
        if prob_err_msg == 1:
            print("You don't have any scrolls.")

        if prob_err_msg == 2:
            print("They all scrolled away.")

        if prob_err_msg == 3:
            print("No scrolls here.")

        if prob_err_msg == 4:
            print("You cannot teleport without a scroll.")

        if prob_err_msg == 5:
            print("If you are reading this, pick up a scroll first.")


def secret_boss_room(Player, gridmap, command):

    boss_text = r.randint(1, 5)
    if Player.BossHp is None:
        Player.BossHp = 15
        Player.BossState = True

    if command in ['attack', 'hit', 'damage', 'boss', 'monarch', 'kill']:

        Player.BossHp -= 5
        print("You did 5 damage! The Fallen Monarch now has " + str(Player.BossHp) + " health.")

        if boss_text == 1:
            print('The Fallen Monarch: "I will show you how I deal with trespassers."')

        elif boss_text == 2:
            print('The Fallen Monarch: "Surrender and I will grant you a swift death."')

        elif boss_text == 3:
            print('The Fallen Monarch: "Kneel."')

        elif boss_text == 4:
            print('The Fallen Monarch: "None of your friends will make it out of that dungeon alive."')

        elif boss_text == 5:
            print('The Fallen Monarch: "I have watched you loop over and over. You cannot defeat me."')

        if Player.BossHp == 0:
            print("You have defeated The Monarch, freeing everyone.")
            print("You have achieved the true ending of the game!")
            Player.BossState = False
            Player.BossHp = None
            print("Congratulations! You have completed the adventure for good!")
            sys.exit()

        Player.player_take_damage(8)

    elif command in ['surrender', 'concede', 'give up']:
        print('The Fallen Monarch: "I see you are still wise enough to serve me. Very well. I will make use of you, even in this shattered form."')
        print('You have achieved the corruption ending and worked with the Fallen Monarch to enslave the denizens of the dungeon.')
        print("Unfortunately, you have finished the adventure.")
        sys.exit()

    else:
        pass


#Defining the rooms individually and assigning appropriate lists, including functions.
gridmap[0][0]["Valid"] = False
gridmap[0][0]["Action"] = secret_boss_room
gridmap[0][1]["Encounter"].append(r.choices(encounter_list, k=1))
gridmap[0][1]["Action"] = encounter_room
gridmap[0][2]["Description"].append("You spot a trap door on the floor. You could explore further down if you had a ladder.")
gridmap[0][2]["Action"] = key_3_room
gridmap[0][3]["Interactables"].append(r.choices(interactable_list, k=1))
gridmap[0][3]["Action"] = interactable_room
gridmap[0][4]["Description"].append("A strange aura comes from that direction. Perhaps you should come back later.")
gridmap[0][4]["Action"] = final_room
gridmap[1][0]["Items"].append("Aged Wooden Staff x1")
gridmap[1][0]["Description"].append("You see a wild oil rig.")
gridmap[1][0]["Action"] = gift_item_room
gridmap[1][1]["Items"].append(r.choice(cons_list))
gridmap[1][1]["Action"] = item_room
gridmap[1][2]["Valid"] = False
gridmap[1][3]["Encounter"].append(r.choices(encounter_list, k=1))
gridmap[1][3]["Action"] = encounter_room
gridmap[1][4]["Valid"] = False
gridmap[2][0]["Items"].append(r.choice(cons_list))
gridmap[2][0]["Action"] = item_room
gridmap[2][1]["Interactables"].append(r.choices(interactable_list, k=1))
gridmap[2][1]["Action"] = interactable_room
gridmap[2][2]["Items"].append("Torch x1")
gridmap[2][2]["Description"].append("The spawn room. You can go North, East, or South. Check your Health, Inventory, and Coordinates by typing 'info'. You can interact with most entities by typing their name.")
gridmap[2][2]["Action"] = spawn_room
gridmap[2][3]["Description"].append("You see a strange altar and a robed man. He seems to be looking for something.")
gridmap[2][3]["Action"] = healer_npc_room #Revisit; needs fixing.
gridmap[2][4]["Description"].append("There is a sealed compartment. Who knows how to open it?")
gridmap[2][4]["Action"] = key_1_room
gridmap[3][0]["Valid"] = False
gridmap[3][1]["Interactables"].append(r.choices(trap_list, k=1))
gridmap[3][1]["Action"] = interactable_room
gridmap[3][2]["Encounter"].append(r.choices(encounter_list, k=1))
gridmap[3][2]["Action"] = encounter_room
gridmap[3][3]["Valid"] = False
gridmap[3][4]["Description"].append("Text illuminates on the wall, asking: (You must squint and read closely).")
gridmap[3][4]["Action"] = trivia_room
gridmap[4][0]["Items"].append("Ladder x1")
gridmap[4][0]["Action"] = ladder_room
gridmap[4][1]["Interactables"].append(r.choices(interactable_list, k=1))
gridmap[4][1]["Action"] = interactable_room
gridmap[4][2]["Description"].append("It's very dark.")
gridmap[4][2]["Action"] = key_2_room
gridmap[4][3]["Items"].append("Teleportation Scroll")
gridmap[4][3]["Action"] = item_room
gridmap[4][4]["Valid"] = False


class player_char: #Player class; must dynamically track player info.
    def __init__(self, Start_Position, Health, Inventory=None, Current_Position=(2, 2)):

        if Inventory is None:
            Inventory = []
        self.Start_Position = Start_Position
        self.Health = Health
        self.Inventory = Inventory
        self.Current_Position = Current_Position
        self.BossState = False
        self.BossHp = None

    def player_take_damage(self, Damage): #Basic damage function.
        self.Health -= Damage
        print(f'You have taken {Damage} damage.') #Revisit; only does (20 - current health.)
        fail_condition()

    def player_info(self): #Method to be called when player wants to see their info. Command function set up below.
        print(f'{self.Health} Health, {self.Inventory}, {self.Current_Position}')

#Player movement system based on input; Revisit.
def player_movement(Player, direction, gridmap):

    x, y = Player.Current_Position
    new_x, new_y = x, y

    #Directional inputs; map exists in (x, -y) plane.
    if direction.lower() == "north":
        new_y -= 1
    elif direction.lower() == "south":
        new_y += 1
    elif direction.lower() == "east":
        new_x += 1
    elif direction.lower() == "west":
        new_x -= 1

    #Defining map bounds. Coordinate cannot be below 0 or greater than 4 (lengridmap) in any direction.
    if not (0 <= new_x < len(gridmap) and 0 <= new_y < len(gridmap[0])):
        print("Invalid direction; That is out of bounds.")
        return

    #Handling invalid rooms. These are inaccessible no matter what to act as an obstacle.
    if not gridmap[new_x][new_y]["Valid"]:
        print("The way is blocked.")
        return

    #Actual movement part of the function.
    Player.Current_Position = (new_x, new_y)
    print(f"You moved {direction}.")
    room_info(Player, gridmap)


def room_info(Player, gridmap): #Mostly used to update room Descriptions dynamically.

    x, y = Player.Current_Position
    room = gridmap[x][y]

    if room["Description"]:
        print(''.join(room["Description"]))

    if room["Items"]:
        print(f'You see {room["Items"]}.')

    if room["Interactables"]:
        print(f'You see {room["Interactables"]}.')

    if room["Encounter"]:
        print(f'You encounter a {room["Encounter"]}.')


Player = player_char(Start_Position=(2, 2), Health=20) #Defines the player.
room_info(Player, gridmap)

#Main Text Loop Gameplay
while True:
    command = input("Where would you like to go? (north, south, east, west): ").strip().lower()

    if command.strip().lower() in ['quit', 'exit']: #Checks if the player wants to stop playing.
        print("Thank you for playing.")
        sys.exit()

    elif command.strip().lower() in ['north', 'south', 'east', 'west']: #Checks for movement inputs and calls the corresponding function with parameters.
        if Player.Current_Position == (0, 0): #Locks movement in boss fight.
            pass
        else:
            player_movement(Player, command, gridmap)

    elif command.strip().lower() in ['info', 'information', 'inventory', 'health', 'stats']: #Checks for player checking their info.
        Player.player_info()

    elif command.strip().lower() in ['potion', 'drink potion', 'use potion']: #Checks for player using an item; calls corresponding function.
        consume_potion(Player, command)
    elif command.strip().lower() in ['use scroll', 'use teleportation scroll', 'scroll', 'teleport', 'tp', 'use tp']:
        if Player.Current_Position == (0, 0): #Locks movement in boss fight.
            pass
        else:
            consume_tpscroll(Player, gridmap, command)

    elif command.strip().lower() in ['shit', 'fart', 'poop']: #What does this button do?
        if Player.Current_Position == (0, 0):
            print("You shit your pants in front of the Monarch. He laughs his ass off.")
            print("You found the humiliation ending.")
            win_condition()
        else:
            print("You shit your pants. Smelly.")
            print("You got the poop ending!")
            win_condition()

    else: #Checks for player interaction within corresponding rooms. While not used directly, it is needed for assigned gridmap functions to work.
        x, y = Player.Current_Position
        room = gridmap[x][y]
        if room["Action"]:
            room["Action"](Player, gridmap, command) #TF2 Coconut.jpg. Do not remove.

