import mysql.connector

# Execute:
# python3 PhaseInsurance.py

#View Menu option 1
def viewplan():
   vpoption = 0;
   print("")
   print("Choose which plan information you want to view:") 
   print("1. Home Insurance") 
   print("2. Auto Insurance") 
   print("3. Health Insurance") 
   print("4. Life Insurance") 
   vpoption = int(input("Choice: "))
   print (vpoption)
   if vpoption == 1:
    ssn = input("Enter their SSN: ")
    mycursor = mydb.cursor()
    sql = "select HomePolicyID, PolicyStatus, CoverageLevel, ExpirationDate, PropertiesInsured from HomeInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print(x)
       return;
   elif vpoption == 2:
    ssn = input("Enter their SSN: ")
    mycursor = mydb.cursor()
    sql = "select AutoPolicyID, PolicyStatus, CoverageLevel, ExpirationDate, VehiclesInsured from AutoInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print(x)		
       return;
   elif vpoption == 3:
    ssn = input("Enter their SSN: ")
    mycursor = mydb.cursor()
    sql = "select HealthPolicyID, PolicyStatus, CoverageLevel, ExpirationDate from HealthInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print(x)
       return;
   elif vpoption == 4:
    ssn = input("Enter their SSN: ")
    mycursor = mydb.cursor()
    sql = "select LifePolicyID, PolicyStatus, CoverageLevel, ExpirationDate from LifeInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print(x)
       return;


#View Menu option 2
def viewclientinfo():
    id = input("Enter their Social Security Number: ")
    mycursor = mydb.cursor()
    sql = "SELECT * FROM ClientInfo WHERE SSN = %s"
    arg = (id, )
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print(x)
    return;




#View Menu option 3
def viewactive():
   vpoption = 0;
   print("")
   print("Choose which plan you want to view the status of:") 
   print("1. Home Insurance") 
   print("2. Auto Insurance") 
   print("3. Health Insurance") 
   print("4. Life Insurance") 
   vpoption = int(input("Choice: "))
   print (vpoption)
   if vpoption == 1:
    ssn = input("Enter their SSN: ")
    mycursor = mydb.cursor()
    sql = "select LastName, FirstName, PolicyStatus as HomeInsuranceStatus from ClientInfo natural join HomeInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print("Home Insurance for:")			
       print(x)
       return;
   elif vpoption == 2:
    ssn = input("Enter their SSN: ")
    mycursor = mydb.cursor()
    sql = "select LastName, FirstName, PolicyStatus as AutoInsuranceStatus from ClientInfo natural join AutoInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print("Auto Insurance for:")	
       print(x)		
       return;
   elif vpoption == 3:
    ssn = input("Enter their SSN: ")
    mycursor = mydb.cursor()
    sql = "select LastName, FirstName, PolicyStatus as HealthInsuranceStatus from ClientInfo natural join HealthInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print("Health Insurance for:")	
       print(x)
       return;
   elif vpoption == 4:
    ssn = input("Enter their SSN: ")
    mycursor = mydb.cursor()
    sql = "select LastName, FirstName, PolicyStatus as LifeInsuranceStatus from ClientInfo natural join LifeInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql, arg)
    myresult = mycursor.fetchall()
    for x in myresult:
       print("Life Insurance for:")	
       print(x)
       return;



#View Menu Option 4
def showall():
  mycursor = mydb.cursor()
  mycursor.execute("SELECT * FROM ClientInfo")
  myresult = mycursor.fetchall()
  for x in myresult:
    print(x)
  return;


#View Menu Option 5
def viewproperties():
   print("")
   ssn = input("Enter their SSN: ")
   mycursor = mydb.cursor()
   sql = "select LastName, FirstName, Count(PropertiesInsured) from ClientInfo natural join HomeInsurance where SSN = %s"
   arg = (ssn,)
   mycursor.execute(sql, arg)
   myresult = mycursor.fetchall()
   for x in myresult:
       print("Properties Insured for:")
       print(x)
       return;
 


