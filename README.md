# ATMulator

ATMulator is an ATM simulator which takes care of creating accounts, tranfers, deposits and withdraw and denomination of notes in the ATM. 
The denomination.txt file has one string of 9 character. First three characters(from 0 to 2) gives the number of one hundred rupees notes present in the ATM. Similarly, the next three characters (index 3, 4, 5) 
represent number of five hundred rupees notes and the last three characters represent number of two thousand rupees notes. So, everytime user withdraws something , the number of notes in each denomination will reduce accordingly. 

The deposit.txt file contains strings. The string consists of name, pin and the deposit amount the customer deposits in the ATM.

First,  customer has to create an account. For example, name: Sourik Dhua. So, the program will generate a random number and give you the pin. The pin has to be remembered to login next time. 
As soon as the account is created, a new file names.txt is created and string name + string pin is stored in names.txt.As the other users create accout, data is appended to names.txt. 

For authentication in each case, the user has to input name and pin. We make a string which is concatenation of name and pin and compare it with the data stored in names.txt.
A typical string in names.txt is "Sourik Dhua1001", that is, name+pin. 

Second, the user needs to deposit some amount in the ATM. The ATMulator asks for name and pin. After the user enters the pin, ATMulator checks it with the data in names.txt. Then it asks for the deposit amount. 
After giving the deposit amount, in a new file, that is, deposit.txt, the string name+ string pin + string deposit will be stored.

By using string manipulations, the deposit amount is retreived every time withdrawal, deposit or a tranfer is being made. After that, it is converted to int , required calcultion is performed (For example: amount after withdrawal= total amount-withdrawn amount), 
then the interger is converted back to string and it is finally put in the corresponding string in deposit.txt

IMPROVEMENTS: 

1. Functions can be made for : 
* String to int conversion
* int to string conversion
* Appending zeroes(zeroes are appended so that everytime deposit substring remains a 6 char string as it is easy to retrive it if it is a specific size string)

2. Denominations are to be added while depositing in the similar manner as we subtract them while withdrawal. For example, if I deposit 1500 rupees, three five hundred rupee note has to be added in the the string in denomination.txt. For example if initial string is 100100100 which means all the three denominations has 100 notes. 
Then after the trasnaction the string will be 100097100, which means 97 notes of five hundred rupees. 

3.In the case of transfer, an attribute such as account number can be added. The receiver's account number is important as if there are two persons with the same name,th ATMulator takes in the first name. 
Account number can be added in a similar manner. Concatenate this to the string in deposit.txt. So, a typical string in deposit.txt will look like "Sourik Dhua100105000012345" where 12345 is the aacoount number, 1001 is the pin and 050000 is the amount in my account. 





