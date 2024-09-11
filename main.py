import sys ; sys.dont_write_bytecode = True
from colorama import Fore , init ; init()
from os import getcwd , system , name
import linecache
import ctypes
import banner
#=========================================================================================
if name == "nt":
    system("cls")
else:
    system("clear")
#=========================================================================================
path = getcwd()
test = ctypes.CDLL(f"{path}/data_base")
#=========================================================================================
RESET = (Fore.RESET) 
#=========================================================================================
# Banner
banner.banner()
#=========================================================================================  
try:
    ask = input(f"{Fore.MAGENTA}Want to find User or create {Fore.GREEN}(F/C): " + RESET)
except KeyboardInterrupt:
    exit(f"""\n{Fore.YELLOW}│
╰┈➤{Fore.RED}[-]{Fore.BLUE} User Exited :)""")

if ask == "c" or ask == "C":
    test.main()

#=========================================================================================
elif ask == "f" or ask == "F":
    
    try:
        file = open("User.txt" , "r")
    except FileNotFoundError:
        exit(Fore.RED + "you didnt create any users !".title() + RESET)

#=========================================================================================
    U_name = input(Fore.MAGENTA + "\nEnter username : ".title() + RESET)
    
    if U_name == "\n" or U_name == "":
        exit(Fore.RED + "Username cant be empty !" + RESET)
    else:
        pass
#=========================================================================================
    r_file = file.read()
#=========================================================================================
    if f"Username : {U_name}" in r_file:
        print(Fore.GREEN + "\nUser found" + RESET)


        with open("User.txt") as myFile:
            for num, line in enumerate(myFile, 1):
                if U_name in line:
                    user_line = num  # user_num has the line
    
    else:
        exit(Fore.RED + "\nuser not found".title() + RESET)


    pwd = input(Fore.MAGENTA + "\nEnter User password : ".title() + RESET)
    if pwd == "\n" or pwd == "":
        exit(Fore.RED + "password cant be empty !" + RESET)
    else:
        pass

    if f"Password : {pwd}" in r_file:
        print(Fore.GREEN + "\nlogin succes".title() + RESET)
        pass
    else:
        exit(Fore.RED + "\nlogin failure".title() + RESET)

#=========================================================================================

    #Banner here 'user panel'

    print(f"""\n\n{Fore.RED}[{Fore.GREEN}1{Fore.RED}] {Fore.LIGHTWHITE_EX}Edit user info  {Fore.RED}[{Fore.GREEN}2{Fore.RED}]{Fore.LIGHTWHITE_EX} Remove user

{Fore.RED}[{Fore.GREEN}3{Fore.RED}] {Fore.LIGHTWHITE_EX}Improve rank  {Fore.RED}[{Fore.GREEN}4{Fore.RED}] {Fore.LIGHTWHITE_EX}Improve rating

{Fore.RED}[{Fore.GREEN}0{Fore.RED}] {Fore.LIGHTWHITE_EX}Exit 
""")
    
    try:
        choose = int(input(Fore.MAGENTA + "\nWhat do you want to do : " + RESET))
    except KeyboardInterrupt:
        exit(f"""\n{Fore.YELLOW}│
╰┈➤{Fore.RED}[-]{Fore.BLUE} User Exited :)""")
    
    match(choose):
        case 1:
            pass
        case 2:
            print("working...")
        case 3:
            pass
        case 4:
            pass
        case 0 :
            exit(f"""{Fore.YELLOW}│
╰┈➤{Fore.RED}[-]{Fore.BLUE} User Exited :)""")
        case _:
            exit(Fore.RED + "No such option !".title() + RESET)
#=========================================================================================
    file.close()