#View Menu Option 6
def viewvehicles():
   print("")
   ssn = input("Enter their SSN: ")
   mycursor = mydb.cursor()
   sql = "select LastName, FirstName, Count(VehiclesInsured) from ClientInfo natural join AutoInsurance where SSN = %s"
   arg = (ssn,)
   mycursor.execute(sql, arg)
   myresult = mycursor.fetchall()
   for x in myresult:
       print("Vehicles Insured for:")
       print(x)
       return;

##########################################################################################
##########################################################################################

#Add Menu Option 1
def addclient():
  lastid = 0;
  ssn = input("Social Security Number: ")
  fn = input("First Name: ")
  ln = input("Last Name: ")
  pn = input("Phone Number: ")
  fa = input("First Address Line: ")
  sa = input("Second Address Line: ")
  zc = input("Zip Code: ")
  cy = input("City: ")
  se = input("State (Abbreviation): ")
  bd = input("Birthday (YYYY-MM-DD): ")
  mycursor = mydb.cursor()
  sql = "INSERT INTO ClientInfo (SSN, FirstName, LastName, PhoneNumber, AddressLine1, AddressLine2, ZipCode, City, State, Birthday) VALUES (%s, %s, %s,%s,%s,%s,%s,%s,%s,%s)"
  arg = (ssn, fn, ln,pn, fa, sa, zc, cy, se, bd)
  mycursor.execute(sql, arg)
  if mycursor.lastrowid:
              lastid = mycursor.lastrowid
  mydb.commit()
  return;


##########################################################################################
##########################################################################################

#Update Menu Option 1
def updatename():
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")   
    fn = input("Please enter their first name: ")    
    ln = input("Please enter their last name: ")      
    sql = "Update ClientInfo set FirstName = %s, LastName = %s where SSN = %s"
    arg = (fn,ln,ssn)
    mycursor.execute(sql,arg)  
    return;


#Update Menu Option 2
def updatephone():
    mycursor = mydb.cursor()
    pn = input("Please enter their new Phone Number: ")    
    ssn = input("Enter their Social Security Number: ")   
    sql = "UPDATE ClientInfo SET PhoneNumber = %s WHERE SSN = %s;"
    arg = (pn,ssn)
    mycursor.execute(sql, arg)  
    return;




#Update Menu Option 3
def updateAddress():
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")   
    fl = input("Please enter the first Address line: ")    
    sl = input("Please enter the first Address line: ")      
    sql = "Update ClientInfo set Addressline1 = %s, Addressline2 = %s where SSN = %s"
    arg = (fl,sl,ssn)
    mycursor.execute(sql,arg)  
    return;




#Update Menu Option 4
def updateStatus():
   vpoption = 0;
   print("")
   print("Choose which plan you want to change the status of:") 
   print("1. Home Insurance") 
   print("2. Auto Insurance") 
   print("3. Health Insurance") 
   print("4. Life Insurance") 
   vpoption = int(input("Choice: "))
   print (vpoption)
   if vpoption == 1:
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")   
    ps = input("Enter updated policy status: ")         
    sql = "Update HomeInsurance set PolicyStatus = %s where SSN = %s"
    arg = (ps, ssn)
    mycursor.execute(sql,arg)  
    return;
   elif vpoption == 2:
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")   
    ps = input("Enter updated policy status: ")         
    sql = "Update AutoInsurance set PolicyStatus = %s where SSN = %s"
    arg = (ps, ssn)
    mycursor.execute(sql,arg)  
    return;
   elif vpoption == 3:
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")   
    ps = input("Enter updated policy status: ")         
    sql = "Update HealthInsurance set PolicyStatus = %s where SSN = %s"
    arg = (ps, ssn)
    mycursor.execute(sql,arg)  
    return;
   elif vpoption == 4:
     mycursor = mydb.cursor()
     ssn = input("Enter their Social Security Number: ")   
     ps = input("Enter updated policy status: ")         
     sql = "Update LifeInsurance set PolicyStatus = %s where SSN = %s"
     arg = (ps, ssn)
     mycursor.execute(sql,arg)  
     return;

