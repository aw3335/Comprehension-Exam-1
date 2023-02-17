/*
By: Austin Weaver
This app simulates a roulette table at a casino allow each player to place bets on any of the choices allowed. Then a random
number is draw and you will be granted money based on the bets put in. 
*/
#include <string> 
#include <iostream>

/*
* These array are all the answers that the program will check to see if the user has won any money.
*/
int oneToEightteen[18] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
int nineteenToThirtysix[18] = { 19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };
int red[18] = { 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 };
int black[18] = { 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };
int even[18] = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36 };
int odd[18] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35 };
int thirdColumn[12] = { 3,6,9,12,15,18,21,24,27,30,33,36 };
int secondColumn[12] = { 2,5,8,11,14,17,20,23,26,29,32,35 };
int firstColumn[12] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 };
int firstRow[3] = { 1,2,3 };
int secondRow[3] = { 4,5,6 };
int thridRow[3] = { 7,8,9 };
int fourthRow[3] = { 10,11,12 };
int fifthRow[3] = { 13,14,15 };
int sixthRow[3] = { 16,17,18 };
int seventhRow[3] = { 19,20,21 };
int eigthRow[3] = { 22,23,24 };
int ninthRow[3] = { 25,26,27 };
int tenthRow[3] = { 28,29,30 };
int eleventhRow[3] = { 31,32,33 };
int twelfthRow[3] = { 34,35,36 };

/*
* These arrays and variable are used to keep information on what the user enter. When the
* user enter start, then the program will refrence these variable for the choices they made 
* and how much they bet on each one.
*/
double amt[100];
int choice[100];
int colNum[100];
int rowNum[100];
int one[100];
int countNum = 0;
int chosenNum;
int randomNum;
int loopCounter = 0;
double betAmt = 0;

/*
These two variable hold the balance that the user hasand how much they want to add
when adding
*/
double balance = 0;
double addedBalance = 0;

/*
* These variables are checkers for the user. They help let the program know if the user whishes to continue playing or
* if the program should end.
*/
bool playAgain = true;
char again = 'n';

//Function Declarations
bool winner(int);
void operations();
void bet();
void outcome(bool);
void totalBalance();
void storeNum(int);
void getWinningNum();
void colNumbers(int);
void rowNumbers(int);

//Namespace setup so std doesnt have to be typed behind everything
using namespace std;

int main()
{
	/*
	* do while loop that does all the front end choices. As long as the user doesnt enter N then the loop
	* will continue to ask what they want to enter. If at any point they enter start, then the program will start and will only
	* continue the loop if the user enters Y.
	*/
	do
	{
		//Variables that will hold the choice the user makes
		int aChoice;


		//Options the user has to choose from
		cout << "Menu:\n"
			<< "1. Zero\n"
			<< "2. Single Number\n"
			<< "3. Column\n"
			<< "4. Row\n"
			<< "5. Odd\n"
			<< "6. Even\n"
			<< "7. Red\n"
			<< "8. Black\n"
			<< "9. 1 to 18\n"
			<< "10. 19 to 36\n"
			<< "11. Check Balance\n"
			<< "12. Add to Balance\n"
			<< "13. Start\n"
			<< "14. Quit";

		cout << "\nEnter a number: ";
		cin >> aChoice;

		//While the user doesnt choose start or quit keep looping the options and getting a choice
		while (aChoice != 14 && aChoice != 13)
		{
			//While the user is out of money or a invalid choice has been made, ask for the information again 
			//and give readable error to user
			while (aChoice < 1 || aChoice > 14 || balance == 0 && aChoice != 12)
			{
				if (balance == 0)
				{
					cout << "\nError no balance, enter number 12 to input a balance.\n\n";
				}
				else
				{
					cout << "Error Choose Another Number\n\n";
				}

				cout << "Menu:\n"
					<< "1. Zero\n"
					<< "2. Single Number\n"
					<< "3. Column\n"
					<< "4. Row\n"
					<< "5. Odd\n"
					<< "6. Even\n"
					<< "7. Red\n"
					<< "8. Black\n"
					<< "9. 1 to 18\n"
					<< "10. 19 to 36\n"
					<< "11. Check Balance\n"
					<< "12. Add to Balance\n"
					<< "13. Start\n"
					<< "14. Quit";

				cout << "\nEnter a number: ";
				cin >> aChoice;
			}

			storeNum(aChoice);

			cout << "Menu:\n"
				<< "1. Zero\n"
				<< "2. Single Number\n"
				<< "3. Column\n"
				<< "4. Row\n"
				<< "5. Odd\n"
				<< "6. Even\n"
				<< "7. Red\n"
				<< "8. Black\n"
				<< "9. 1 to 18\n"
				<< "10. 19 to 36\n"
				<< "11. Check Balance\n"
				<< "12. Add to Balance\n"
				<< "13. Start\n"
				<< "14. Quit";

			cout << "\nEnter a number: ";
			cin >> aChoice;

		}
		//if start has been selected then begin the operations and then let the user
		//know their total balance. Once the roulette is done, then it will ask if the user wants
		//to play again.
		if (aChoice == 13)
		{
			operations();

			totalBalance();

			cout << "\n\n Do you want to continue: (Y / N) ";
			cin >> again;

			//If the choice is yes then reset the stored array so the program doesnt repeat any data and then start over
			if (again == 'Y' || again == 'y')
			{
				playAgain = true;

				amt[99];
				choice[99];
				colNum[99];
				rowNum[99];
				one[99];
				countNum = 0;
				chosenNum = 0;
				randomNum = 0;
				loopCounter = 0;
			}
			//If not yes then end the program and thank the user for playing the roulette
			else
			{
				playAgain = false;

				cout << "Thank you for playing the roulette. Please come again!";
			}
		}
	} while (playAgain);

	return 0;
}

