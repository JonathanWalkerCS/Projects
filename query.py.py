#! python3
import pyperclip

option = 0

while option != 6:
    print('SQL example queries'.center(20, '='))
    print('Please select an option.')
    print('Option 1: Check if IdNum is 1115')
    print('Option 2: Check if two employees have salary greater than $2000')
    print('Option 3: Find the average salary')
    print('Option 4: Find the lowest salary')
    print('Option 5: Find the total amount paid')
    print('Option 6: Exit')
    print('='.center(20, '='))

    print('Your selection: Option ', end='')
    option = int(input())

    if option == 1:  # Copy first text
        text = "SELECT employees.IdNum, employees.LName, employees.FName FROM employees WHERE employees.IdNum = 1115;"
        pyperclip.copy(text)
        print(f"Text copied: {text}\n")
    elif option == 2:  # Copy second text
        text = "SELECT employees.Salary, employees.LName, employees.FName FROM employees WHERE employees.Salary > '40000';"
        pyperclip.copy(text)
        print(f"Text copied: {text}\n")
    elif option == 3:  # Copy third text
        text = "SELECT AVG(employees.Salary) as Average_salary FROM employees;"
        pyperclip.copy(text)
        print(f"Text copied: {text}\n")
    elif option == 4:  # Copy fourth text
        text = "SELECT MIN(employees.Salary) as Lowest_salary FROM employees;"
        pyperclip.copy(text)
        print(f"Text copied: {text}\n")
    elif option == 5:  # Copy fifth text
        text = "SELECT SUM(employees.Salary) as Total_Company_Pay FROM employees"
        pyperclip.copy(text)
        print(f"Text copied: {text}\n")
    elif option == 6:  # Exit
        print('Thank you and have a great day.')
    else:
        print('Invalid Input!\n')
