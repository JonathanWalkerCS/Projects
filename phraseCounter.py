import pprint

def soloCounter():
    print('\nPlease enter a phrase: ')
    phrase = input()
    daList = {}

    for word in phrase.upper():
        daList.setdefault(word,0)
        daList[word] = daList[word] + 1

    print('\nHere is the breakdown of characters in the phrase: ' + str(phrase))
    pprint.pprint(daList)


def fullCounter():
    print('\nPlease enter a phrase: ')
    fullPhrase = str(input())
    print('\nThe total number of characters in your phrase is: ' + str(len(fullPhrase)))


    
    
option = 0
while option != 3:
    print()
    print('Choose from the following options:')
    print('Option 1: Find the characters in a phrase')
    print('Option 2: Find the total number of characters in a phrase')
    print('Option 3: Exit')
    print('Your Selection: ', end="")
    option = int(input())

    if option == 1:
        soloCounter()
    elif option == 2:
        fullCounter()
    elif option == 3:
        print('\nThank you have a nice day')
    else:
        print('\nThat was not a valid option')
    