##########################################################################################
##########################################################################################


#Delete Menu option 1
def removepolicy():
   vpoption = 0;
   print("")
   print("Choose which plan you want to delete from a client's plan:") 
   print("1. Home Insurance") 
   print("2. Auto Insurance") 
   print("3. Health Insurance") 
   print("4. Life Insurance") 
   vpoption = int(input("Choice: "))
   print (vpoption)
   if vpoption == 1:
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")           
    sql = "Delete from HomeInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql,arg)  
    return;
   elif vpoption == 2:
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")           
    sql = "Delete from AutoInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql,arg)  
    return;
   elif vpoption == 3:
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")           
    sql = "Delete from HealthInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql,arg)  
    return;
   elif vpoption == 4:
    mycursor = mydb.cursor()
    ssn = input("Enter their Social Security Number: ")           
    sql = "Delete from LifeInsurance where SSN = %s"
    arg = (ssn,)
    mycursor.execute(sql,arg)  
    return;





###############################################################
###############################################################
###############################################################
###############################################################
###############################################################
###############################################################
###############################################################
###############################################################
###############################################################

#View Menu
def view():
 voption = 0;

 while voption != 7: 
    
   print("")
   print("What information would you like to view?") 
   print("1. Request their insurance plan data")   
   print("2. Request their client data")
   print("3. Check to see if an insurance policy is active")
   print("4. Display all clients")   
   print("5. See all the properties you have insured")  
   print("6. See all the vehicles your have insured") 
   print("7. Return to main menu")
    
   voption = int(input("Choice: "))
   print (voption)
   if voption == 1:
        viewplan()
   elif voption == 2:
        viewclientinfo()
   elif voption == 3:
        viewactive()
   elif voption == 4: 
        showall()
   elif voption == 5:
        viewproperties()   
   elif voption == 6:
        viewvehicles()



#Add Menu
def add():
 aoption = 0;

 while aoption != 2: 
    
   print("")
   print("What information do you want to add?") 
   print("1. If you are going to register a new client's information")
   print("2. Return to main menu")
    
   aoption = int(input("Choice: "))
   print (aoption)
   if aoption == 1:
        addclient()



#Update Menu
def update():
 uoption = 0;

 while uoption != 5: 
    
   print("")
   print("What information do you want to update?") 	 
   print("1. To update their name")
   print("2. To update their contact number")
   print("3. To update their address")
   print("4. To change their policy status") 
   print("5. Return to main menu")
    
   uoption = int(input("Choice: "))
   print (uoption)
   if uoption == 1:
        updatename()
   elif uoption == 2:
        updatephone()
   elif uoption == 3:
        updateAddress()
   elif uoption == 4:
        updateStatus()
 


#Delete Menu
def delete():
 doption = 0;

 while doption != 2: 
    
   print("")
   print("What information do you want to delete?")  
   print("1. To remove a insurance policy from their plan") 
   print("2. Return to main menu")
    
   doption = int(input("Choice: "))
   print (doption)
   if doption == 1:
        removepolicy()


###############################################################
###############################################################
###############################################################
###############################################################
###############################################################
###############################################################
#MAIN PROGRAM
mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="Insurance"
)

mainoption = 0;

while mainoption != 5: 

    print("")
    print("Welcome to phasecare, please select one of the following options:")
    print("1. View their information")
    print("2. Add new information")    
    print("3. Update their information")    
    print("4. Delete a policy")
    print("5. If no further help is needed")

    mainoption = int(input("Choice: "))
    print (mainoption)
    if mainoption == 1:
        view()
    elif mainoption == 2:
        add()
    elif mainoption == 3:
        update()
    elif mainoption == 4:
        delete()
    elif mainoption == 5:
        print("Thank for using phasecare, have a great day!")