/*
* Function storeNum
* This function takes in a choice from the user and stores the correct information based of
* the choice. Then the function will get the betting amount and subtract that amount from the total
* balance that the user has.
*/
void storeNum(int num)
{
	//If the numbers the user chose was 2 then get the single numbers and do input validation, then store that 
	//number in the correct location
	if (num == 2)
	{
		cout << "Enter a number from 1 to 36: ";
		cin >> chosenNum;

		while (chosenNum < 1 || chosenNum > 36)
		{
			cout << "Error invalid number \n\nEnter a number from 1 to 36: ";
			cin >> chosenNum;
		}
		one[countNum] = chosenNum;
	}
	//If the numbers the user chose was 3 then get the column the user wants and do input validation, then 
	//same thing, store it in the appropiate array for it to be called on later
	else if (num == 3)
	{
		cout << "Which column would you like to choose? (1, 2, 3) ";
		cin >> chosenNum;

		while (chosenNum < 1 || chosenNum > 3)
		{
			cout << "Invalid Number try again\n\nWhich column would you like to choose? (1, 2, 3) ";
			cin >> chosenNum;
		}
		colNum[countNum] = chosenNum;
	}
	//Same as the one above but for rows
	else if (num == 4)
	{
		cout << "Which row  would you like to choose? (1 - 12) ";
		cin >> chosenNum;

		while (chosenNum < 1 || chosenNum > 12)
		{
			cout << "Invalid Number try again\n\nWhich row would you like to choose? (1 - 12) ";
			cin >> chosenNum;
		}
		rowNum[countNum] = chosenNum;
	}
	//If the chosen number is 11 then call the totalBalance function and display it to the user
	else if (num == 11)
	{
		totalBalance();
	}
	//If the choice was 12 then get the balance the user wants to add and add it to the total balance. 
	//Also let user know the newly update balance.
	else if (num == 12)
	{
		cout << "How much money would you like to add: ";
		cin >> addedBalance;

		balance += addedBalance;
		cout << "\n\nNew total balance: $" << balance << "\n\n";
	}

	//If any of these arrays was not chosen or updated then fill it with a 0 that way its not mistaken as filled with some
	//number
	if (one[countNum] == NULL)
	{
		one[countNum] = 0;
	}
	else if (colNum[countNum] == NULL)
	{
		colNum[countNum] = 0;
	}
	else
	{
		rowNum[countNum] = 0;
	}

	//As long as the numbers is not 11,12,13,or 14 then get the betting amount and store it in the appropiate arrays. Then increase 
	//the couuntNum signifying that the array will increase in size by 1. This will allow the user to make up to 100 bets without
	//being stopped.
	if (num != 11 && num != 12 && num != 13 && num != 14)
	{
		bet();
		amt[countNum] = betAmt;
		balance -= betAmt;
		choice[countNum] = num;
		countNum++;
	}
}

