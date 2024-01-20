#Author: Karryl Dumalag
#Date: 10/05/22
#Description: Assignment 2 (Python). Mortgage calculator and Student record program.

#Part 1
def mortgageCalc():
    #Introduction to the program. Asks user for input..
    #I inserted triple \n here and there just to make things easier to read when the code is ran.
    print("\n\n\nWelcome to the Mortgage Payment Calculator! \nPlease Select an option:\n")
    print("(1) Compute Monthly Mortgage Payment")
    print("(2) Quit\n\n\n")
    
    mortgage_select = input("Option: ")

    #Enters if statement depending on what the user chose
    if mortgage_select == "1":
        #Inputs the necessary values needed for mortgage calculation into their desginated variables
        total_amount = float(input("Enter total amount you owe:"))
        interest_rate = float(input("Enter the interest rate (percent):"))
        monthly_interest_rate = interest_rate / 1200 #formats the percentage so that the calculation works (../12 for monthly, ../100 for percentage)
        months = float(input("Enter the number of months:"))

        #The calculation for the monthly mortgage
        monthly_mortgage = total_amount * ((monthly_interest_rate * pow(1 + monthly_interest_rate, months))/(pow(1 + monthly_interest_rate, months) - 1))
        #Formats the answer to end after two decimal places
        format_monthly_mortgage = "{:.2f}".format(monthly_mortgage)

        print("\nCalculated Monthly Mortgage Payment: " + str(format_monthly_mortgage) + " per month.\n")
        
        #Asks the user if they wish to try another calculation with different values
        mortgage_redo = input("Would you like to try again? (yes/no): \n\n")
        if mortgage_redo == "yes":
            mortgageCalc()
        elif mortgage_redo == "no":
            main()
        else:
            print("That wasn't an option, dude. You're exiting the program now.\n\n\n")
            main()
    elif mortgage_select == "2":
        main()
    else:
        print("ERROR: I know you saw that wasn't an option. Do it again.\n\n\n")
        mortgageCalc()





#Part 2
def studentRecord():
    #Introduce the user with their options
    print("\n\n\nWelcome to the Student Record Program! \nPlease select an option:\n")
    print("(1) Enter Student Name")
    print("(2) Enter Student ID")
    print("(3) Enter Class")
    print("(4) Remove a Student Name")
    print("(5) Remove a Student ID")
    print("(6) Remove a Class")
    print("(7) Display Student Names")
    print("(8) Display Student IDs")
    print("(9) Display Classes")
    print("(10) Quit Program")

    #Read user input to decide the next step
    record_select = input("Option: ")

    #Depending on user's choice, do the specified task
    if record_select == "1":
        new_student = input("Enter new student name: \n")
        students.append(new_student)
        students.sort() #For organization sake, sort the list alphabetically every time it is update
    elif record_select == "2":
        new_id = input("Enter new student student ID: \n")
        id.append(new_id)
        id.sort() #Sorts the ID to make things easier to find
    elif record_select == "3":
        new_class = input("Enter new class: \n")
        classes.append(new_class)
        classes.sort() #Sorts the classes
    elif record_select == "4":
        remove_student = input("Enter student to delete: \n")
        
        #Check to see if the name exists in the list to avoid error
        exist_student = students.count(remove_student)

        #If the input exists at least once, the code will prompt deletion. If not, user will be asked to redo their selection.
        if exist_student > 0:
            students.remove(remove_student)
            students.sort()
        else:
            print("The student does not exist.")
    elif record_select == "5":
        remove_id = input("Enter ID to delete: \n")

        #Check to see if the ID exists in the list to avoid error
        exist_id = id.count(remove_id)

        if exist_id > 0:
            id.remove(remove_id)
            id.sort()
        else:
            print("The ID does not exist.")
    elif record_select == "6":
        remove_class = input("Enter class to delete: \n")

        #Check to see if the class exists in the list to avoid error
        exist_class = id.count(remove_id)

        if exist_id > 0:
            classes.remove(remove_class)
            classes.sort()
        else:
            print("The class does not exist.")
    elif record_select == "7":
        print(students)
    elif record_select == "8":
        print(id)
    elif record_select == "9":
        print(classes)
    elif record_select == "10":
        main()

    #Function to determine whether or not user wishes to exit the program based on input
    def studentRecordRedo():
        do_again = input("\nWould you like to do something else? (yes/no): \n")
        if do_again == "yes":
            studentRecord()
        elif do_again == "no":
            main()
        else:
            print("You didn't enter correctly. Retry...")
            studentRecordRedo()

    #After task is completed, ask user if they wish to do something else 
    studentRecordRedo()

#Main body
def main():
    print("\n\n\nWelcome to my program! \n\nSelect what you'd like to do:")
    print("(1) Compute Monthly Mortgage Payment")
    print("(2) Organize Student Records\n")
    intro_select = input("Option: ")

    if intro_select == "1":
        mortgageCalc()
    elif intro_select == "2":
        studentRecord()
    else:
        print("Not an option. Retry.")
        main()

#Initialize the studentRecord lists outside of the function so it stays updated
students = []
id = []
classes = []

#Begins the script. Calls the main body so the user can enter their needed program
main()
        