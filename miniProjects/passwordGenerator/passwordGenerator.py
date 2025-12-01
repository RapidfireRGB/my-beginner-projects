import random

# Defining list variables; used as password criteria later.
alph_lowerc = list('qwertyuiopasdfghjklzxcvbnm')
alph_upperc = [char.upper() for char in alph_lowerc] # uppercases above list. Enclosed in brackets to exist as a list itself.
num = list('0123456789')
spec_chars = list('!@#$%&~_=+`-')
odd_chars = [' ', '\\', '"', "'", ';', ':', '^', '*', '?', '{', '}', '[', ']', '(', ')', '|', ',', '.', '/']

# Function asks for password length and other criteria via console output text.
def user_prompts():

    alph_lowerc_allowed = True
    user_pass_length = int(input('Specify Password Length (4-24).'))

    # Password length validation
    try:
        if user_pass_length < 4 or user_pass_length > 24:
            print('Invalid Password Length. Try again.')
            user_prompts()
        else:
            pass
    except TypeError:
        print('Invalid data type for Password Length. Try again.')
        user_prompts()

    num_only = str(input('Do you want to generate a PIN? (y/n, activates numbers-only mode.)'))

    # Sets input prompts to 'n' prematurely, cancelling below prompts if condition is met.
    if num_only == 'y' or num_only == 'yes':
        alph_upperc_allowed = num_allowed = spec_chars_allowed = odd_chars_allowed = 'n'

    else:
        alph_upperc_allowed = str(input('Do You Want Uppercase Letters? (y/n)'))
        num_allowed = str(input('Do You Want Numbers? (y/n)'))
        spec_chars_allowed = str(input('Do You Want Special Characters? (y/n)'))
        odd_chars_allowed = str(input('Do You Want Odd Special Characters? (y/n)'))

    # Inner Function checks user-defined criteria and appends probable_list accordingly.
    def user_toggles():

        # Nonlocal to use outer function variable in below conditions.
        nonlocal alph_lowerc_allowed

        # Empty list to populate as below conditions are met (User criteria).
        probable_list = []
        
        if num_only == 'y' or num_only == 'yes':
            alph_lowerc_allowed = False
            probable_list += num
            
        if alph_lowerc_allowed:
            probable_list += alph_lowerc
            
        if alph_upperc_allowed == 'y' or alph_upperc_allowed == 'yes':
            probable_list += alph_upperc
            
        if num_allowed == 'y' or num_allowed == 'yes':
            probable_list += num
            
        if spec_chars_allowed == 'y' or spec_chars_allowed == 'yes':
            probable_list += spec_chars
            
        if odd_chars_allowed == 'y' or odd_chars_allowed == 'yes':
            probable_list += odd_chars

        # The randomizer; uses probable_list for population and user_pass_length for iteration count. No weights.
        password = random.choices(probable_list, k=user_pass_length)
        print(''.join(password)) 

# Calling the functions.
    user_toggles()
    
user_prompts()