/*
* Operations Function
* This function when called performs the operations of the roulette. Based of the chosen Numbers the user made, the function
* will display the choice, then determine if you won or loss and display that, and then push the array to the next choice.
*/
void operations()
{
	//Boolean variable that will hold if the user won or lost
	bool winLoss = true;
	//Print out for looks in the console
	cout << "\n****************************************\n";

	//For every choice the user made, loop throught those choices and determine the appropiate actions that need to happen.
	for (int i = 0; i < countNum; i++)
	{
		switch (choice[i])
		{
		case 1:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: Zero";
			winLoss = winner(1);
			loopCounter++;
			outcome(winLoss);
			break;
		case 2:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: Single Number\n";
			cout << "Chosen Number: " << one[i] << "\n";
			winLoss = winner(2);
			loopCounter++;
			outcome(winLoss);
			break;
		case 3:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: Column #" << colNum[i] << "\n";
			colNumbers(colNum[i]);
			winLoss = winner(3);
			loopCounter++;
			outcome(winLoss);
			break;
		case 4:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: Row #" << rowNum[i] << "\n";
			rowNumbers(rowNum[i]);
			winLoss = winner(4);
			loopCounter++;
			outcome(winLoss);
			break;
		case 5:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: Odd Numbers";
			winLoss = winner(5);
			loopCounter++;
			outcome(winLoss);
			break;
		case 6:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: Even numbers";
			winLoss = winner(6);
			loopCounter++;
			outcome(winLoss);
			break;
		case 7:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: Red Numbers";
			winLoss = winner(7);
			loopCounter++;
			outcome(winLoss);
			break;
		case 8:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: Black Numbers";
			winLoss = winner(8);
			loopCounter++;
			outcome(winLoss);
			break;
		case 9:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: 1 to 18";
			winLoss = winner(9);
			loopCounter++;
			outcome(winLoss);
			break;
		case 10:
			cout << "Bet Amount: " << amt[i] << "\nChosen Value: 19 to 36";
			winLoss = winner(10);
			loopCounter++;
			outcome(winLoss);
			break;
		}
	}

}

/*
* Outcome Function
* This function lets the user know if they won the roulette spin. If they win let them know how much they won else 
* dont because you dont let the user know how much they are losing.
*/
void outcome(bool winLoss)
{
	if (winLoss)
	{
		cout << "\n\nYou win $" << betAmt * 2 << "\n\n * ***************************************\n";
		balance += (betAmt * 2);
	}
	if (!winLoss)
	{
		cout << "\n\nYou lose\n\n****************************************\n";
	}
}

/*
* Total Balance Function
* This function simple as is, displays the current total balance to the user.
*/
void totalBalance()
{
	cout << "\n\nCurrent balance: $" << balance << "\n\n";
}

/*
* Function Bet
* This function gets how much the user will bet and stores it in the betAmt variable and later in the bet amount array
*/
void bet()
{
	cout << "How Much would you like to bet: $";
	cin >> betAmt;

	if (betAmt > balance || betAmt <= 0)
	{
		cout << "Error Please try again: \nHow Much would you like to bet: $";
		cin >> betAmt;
	}
}

/*
* Function RandNumber
* This function simply returns a random number from 0 to 36
*/
int randNumber()
{
	srand(time(0));
	return rand() % 37;
}

/*
* Function GetWinningNum
* This function will call that randNum function and dislay the random number to the user indicating that it is the winning number.
*/
void getWinningNum()
{
	randomNum = randNumber();
	cout << "\nWinning number is: " << randomNum;
}

