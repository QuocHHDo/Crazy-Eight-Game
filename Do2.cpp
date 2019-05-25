#include <iostream>
#include <cstdlib> //
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    int CardNum = 0;
    string card = ""; 
    
    const char suit [] = {'H', 'C', 'D', 'S'};
    const string face [] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    
    vector<string> deck;  

    for (int i = 0; i < 4; ++i) { 
        for (int j = 0 ; j < 13; ++j) {
            
            card = suit[i] + face[j]; 

            deck.push_back(card);
        }
    }
    random_shuffle (deck.begin(), deck.end());
    random_shuffle (deck.begin(), deck.end());
    random_shuffle (deck.begin(), deck.end());
    random_shuffle (deck.begin(), deck.end());
    random_shuffle (deck.begin(), deck.end());
	string saveCard;
	string topCard;
	topCard = deck.front();
	deck.erase(deck.begin()); 

  int hand_size = 6;
  int hand1_size = 6;
  int hand2_size = 6;
  int hand3_size = 6;

  vector<string> myHand;
  for (int i = 0; i < hand_size; ++i) {
    myHand.push_back(deck.at(i)); 
  }
  deck.erase(deck.begin(), deck.begin() + 6);
  
  vector<string> player1Hand;
  for (int i = 0; i < hand1_size; ++i) {
    player1Hand.push_back(deck.at(i)); 
  }
  deck.erase(deck.begin(), deck.begin() + 6);
  vector<string> player2Hand;
  for (int i = 0; i < hand2_size; ++i) {
    player2Hand.push_back(deck.at(i)); 
  }
  deck.erase(deck.begin(), deck.begin() + 6);
  
  vector<string> player3Hand;
  for (int i = 0; i < hand3_size; ++i) {
    player3Hand.push_back(deck.at(i)); 
  }
  deck.erase(deck.begin(), deck.begin() + 6);

	cout << " Pile has " << topCard << " <--- your turn" << endl << endl;
	
	bool GAME_OVER = false;
  START:  while (GAME_OVER == false) {
	
	vector <char> letters; 
  char numberToLetter;
  string menu;
  string option = "";
	for (unsigned int i = 0; i < hand_size; ++i) {
		numberToLetter = (char)('a' + i);
		letters.push_back(numberToLetter);
		menu = "  (";
		menu += numberToLetter;
		menu += ") ";
		option += menu + myHand.at(i); 
	}
  cout << option;

	char lastOption = (char)('a' + hand_size);
	letters.push_back(lastOption);
	string drawMenu = "  (";
	drawMenu += lastOption;
	drawMenu += ") draw";
	cout << drawMenu << endl;
	bool correct = false;
	string currentCard;
	char choice;
  char matchChoice;
	
	RESTART: while (correct == false) {
  cout << endl;
	cout << "Which one to play? ";
	cin >> choice; 
        
        if (find(letters.begin(), letters.end(), choice) == letters.end() && choice != '?') {
	        cout << "Invalid choice. Please type ";
	        for (int i = 0; i < letters.size(); ++i) {
	            cout << letters.at(i);
	            cout << ", ";
	            }
	            cout << "or ? in lowercase." << endl;
			correct = false;
			goto RESTART;
	    }
  for (int i = 0; i < hand_size; ++i) {
    matchChoice = (char)('a' + i);
    if (choice == matchChoice) currentCard = myHand.at(i);
  }
// if choice == draw 
	if (choice == letters.back()) {
   numberToLetter = (char)('a' + hand_size);
   letters.push_back(numberToLetter);
   	menu = "  (";
	menu += numberToLetter;
	menu += ") ";
	option += menu + deck.front();
	myHand.push_back(deck.front());
    deck.erase(deck.begin());
    if (deck.size() == 0) goto END; 
    cout << option;
    hand_size = hand_size + 1;
    lastOption = (char)('a' + hand_size);
	  letters.push_back(lastOption);
	  string drawMenu = "  (";
	  drawMenu += lastOption;
	  drawMenu += ") draw";
	  cout << drawMenu << endl;
    correct = false;
    goto RESTART;
  }
	if (choice == '?') {
    cout << "Player 1";
    vector <char> letters1; 
    string menu1;
    string option1 = "";
      for (unsigned int i = 0; i < hand1_size; ++i) {
		  numberToLetter = (char)('a' + i);
		  letters1.push_back(numberToLetter);
		  menu1 = "  (";
		  menu1 += numberToLetter;
		  menu1 += ") ";
		  option1 += menu1 + player1Hand.at(i); 
	}
    cout << option1 << endl;
     cout << "Player 2";
     	vector <char> letters2; 
     string menu2;
     string option2 = "";
      for (unsigned int i = 0; i < hand2_size; ++i) {
		  numberToLetter = (char)('a' + i);
		  letters2.push_back(numberToLetter);
		  menu2 = "  (";
		  menu2 += numberToLetter;
		  menu2 += ") ";
		  option2 += menu2 + player2Hand.at(i); 
	}
    cout << option2 << endl;
     cout << "Player 3";
     vector <char> letters3; 
     string menu3;
     string option3 = "";
      for (unsigned int i = 0; i < hand3_size; ++i) {
		  numberToLetter = (char)('a' + i);
		  letters3.push_back(numberToLetter);
		  menu3 = "  (";
		  menu3 += numberToLetter;
		  menu3 += ") ";
		  option3 += menu3 + player3Hand.at(i); 
	}
    cout << option3 << endl;
    correct = false;
     goto RESTART;
  }
	  if (find(letters.begin(), letters.end() - 1, choice) != letters.end() - 1) {     
	    while ( (currentCard.at(0) != topCard.at(0)) && (currentCard.at(1) != topCard.at(1)) && currentCard.at(1) != '8' ) {
	        cout << "Invalid choice. Please select another choice" << endl;
			correct = false;
			goto RESTART;
	}
      }
	if (currentCard.at(1) == '8') {
	    saveCard = currentCard;
		cout << "Which suit do you want? "; 
		string selectSuit; 
		cin >> selectSuit;
		    while (selectSuit != "H" && selectSuit != "C" && selectSuit != "D" && selectSuit != "S" ) {
			    cout << "Invalid suit. Please type H for hearts, C for clubs, D for diamonds, or S for spades." << endl;
			    cout << "Which suit do you want? "; 
			    cin >> selectSuit; 
		    }
		myHand.erase(remove(myHand.begin(), myHand.end(), currentCard), myHand.end());
	    currentCard = selectSuit.append("*");
	    topCard = currentCard;
	    cout << " Pile has " << currentCard << endl;
	    hand_size = hand_size - 1;
      if (hand_size == 0 || deck.size() == 0) goto END; 
	    letters.clear();
	    correct = false;
	    goto START1;
	    
	}
	    if (choice != letters.back() && choice != '?') {
	    cout << " Pile has " << currentCard << endl;
		}
		myHand.erase(remove(myHand.begin(), myHand.end(), currentCard), myHand.end());
		hand_size = hand_size - 1;
    if (hand_size == 0) goto END;

    if (hand_size == 0 || deck.size() == 0) {
    GAME_OVER = true; 
    break;
    }
  letters.clear(); 
	correct = false;
  topCard = currentCard; 
  GAME_OVER = false;
  goto START1;
	}

START1:
bool playableCard1 = false; 
bool found1 = false;

  for(int i = 0; i < player1Hand.size(); ++i) {
      if (player1Hand.at(i).at(0) == topCard.at(0) || player1Hand.at(i).at(1) == topCard.at(1)) {
        currentCard = player1Hand.at(i); 
      cout << "      Player 1 chose " << currentCard << endl;
      cout << "Pile has " << currentCard << endl;
      hand1_size = hand1_size - 1;
      if (hand1_size == 0 || deck.size() == 0) goto END;

      topCard = currentCard; 
      player1Hand.erase(remove(player1Hand.begin(), player1Hand.end(), currentCard), player1Hand.end());
      playableCard1 = true;
      goto START2; 
      }
  }

  for(int i = 0; i < player1Hand.size(); ++i) {
       if(player1Hand.at(i).at(1) == '8') {
         currentCard = player1Hand.at(i);
        cout << "      Player 1 chose " << currentCard << endl;
        topCard = currentCard; 
        found1 = true;
        break;
       }
  }
  if (found1 == true) {
               int numH = 0; int numC = 0; int numD = 0; int numS = 0; 
        for (int i = 0; i < player1Hand.size(); ++i) {
          if (player1Hand.at(i).at(0) == 'H')  numH += 1;
          if (player1Hand.at(i).at(0) == 'C')  numC += 1;
          if (player1Hand.at(i).at(0) == 'D')  numD += 1;
          if (player1Hand.at(i).at(0) == 'S')  numS += 1; 
        }
        int array[4] = {numH, numC, numD, numS};
        int max = 0; 
        for (int i = 0; i < 4; ++i) {
          if (array[i] > max) max = array[i]; 
        }
        string selectSuit; 
        if (numH == max) selectSuit = "H"; 
        if (numC == max) selectSuit = "C";
        if (numD == max) selectSuit = "D";
        if (numS == max) selectSuit = "S";
        cout << "      Player 1 declared suite " << selectSuit << endl;
        player1Hand.erase(remove(player1Hand.begin(), player1Hand.end(), currentCard), player1Hand.end());
        currentCard = selectSuit.append("*");
        cout << "Pile has " << currentCard << endl;
        	    hand1_size = hand1_size - 1;
              if (hand1_size == 0 || deck.size() == 0) goto END;
        topCard = currentCard; 
        hand1_size -= 1; 
        playableCard1 = true;
        goto START2; 
  }

while (playableCard1 == false) {
  player1Hand.push_back(deck.front()); 
  hand1_size += 1;
  deck.erase(deck.begin()); 
  cout << "      Player 1 drawing..." << endl;
  if (player1Hand.back().at(0) == topCard.at(0) || player1Hand.back().at(1) == topCard.at(1)) {
    currentCard = player1Hand.back(); 
    player1Hand.erase(player1Hand.end());
    cout << "      Player 1 chose " << currentCard << endl;
    player1Hand.erase(remove(player1Hand.begin(), player1Hand.end(), currentCard), player1Hand.end());
    cout << "Pile has " << currentCard << endl;
    hand1_size = hand1_size - 1;
    if (hand1_size == 0 || deck.size() == 0) goto END;
    topCard = currentCard; 
    playableCard1 = true;
    goto START2;
  }
  else playableCard1 = false; 
} 

START2: 
bool playableCard2 = false;
bool found2 = false; 

  for(int i = 0; i < player2Hand.size(); ++i) {
    if(player2Hand.at(i).at(0) == topCard.at(0) || player2Hand.at(i).at(1) == topCard.at(1)) {
      currentCard = player2Hand.at(i);
      cout << "      Player 2 chose " << currentCard << endl;
      cout << "Pile has " << currentCard << endl;
      hand2_size = hand2_size - 1;
      if (hand2_size == 0 || deck.size() == 0) goto END;
      topCard = currentCard; 
      player2Hand.erase(remove(player2Hand.begin(), player2Hand.end(), currentCard), player2Hand.end());
      playableCard2 = true;
      goto START3; 
      }
    }

    for (int i = 0; i < player2Hand.size(); ++i) {
       if(player2Hand.at(i).at(1) == '8') {
         currentCard = player2Hand.at(i);
        cout << "      Player 2 chose " << currentCard << endl; 
        topCard = currentCard;
        found2 = true;
        break;
       }
  }
  if (found2 == true) {
        int numH = 0; int numC = 0; int numD = 0; int numS = 0; 
        for (int i = 0; i < player2Hand.size(); ++i) {
          if (player2Hand.at(i).at(0) == 'H')  numH += 1;
          if (player2Hand.at(i).at(0) == 'C')  numC += 1;
          if (player2Hand.at(i).at(0) == 'D')  numD += 1;
          if (player2Hand.at(i).at(0) == 'S')  numS += 1; 
        }
        int array[4] = {numH, numC, numD, numS};
        int max = 0; 
        for (int i = 0; i < 4; ++i) {
          if (array[i] > max) max = array[i]; 
        }
        string selectSuit; 
        if (numH == max) selectSuit = "H"; 
        if (numC == max) selectSuit = "C";
        if (numD == max) selectSuit = "D";
        if (numS == max) selectSuit = "S";
        cout << "      Player 2 declared suite " << selectSuit << endl;
        player2Hand.erase(remove(player2Hand.begin(), player2Hand.end(), currentCard), player2Hand.end());
        currentCard = selectSuit.append("*");
        cout << "Pile has " << currentCard << endl;
        topCard = currentCard; 
        hand2_size -= 1;
        if (hand2_size == 0 || deck.size() == 0) goto END;
        playableCard2 = true;
        goto START3;
      }

while (playableCard2 == false) {
  player2Hand.push_back(deck.front()); 
  hand2_size += 1;
  deck.erase(deck.begin()); 
  cout << "      Player 2 drawing..." << endl;
  if (player2Hand.back().at(0) == topCard.at(0) || player2Hand.back().at(1) == topCard.at(1)) {
    currentCard = player2Hand.back(); 
    player2Hand.erase(player2Hand.end());
    cout << "      Player 2 chose " << currentCard << endl;
    player2Hand.erase(remove(player2Hand.begin(), player2Hand.end(), currentCard), player2Hand.end());
    cout << "Pile has " << currentCard << endl;
    hand2_size -= 1;
    if (hand2_size == 0 || deck.size() == 0) goto END;
    topCard = currentCard; 
    playableCard2 = true;
    goto START3;
  }
  else playableCard2 = false; 
}
START3:
bool playableCard3 = false;  
bool found3 = false;

  for(int i = 0; i < player3Hand.size(); ++i) {
      if (player3Hand.at(i).at(0) == topCard.at(0) || player3Hand.at(i).at(1) == topCard.at(1)) {
        currentCard = player3Hand.at(i); 
      cout << "      Player 3 chose " << currentCard << endl;
      cout << "Pile has " << currentCard << " <--- your turn" << endl << endl;
      hand3_size -= 1;
      if (hand3_size == 0 || deck.size() == 0) goto END;
      topCard = currentCard; 
      player3Hand.erase(remove(player3Hand.begin(), player3Hand.end(), currentCard), player3Hand.end());
      playableCard3 = true;
      goto START; 
      }
  }
  for (int i =0; i < player3Hand.size(); ++i) {
       if(player3Hand.at(i).at(1) == '8') {
         currentCard = player3Hand.at(i);
        cout << "      Player 3 chose " << currentCard << endl; 
        topCard = currentCard; 
        found3 = true;
        break;
       }
  }
  if (found3 == true) {
        int numH = 0; int numC = 0; int numD = 0; int numS = 0; 
        for (int i = 0; i < player3Hand.size(); ++i) {
          if (player3Hand.at(i).at(0) == 'H')  numH += 1;
          if (player3Hand.at(i).at(0) == 'C')  numC += 1;
          if (player3Hand.at(i).at(0) == 'D')  numD += 1;
          if (player3Hand.at(i).at(0) == 'S')  numS += 1; 
        }
        int array[4] = {numH, numC, numD, numS};
        int max = 0; 
        for (int i = 0; i < 4; ++i) {
          if (array[i] > max) max = array[i]; 
        }
        string selectSuit; 
        if (numH == max) selectSuit = "H"; 
        if (numC == max) selectSuit = "C";
        if (numD == max) selectSuit = "D";
        if (numS == max) selectSuit = "S";
        cout << "      Player 3 declared suite " << selectSuit << endl;
        player3Hand.erase(remove(player3Hand.begin(), player3Hand.end(), currentCard), player3Hand.end());
        currentCard = selectSuit.append("*");
        cout << "Pile has " << currentCard << endl;
        topCard = currentCard; 
        hand3_size -= 1; 
        if (hand3_size == 0 || deck.size() == 0) goto END;
        playableCard3 = true; 
        goto START;
  }

while (playableCard3 == false) {
  player3Hand.push_back(deck.front()); 
  hand3_size += 1;
  deck.erase(deck.begin()); 
  cout << "      Player 3 drawing..." << endl;
  if (player3Hand.back().at(0) == topCard.at(0) || player3Hand.back().at(1) == topCard.at(1)) {
    currentCard = player3Hand.back(); 
    player3Hand.erase(player3Hand.end());
    cout << "      Player 3 chose " << currentCard << endl;
    player3Hand.erase(remove(player3Hand.begin(), player3Hand.end(), currentCard), player3Hand.end());
    cout << "Pile has " << currentCard << " <--- your turn" << endl << endl;;
    hand3_size -= 1;
    if (hand3_size == 0 || deck.size() == 0) goto END;
    topCard = currentCard; 
    playableCard3 = true;
    goto START;
  }
  else playableCard3 = false;
}
	}
  END:
  if (hand_size == 0)  cout << "You won!" << endl << endl;
  if (hand1_size == 0) cout << "Player 1 won!" << endl << endl;
  if (hand2_size == 0) cout << "Player 2 won!" << endl << endl;
  if (hand3_size == 0) cout << "Player 3 won!" << endl << endl;
  if (deck.size() == 0) cout << "No more cards in deck!" << endl << endl;

    cout << "[ Final card distributions ]" << endl;
      char numberToLetter;
  string menu;
  string option = "";
  vector <char> letters; 
  cout << "Player 0";
	for (unsigned int i = 0; i < hand_size; ++i) {
		numberToLetter = (char)('a' + i);
		letters.push_back(numberToLetter);
		menu = "  (";
		menu += numberToLetter;
		menu += ") ";
		option += menu + myHand.at(i); 
	}
  cout << option << endl;
    cout << "Player 1";
    vector <char> letters1; 
    string menu1;
    string option1 = "";
      for (unsigned int i = 0; i < hand1_size; ++i) {
		  numberToLetter = (char)('a' + i);
		  letters1.push_back(numberToLetter);
		  menu1 = "  (";
		  menu1 += numberToLetter;
		  menu1 += ") ";
		  option1 += menu1 + player1Hand.at(i); 
	}
    cout << option1 << endl;

     cout << "Player 2";
     	vector <char> letters2; 
     string menu2;
     string option2 = "";
      for (unsigned int i = 0; i < hand2_size; ++i) {
		  numberToLetter = (char)('a' + i);
		  letters2.push_back(numberToLetter);
		  menu2 = "  (";
		  menu2 += numberToLetter;
		  menu2 += ") ";
		  option2 += menu2 + player2Hand.at(i); 
	}
    cout << option2 << endl;

     cout << "Player 3";
     vector <char> letters3; 
     string menu3;
     string option3 = "";
      for (unsigned int i = 0; i < hand3_size; ++i) {
		  numberToLetter = (char)('a' + i);
		  letters3.push_back(numberToLetter);
		  menu3 = "  (";
		  menu3 += numberToLetter;
		  menu3 += ") ";
		  option3 += menu3 + player3Hand.at(i); 
	}
    cout << option3 << endl;
}
