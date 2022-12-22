import random
# from random randint

class Game:
   def __init__(self, num_tries):
        self.tries = num_tries
        self.win = False
   def menu(self):
        print('Welcome to the game of GUESS THE NUMBER')
        print('Select one of the following options')
        print('    1. Player guess the number')
        print('    2. CPU guesses the number')
        print('    3. Exit')
        print('         Enter the number of the option: ', end='')
        option = self.get_number(1, 3)
        while option < 1 or option > 3:
            option = self.get_number(1, 3)
        return option

    def get_number(self, v_min:int, v_max:int):
        value = int(input())
        while value < v_min or value > v_max:
            print('Incorrect... Try again you dumb motherfucker')
            value = int(input())
        return value

    def get_random(self, minimum, maximum):
        num = random.randint(minimum,maximum + 1)
        return num

    def run(self):
        while True:
            player = self.menu()
            if player == 1:
                cpu_num = self.get_random(1, 100)
                while self.tries > 0:
                    print('What is the number I am thinking of? (1-100): ', end='')
                    value = self.get_number(1, 100)
                    if value == cpu_num:
                        self.win = True
                        self.tries = 0
                    else:
                        if value < cpu_num:
                            print('CPU says: The number is grater than {}'.format(value))
                        elif value > cpu_num:
                            print(f'CPU says: The number is lower than {value}')
                        self.tries -= 1
                    if self.win is True:
                        print('\nCongratulations, lucky bastard')
                    else:
                        print('\nYou have lost, so sorry')
            if player == 2:
                print('What is the number you want the CPU to guess? (1-100)', end='')
                value = self.get_number(1,100)
                lower_limit = 1
                upper_limit = 100
                while self.tries > 0:
                    value_cpu = self.get_random(lower_limit, upper_limit)
                    print(f'CPU says: The number chosen is {value_cpu}')
                    if value == value_cpu:
                        self.win = True
                        self.tries = 0
                    else:
                        if value < value_cpu:
                            print('The number is grater than {}'.format(value_cpu))
                            upper_limit = value_cpu
                        elif value > value_cpu:
                            print(f'The number is lower than {value_cpu}')
                            lower_limit = value_cpu
                        self.tries -= 1
                    if self.win is True:
                        print('\nCongratulations CPU, lucky bastard')
                    else:
                        print('\nYou have lost CPU, so sorry')
            if player == 3:
                break
            self.tries = 0
