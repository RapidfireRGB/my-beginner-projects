#Random loot generator
import random

materials = ['Iron', 'Copper', 'Steel', 'Titanium']
items = ['Sword', 'Dagger', 'Bow', 'Tome']
loot_pool = [] #Empty list to append in the loop.

for material in materials:
    for item in items:
        loot_pool.append(f'{material} {item}') #Nested For loop to generate a list of ordered pairs (Iron Sword, Iron Dagger, etc)

drop_rate = [4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1] #The weights for random.choices; a drop rate multiplier for corresponding list items.
random_loot = random.choices(loot_pool, weights = drop_rate, k=1)[0] #The randomly generated item.

print(f"You found {random_loot} x1!")

if random.randint(1, 5) == 5: #20% chance for a bonus item.

    new_lootpool = loot_pool.copy() #Copies the list and weights to eliminate "duplicates" from the list.
    new_weights = drop_rate.copy()
    
    elim_loot = new_lootpool.index(random_loot) #Eliminates the random_loot item from the list.
    new_lootpool.pop(elim_loot)
    new_weights.pop(elim_loot)
    
    bonus_loot = random.choices(new_lootpool, weights = new_weights, k=1)[0] #Generates the bonus item.
    print(f"You also found {bonus_loot} x1!") 
    
    if 'random_loot' in locals() and 'Titanium' in random_loot: #Prints some flavor text if you get Titanium.
        print('Congratulations, you got a Rare Item!')
    elif 'bonus_loot' in locals() and 'Titanium' in bonus_loot:
        print('Congratulations, you got a Rare Item!')
        
#To DO: Make the code look nice!!!