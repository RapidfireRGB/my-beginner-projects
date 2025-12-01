import random as r

def main():

    num_skills = 3

    challenges = ["Ironman", "No Fast Travel", "Permadeath", "One HP",
                  "Complete the Goal in Under 1 Hour", "Pacifist"]

    modifiers = ["Cannot Level Up", "Cannot Craft", "No Essential NPCs", "No Followers", "No Sleeping",
                 "No Crime", "For Magic, Only Use Spells From Apocalypse Magic", "Must use Survival Mode"]

    goals = ["Reach the Peak of the Throat of the World", "Defeat Alduin", "Own Property in Every Hold",
             "Discover Each Standing Stone", "Reach 100 in a Skill Naturally", "Befriend 10 NPCs",
             "Defeat 5 Master Vampires and 1 Werewolf", "Get a Bounty of 1000+ in Every Hold"]

    races = ["Argonian", "Dark Elf", "Nord", "High Elf", "Wood Elf", "Breton", "Imperial", "Redguard",
             "Khajiit"]

    skills = ["Alteration", "Alchemy", "Destruction", "Enchanting", "Restoration", "Conjuration",
              "One-Handed", "Two-Handed", "Block", "Smithing", "Archery", "Speech", "Lockpicking",
              "Pickpocket", "Illusion", "Sneak", "Light Armor", "Heavy Armor"]

    attributes = ["Health", "Magicka", "Stamina"]

    difficulties = ["Adept", "Expert", "Master", "Legendary"]

    locations = ["Riverwood", "Darkwater Crossing", "Kynesgrove", "High Hrothgar",
                 "Whiterun", "Morthal", "Winterhold", "Markarth", "Solitude", "Riften", "Windhelm",
                 "Falkreath", "Dawnstar", "Stonehills", "Labyrinthian", "Anise's Cabin", "Rorikstead",
                 "Sleeping Tree Camp", "Frostflow Lighthouse", "High Gate Ruins", "Hall of the Vigilant",
                 "Statue to Meridia", "Volskygge", "Valthume", "Thalmor Embassy", "The Serpent Stone",
                 "Yngvild", "Raven Rock", "Skaal Village", "Lost Tongue Overlook", "Thirsk Mead Hall",
                 "Castle Karstaag", "Fort Amol", "Cracked Tusk Keep"]

    print(f'Challenge: {r.choice(challenges)}\n'
          f'Modifier: {r.choice(modifiers)}\n'
          f'Goal: {r.choice(goals)}\n'
          f'Difficulty: {r.choice(difficulties)}\n'
          f'Race: {r.choice(races)}\n'
          f'Start Location: {r.choice(locations)}\n'
          f'Skills: {r.choices(skills, k=num_skills)}')

    #print(f'Attributes: {attributes}')

main()
