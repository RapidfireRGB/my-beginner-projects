#Random loot generator
import random

materials = ['Iron', 'Copper', 'Steel', 'Titanium']
items = ['Sword', 'Dagger', 'Bow', 'Tome']
loot_pool = [] #Empty list to be appended in the loop.

#Nested For loop to generate a list of ordered pairs ('Iron' and 'Sword' becomes 'Iron Sword' etc)
for material in materials:
    for item in items:
        loot_pool.append(f'{material} {item}') 

#Defining the weights for random.choices; a rate multiplier for list items at specific index positions.
drop_rate = [4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1]

#The randomly generated item.
random_loot = random.choices(loot_pool, weights = drop_rate, k=1)[0] 

print(f"You found {random_loot} x1!")

if random.randint(1, 5) == 5: #20% chance for a bonus item.

    #Copies the list and weights to eliminate "duplicates" from the list.
    new_lootpool = loot_pool.copy() 
    new_weights = drop_rate.copy()

    #Eliminates the random_loot item from the list.
    elim_loot = new_lootpool.index(random_loot) 
    new_lootpool.pop(elim_loot)
    new_weights.pop(elim_loot)

    #Generates the bonus item.
    bonus_loot = random.choices(new_lootpool, weights = new_weights, k=1)[0] 
    print(f"You also found {bonus_loot} x1!") 

    #Prints some flavor text if you get a Titanium item.
    if 'random_loot' in locals() and 'Titanium' in random_loot: 
        print('Congratulations, you got a Rare Item!')
    elif 'bonus_loot' in locals() and 'Titanium' in bonus_loot:
        print('Congratulations, you got a Rare Item!')
        
#To DO: Make the code look nice!!!