/*
* Function Winner
* This function is the checker behind the scenes. This function will loop throught each choice and if that choice
* matches the winning number then the user wins otherwise they lose.
*/
bool winner(int chosenCase)
{
	//Gets the winning number once in the beginning
	getWinningNum();

	//If the chosenCase is 1 then compae the randNum to zero and then return true if they won or false if not.
	if (chosenCase == 1)
	{
		if (randomNum == 0)
		{
			return true;
		}
		return false;
	}
	//If chosenCase is 2 then compare the random number to the users chosen number and then return true if they won or false if not
	else if (chosenCase == 2)
	{
		if (one[loopCounter] == randomNum)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//If chosenCase == 3, the switch between the columns based off the users choices and check if the randomNum is in that 
	//column. Then return true if they won or false if not
	else if (chosenCase == 3)
	{
		int i = 0;
		switch (colNum[loopCounter])
		{
		case 1:
			while (i < 12)
			{
				if (firstColumn[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 2:
			while (i < 12)
			{
				if (secondColumn[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 3:
			while (i < 12)
			{
				if (thirdColumn[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		default:
			break;
		}
	}
	//If chosenCase is 4 then switch through all the chosen Row and checks if that row contains the numbers. Then return true if
	//it does and false if not.
	else if (chosenCase == 4)
	{
		int i = 0;
		switch (rowNum[loopCounter])
		{
		case 1:
			while (i < 3)
			{
				if (firstRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 2:
			while (i < 3)
			{
				if (secondRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 3:
			while (i < 3)
			{
				if (thridRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 4:
			while (i < 3)
			{
				if (fourthRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 5:
			while (i < 3)
			{
				if (fifthRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 6:
			while (i < 3)
			{
				if (sixthRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 7:
			while (i < 3)
			{
				if (seventhRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 8:

			while (i < 3)
			{
				if (eigthRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 9:
			while (i < 3)
			{
				if (ninthRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 10:
			while (i < 3)
			{
				if (tenthRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 11:
			while (i < 3)
			{
				if (eleventhRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		case 12:
			while (i < 3)
			{
				if (twelfthRow[i] == randomNum)
				{
					return true;
				}
				i++;
			}
			return false;
			break;
		default:
			return false;
			break;
		}
	}
	//If chosenCase is 5 then compare the randomNumber to the odd numbers and check to see if they won
	else if (chosenCase == 5)
	{
		int i = 0;
		while (i < 18)
		{
			if (odd[i] == randomNum)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	//If chosenCase is 6 then compare to even instead of odd and see if they won.
	else if (chosenCase == 6)
	{
		int i = 0;
		while (i < 18)
		{
			if (even[i] == randomNum)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	//If chosenCase is 7 then check if the number is a red number and the check if they won
	else if (chosenCase == 7)
	{
		int i = 0;
		while (i < 18)
		{
			if (red[i] == randomNum)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	//If chosenCase is 8 then check if number is a black number and see if they won
	else if (chosenCase == 8)
	{
		int i = 0;
		while (i < 18)
		{
			if (black[i] == randomNum)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	//If chosenCase is 9 then check if it is between 1 and 18 and let them know if they won
	else if (chosenCase == 9)
	{
		int i = 0;
		while (i < 18)
		{
			if (oneToEightteen[i] == randomNum)
			{
				return true;
			}
			i++;
		}
		return false;
	}
	//Lastly, if chosenCase is 10 then check if the number if between 19 and 36 and let them know they won
	else if (chosenCase == 10)
	{
		int i = 0;
		while (i < 18)
		{
			if (nineteenToThirtysix[i] == randomNum)
			{
				return true;
			}
			i++;
		}
		return false;
	}

}

/*
* colNumbers Function
* This function is for display and will display the column numbers based of the column the user has chosen. It helps let
* the user check if the answer is correct.
*/
void colNumbers(int num)
{
	cout << "Selected Column Numbers: " << "\n";
	for (int i = 0; i < 12; i++)
	{
		if (num == 1)
		{
			cout << firstColumn[i] << " ";
		}
		else if (num == 2)
		{
			cout << secondColumn[i] << " ";
		}
		else
		{
			cout << thirdColumn[i] << " ";
		}
	}
}

/*
* rowNumbers function
* Same as above function but checks rowNumbers and displays to user. Also helps with checking the if the program has malfunctioned.
*/
void rowNumbers(int num)
{
	cout << "Selected Row Numbers: " << "\n";
	for (int i = 0; i < 3; i++)
	{
		if (num == 1)
		{
			cout << firstRow[i] << " ";
		}
		else if (num == 2)
		{
			cout << secondRow[i] << " ";
		}
		else if (num == 3)
		{
			cout << thridRow[i] << " ";
		}
		else if (num == 4)
		{
			cout << fourthRow[i] << " ";
		}
		else if (num == 5)
		{
			cout << fifthRow[i] << " ";
		}
		else if (num == 6)
		{
			cout << sixthRow[i] << " ";
		}
		else if (num == 7)
		{
			cout << seventhRow[i] << " ";
		}
		else if (num == 8)
		{
			cout << eigthRow[i] << " ";
		}
		else if (num == 9)
		{
			cout << ninthRow[i] << " ";
		}
		else if (num == 10)
		{
			cout << tenthRow[i] << " ";
		}
		else if (num == 11)
		{
			cout << eleventhRow[i] << " ";
		}
		else
		{
			cout << twelfthRow[i] << " ";
		}
	}
}