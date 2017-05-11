#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include<ctime>
using namespace std;
int main()
{	
	string name,  denom_line,iname, in_info, line, str_pin, dep_line,depline, amount, balance_line, str_balance, temp, overall_denom;
	char zeroes[20], zero[20];
	int iline, op, pin,ipin,iamount, withdraw, transfer,int_amount, no_of_zeroes,x,y,z;
	long int deposit;
	string one_hundred, five_hundred, two_thousand, your_balance, transfer_name, trans_line, transfer_line, str_dep;
	int  name_length, int_one_hundred, int_five_hundred, int_two_thousand, i, j, k;
	stringstream dep,ss;
	
	cout<<"1. create account 2. withdraw 3. check balance 4. deposit 5. tranfer 6. exit\n";
	cin>>op;
	switch(op)
	{
		case 1:{ cout<<"*** create account ***\n";
			cin.ignore();
			cout<<" Enter name: \n";
			getline(cin,name);
			ofstream file ("names.txt", ios_base::app);			
			srand ( time(NULL) );
			pin= rand() % 9000 + 1000;
			cout<<" Your pin is " <<pin<<". Keep it safe\n";
			file<<name<<pin<<"\n";
			file.close();
			break;
			}
		case 2: {cout<<"***Withdraw***"; 
			i=1;
			while (i==1)
			{
				cin.ignore();
				cout<<" Enter name\n"; 
				getline(cin,name);
				cout<<" Enter pin\n"; 
				cin>>ipin;
				ss<<ipin;
				str_pin = ss.str();
				in_info = name+str_pin;

				ifstream in_file ("names.txt");
				while(!in_file.eof())
				{
					getline(in_file, line);
					if (line==in_info)
					{
						cout<<" Checking database...\n";
						cout<<" Authentication found!\n";
						break;
					}
									
				}
				if(in_file.eof())
				{
					cout<<" The account does not exist\n";
					exit(0);
				}
				in_file.close();

				cout << "Enter the amount to be withdrawn\n";
				cin >> withdraw; 
				
				if (withdraw%100!=0)
				{
					cout<<" please enter multiples of Rs. 100 only. Insert again\n";
						
				}
					
				

				ifstream dep_file("deposit.txt");
				while(!dep_file.eof())
				{
					getline(dep_file, dep_line);
					name_length= in_info.length();
					if (dep_line.substr(0, name_length)== in_info)
					{

						string amount= dep_line.substr(name_length,6); 
						stringstream convert(amount);//object from the class stringstream.
						int_amount=0;
						convert>>int_amount;
						cout<<" initial balance in account is : "<<int_amount;
					
						break;
					}	
				}
				dep_file.close();

				if (withdraw<=int_amount && withdraw<=10000)
				{
							
					cout<<" Please take your cash\n";
					deposit= int_amount-withdraw;
					dep<<deposit;
					str_balance= dep.str();
					no_of_zeroes= 6- str_balance.length();
					if (no_of_zeroes== 0)
					{
						balance_line= name+ str_pin + str_balance;

					}
					else
					{
				
						for(i=0; i<no_of_zeroes; i++)
						{
							zeroes[i]= '0';
						}
						zeroes[no_of_zeroes]='\0';
						balance_line= name+ str_pin + zeroes+ str_balance;
					}
		
					ifstream infile("deposit.txt");
					ofstream outfile("output.txt");
					while(!infile.eof())
					{
					      getline(infile, depline);
					      if(depline==dep_line)
					      {
						     depline= balance_line;
						     // cout<<" hello there\n";
					      }


					      outfile<<depline<<"\n";

					}
					infile.close();
					outfile.close();

				       remove("deposit.txt");
				       rename("output.txt", "deposit.txt");

				       ifstream denom_file("denomination.txt");
				       getline(denom_file, denom_line);
				       one_hundred= denom_line.substr(0,3);
				       five_hundred= denom_line.substr(3, 3);
				       two_thousand= denom_line.substr(6, 3);

					stringstream con(one_hundred);//object from the class stringstream.
        				int_one_hundred=0;
					con>>int_one_hundred;
					cout<<" no. of 100 rs notes in atm is : "<<int_one_hundred;
					
					stringstream conv(five_hundred);//object from the class stringstream.
        				int_five_hundred=0;
					conv>>int_five_hundred;
					cout<<" no. of 500 rs notes in atm is : "<<int_five_hundred;

					stringstream convert(two_thousand);//object from the class stringstream.
        				int_two_thousand=0;
					convert>>int_two_thousand;
					cout<<" no. of 2000 rs notes in atm is : "<<int_two_thousand;

					for (i=0; i<=int_one_hundred; i++ )
					{
						for (j=0;j<=int_five_hundred; j++)
						{
							for (k= 0; k<=int_two_thousand; k++)
							{
								if(100*i+ 500*j+ 2000*k==withdraw)
								{
									cout<<" Number of one hundred notes ejected: " <<i<<"\n";
									
									cout<<" Number of five hundred notes ejected: "<<j<<"\n";
										
									cout<<" Number of two thousand notes ejected: " <<k<<"\n";
									
									goto afterloop;
								}
	
								
							}
						}
					}
					afterloop: if (i==int_one_hundred && j== int_five_hundred &&  k== int_two_thousand && (100*i +500*j +2000*k!= withdraw))
					{
						cout<<" Sorry! Insufficient cash in the ATM. ";
						exit(0);
					}			
					denom_file.close();

					no_of_zeroes=0;
					int_one_hundred=  int_one_hundred -i;
					int_five_hundred= int_five_hundred-j;
					int_two_thousand= int_two_thousand-k; 
					cout<<" after transaction: 1,5 and 2 hundred: "<<int_one_hundred<<" "<<int_five_hundred<<" "<<int_two_thousand;
	
					ofstream denom_f("denomination.txt");
					stringstream dep;
					dep<<int_one_hundred;
			 		one_hundred= dep.str();
					cout<<" one hundred string after transaction: " <<one_hundred;
	
					no_of_zeroes= 3-one_hundred.length();
					cout<<" no./ of zeroes= "<<no_of_zeroes;
					if (no_of_zeroes==0)
					{	
						one_hundred=one_hundred;
							
					}
					else
					{
						for(i=0;i< no_of_zeroes;i++ )
						{
							zero[i]='0';
						}
						zero[no_of_zeroes]='\0';
						one_hundred= zero+one_hundred; 
					}
										
				
					stringstream five;
					five<<int_five_hundred;
			 		five_hundred= five.str();
					cout<<" 5 hundred string after transaction before adding zero: "<<five_hundred<<"\n";
					no_of_zeroes= 3-five_hundred.length();
					if (no_of_zeroes==0)
					{	
						five_hundred= five_hundred;	
					}
					else
					{
						for(i=0;i< no_of_zeroes;i++ )
						{
							zero[i]='0';
						}
						zero[no_of_zeroes]='\0';
						cout<<" zeroes for five hundred are: \n"<<zero;
						five_hundred= zero+five_hundred; 
						cout<<" five hundred string after adding zero " <<five_hundred<<"\n";
					}

				
					stringstream two;
					two<<int_two_thousand;
			 		two_thousand= two.str();
					no_of_zeroes= 3-two_thousand.length();
					if (no_of_zeroes==0)
					{	
						two_thousand=two_thousand;	
					}
					else
					{
						for(i=0;i<no_of_zeroes;i++ )
						{
							zero[i]='0';
						}
						zero[no_of_zeroes]='\0';
						two_thousand= zero+two_thousand; 
					}
					overall_denom=one_hundred+five_hundred+two_thousand;
					cout<<" overall denom is : \n"<<overall_denom<<"\n";
					denom_f<<overall_denom;
					denom_f.close();
					exit(0);
				}


				if (withdraw>int_amount) 
				{
					cout<<" Sorry! Not enough funds in your account! Press 1 to try again and press 2 to cancel \n";
					cin>>i;
				
					if (i==2)
					{
						cout << " transaction cancelled\n";
						exit(0);
					}
				}
				if(withdraw>10000) 
				{
					cout<<" Cash can be withdrawn up to 10000 only. press 1 to try again and 2 to cancel. \n";
					cin >>i;
		
					if (i==2)
					{
						cout << " transaction cancelled\n";
						exit(0);
					}

				}
			}
			break;
			}

		case 3: {	cin.ignore();
				cout<<" Enter name\n"; 
				getline(cin,name);
				cout<<" Enter pin\n"; 
				cin>>ipin;
				ss<<ipin;
				str_pin = ss.str();
				in_info = name+str_pin;
				ifstream in_file ("names.txt");
				while(!in_file.eof())
				{
					getline(in_file, line);
					if (line==in_info)
					{
						cout<<" Authentication found!\n";
						break;
					}
				}
				if(in_file.eof())
				{
					cout<<" The account does not exist\n";
					exit(0);
				}
				in_file.close();

				cout<<"***check balance***'\n";
				ifstream check_balance("deposit.txt");
				//getline(check_balance, dep_line);
				while(!check_balance.eof())
				{
					getline(check_balance, dep_line);
					name_length= in_info.length();
					if (dep_line.substr(0, name_length)== in_info)
					{

						your_balance= dep_line.substr(name_length,6); 
						cout<<" Your balance is : "<<your_balance<<"\n";
						break;
					}	
				}
				if(check_balance.eof())
				{
					cout<<" Your account is empty. Please deposit soon. \n";
				}
				check_balance.close();
				break;
			}
		case 4: {	cin.ignore();
				cout<<" Enter name\n"; 
				getline(cin, name);
				cout<<" Enter pin\n"; 
				cin>>ipin;
				ss<<ipin;
				str_pin = ss.str();
				in_info = name+str_pin;
				ifstream in_file ("names.txt");
				while(!in_file.eof())
				{
					getline(in_file, line);
					if (line==in_info)
					{
						cout<<" Authentication found!\n";
						break;
					}
				}
				if(in_file.eof())
				{
					cout<<" The account does not exist\n";
					exit(0);
				}
				in_file.close();
				cout<<"***deposit***\n";
				cout<<" DEPOSIT CANNOT BE MORE THAN Rs.9,99,999\n";
				cout<<" How much do you want to deposit\n";
				cin >> deposit;
				if (deposit>999999)
				{
					cout<<" Invalid amount entered. Keep it less than Rs. 9,99,999\n";
				}	
				cout<<deposit<<" has been deposited\n";


				ifstream de_file ("deposit.txt");
				while(!de_file.eof())
				{
					getline(de_file, line);
					
					if (line.substr(0, in_info.length())==in_info)
					{
						cout<<" The line is : "<<line;
						line= line.substr(in_info.length(), 6);
						cout<<" The line is : "<<line;
						de_file.close();

						ofstream de_f("deposit.txt");
						stringstream convert(line);//object from the class stringstream.
						iline=0;
						convert>>iline;
						deposit= deposit+iline;
						cout<<" int deposit is : "<<deposit<<"\n";
						stringstream qq;
						qq<<deposit;
						str_dep = qq.str();
						cout<<" str_dep is : "<<str_dep;
						no_of_zeroes= 6-str_dep.length();
						if (no_of_zeroes==0)
						{	
							str_dep=str_dep;	
						}
						else
						{
							for(i=0;i<no_of_zeroes;i++ )
							{	
								zero[i]='0';
							}
							zero[no_of_zeroes]='\0';
							line= in_info+zero+str_dep; 
						}		
						cout<<" the line is : "<<line<<"\n";
						de_f<<line<<"\n";
						de_f.close();
						exit(0);
					}
				}
				if (de_file.eof())
				{
				
						ofstream bal_file("deposit.txt",ios_base:: app);
						stringstream depo;
						depo<<deposit;
						str_balance= depo.str();
						no_of_zeroes= 6- str_balance.length();
						if (no_of_zeroes== 0)
						{
							balance_line= name+ str_pin + str_balance;

						}
						else
						{
					
							for(i=0; i<no_of_zeroes; i++)
							{
								zeroes[i]= '0';
							}
							zeroes[no_of_zeroes]='\0';
							balance_line= name+ str_pin + zeroes+ str_balance;
						}
						cout <<" balance line in deposit file is : "<<balance_line;
						bal_file<<balance_line<<"\n";
						bal_file.close();
						break;
				}
				
			}
					
				
		
		case 5: {	cin.ignore();
				cout<<" Enter name\n"; 
				getline(cin, name);
				cout<<" Enter pin\n"; 
				cin>>ipin;
	
				ss<<ipin;
				str_pin = ss.str();
				in_info = name+str_pin;
				ifstream in_file ("names.txt");
				while(!in_file.eof())
				{
					getline(in_file, line);
					if (line==in_info)
					{
						cout<<" Authentication found!\n";
						break;
					}

				}
				if(in_file.eof())
				{
					cout<<" The account does not exist\n";
					exit(0);
				}
				in_file.close();

				cout<<"***Tranfer***\n"; 
				j=1;
				while (j==1)
				{
					cout<<" Enter the amount that you want to tranfer\n";
					cin >>transfer;
					cout<<" Whom do you want to transfer the funds? " ;
					cin.ignore();
					getline(cin, transfer_name);
					cout<<" The receiver is : "<<transfer_name<<"\n";
					cout<<"Rs "<<transfer<<" has been tranferred\n"; 
					
					if (transfer > 50000)
					{
						
						cout<<" Amount up to Rs. 50000 can be tranferred in one day. Press 1 to continue or 2 to cancel\n";
						cin>>j;
						if(j==1)
						{
							continue;
						}
					
						if (j==2)
						{
							cout << " Transaction cancelled\n";
							exit(0);
						
						}
					}
					
					else
					{
						
						ifstream transfer_file("deposit.txt");
						while(!transfer_file.eof())
						{
							getline(transfer_file, dep_line);
							name_length= in_info.length();
							if (dep_line.substr(0, name_length)== in_info)
							{

								string amount= dep_line.substr(name_length,6); 
								stringstream convert(amount);//object from the class stringstream.
								int_amount=0;
								convert>>int_amount;
							
								break;
							}	
						}
						transfer_file.close();
						int_amount= int_amount- transfer;
						stringstream dep;
						dep<<int_amount;
						str_balance= dep.str();
						no_of_zeroes= 6- str_balance.length();
						if (no_of_zeroes== 0)
						{
							balance_line= name+ str_pin + str_balance;

						}
						else
						{
					
							for(i=0; i<no_of_zeroes; i++)
							{
								zeroes[i]= '0';
							}
							zeroes[no_of_zeroes]='\0';
							balance_line= name+ str_pin + zeroes+ str_balance;
						}
			
						ifstream infile("deposit.txt");
						ofstream outfile("output.txt");
						while(!infile.eof())
						{
						      getline(infile, depline);
						      if(depline==dep_line)
						      {
							     depline= balance_line;
							     // cout<<" hello there\n";
						      }


						      outfile<<depline<<"\n";

						}
						infile.close();
						outfile.close();
                                             
				      		remove("deposit.txt");
				       		rename("output.txt", "deposit.txt");


				       		ifstream file_transfer_receiver("deposit.txt");
						while(!file_transfer_receiver.eof())
						{
							getline(file_transfer_receiver, transfer_line);
						//	cout<<transfer_line.substr(0, transfer_name.length())<<"\n";
							
							if (transfer_line.substr(0, transfer_name.length())==transfer_name)
							{
							
								amount= transfer_line.substr(transfer_name.length()+4, 6);
								stringstream convert(amount);//object from the class stringstream.
								iamount=0;
								convert>>iamount;
								iamount= iamount+transfer;
								
								stringstream dep;
								dep<<iamount;
								str_balance= dep.str();
								//cout<<" nandy's string amount afte receiving: "<<str_balance<<"\n";;
								no_of_zeroes= 6- str_balance.length();
								if (no_of_zeroes== 0)							
								{
									balance_line= transfer_line.substr(0,transfer_name.length()+4) + str_balance;
									break;
	
								}
								else
								{
					
									for(i=0; i<no_of_zeroes; i++)
									{
										zeroes[i]= '0';
									}
									zeroes[no_of_zeroes]='\0';
									balance_line= transfer_line.substr(0, transfer_name.length()+4) + zeroes+ str_balance;
								//	cout<<" balance line is : "<<balance_line<<"\n";
									break;
								}	
							}
						}
			
						ifstream in_file("deposit.txt");
						ofstream out_file("output.txt");
						while(!in_file.eof())
						{
						      getline(in_file, depline);
						      if(depline==transfer_line)
						      {
							     depline= balance_line;
							     // cout<<" hello there\n";
						      }


						      out_file<<depline<<"\n";

						}
						in_file.close();
						out_file.close();

						remove("deposit.txt");
						rename("output.txt", "deposit.txt");

						j= 0;
						

					}//main else loop
			
				}
				break;
		
			}

	
		case 6: {exit(0);
			break;
			}
	}
}
		
		
				
 
			
			
			  
			




			

			
			
	
	
		
		
	
	
	
