# PRESIDENT(SCUM) GAME
## Hackathon 2: Group 26
Members: 
- Andrew Tee Wei Xiong 164761
- Stelly Tan Xin Mei 164904
- Teh Hong Jun 164723

## Table Of Content
- Game Description 
- Why Play Our Game? 
- Game Rules 
- Game Logic 
- Object-Oriented Based Game
- Linked Lists as Core Data Structure
- Previews of The Game
- A Quick Demo of Our Game

## Game Description
Welcome to the thrilling and strategic card game "President(Scum)"! Get ready to put your card-playing skills to the test and aim for the prestigious title of President in each round. Gather your friends and let the battle for dominance begin! In this game, only a deck of 52 playing cards and a group of enthusiastic players are needed. With 4 or more participants, the competition will be fierce, but don't worry, the rules are easy to grasp, even for newcomers.


The cards are dealt out evenly among the players, ensuring everyone has a fair chance at victory. Remember, if there are any leftover cards, they won't be used in the game. Now, it's time to kick off the action. Player 1 takes the lead, setting the pace for the rest of the game. Each player will take their turn based on their number, unleashing their cunning moves on the table.


Here's the key to success: you must play cards that outrank the previous player's move. If you can't surpass their play or decide to hold back, passing is always an option. But choose wisely, for the tides of fortune can turn in an instant.Keep an eye out for the mighty 2's! When played, they have the power to reset the round and allow the player to start anew. It doesn't matter if the 2 is lower-ranked; it's a wild card that can change the course of the game during your turn.


Now, let's talk about the hierarchy of plays. Single cards can be trumped by higher-ranking cards, pairs have the upper hand against singles, and triples leave pairs and singles in their wake. But beware the bombs - four cards of the same rank! They reign supreme and can only be conquered by even mightier bombs.As the rounds progress, players strive to shed their cards and achieve the glorious status of President. The first player to empty their hand claims this coveted title, while the last player to get rid of their cards will be known as the Scum. It's all about timing, strategy, and a bit of luck. But remember, the President holds a special advantage. They get to kick off each round, dictating the flow of the game and putting their opponents on the back foot.


The battle for supremacy continues for multiple rounds, as players vie for the top position. How long will your reign as President last? Can you outsmart your opponents and secure victory in each round? Only time will tell!

## Why Play Our Game?

"President(Scum)" is not just any ordinary card game—it's a remarkable blend of fun, strategy, and friendly competition that will have you and your friends on the edge of your seats! As you dive into the gameplay, you'll quickly realize that it's not only about making wise decisions on how to strategically discard your cards, but also about employing clever tactics to prevent your friends from triumphing before you do.Each turn presents you with an exhilarating challenge: Should you play your highest-ranking card now, or save it for a critical moment when victory is within reach? With every move, you'll need to assess the current state of the game, analyze your opponents' plays, and carefully consider your options. It's a thrilling mental exercise that keeps you engaged and on your toes throughout the entire game.

But "President(Scum)" is not just about individual skill—it's about the social experience and shared moments with your friends. Picture yourselves gathered around a table, laughing, teasing, and strategizing as you strive to outsmart one another. The game sparks lively conversations, friendly banter, and memorable interactions that deepen your bonds and create lasting memories. What's even more exciting is the element of luck that adds an unpredictable twist to the game. As you shuffle the cards and deal them out, you can never be sure who will have the upper hand. Will you be the one blessed by fortune, or will luck favor someone else? The anticipation builds with each round, creating an atmosphere of suspense and excitement that heightens the overall gaming experience.

And here's the cherry on top: "President(Scum)" offers a fantastic opportunity to add some real-life stakes to the game. If you're feeling adventurous, why not introduce a friendly wager? The winner could earn the privilege of having a meal bought by the loser, adding an extra layer of excitement and motivation to emerge victorious. It's a chance to bring a touch of real-world consequences into the game, making every play even more meaningful and rewarding.

## Game Rules
#### Number of players: President is typically played with 4 or more players, although it can be played with as few as 3 players.

#### Deck of cards: A standard deck of 52 playing cards is used. The ranking of cards, from highest to lowest, is as follows: 2, A, K, Q, J, 10, 9, 8, 7, 6, 5, 4, 3.

#### Objective: The objective of the game is to be the first player to get rid of all their cards and become the President in the next round.

### Gameplay:

The dealer shuffles the deck and deals the entire deck of cards equally among the players. If there are leftover cards, they are not used in the game and will be left out.

Player 1 will start the game. 

Players take turns by their number. On your turn, you must play a higher-ranking card or set of cards than the previous player's play, or pass if you don't have a higher-ranking play or choose not to play one.

When one or more 2s are played by a player, the player starts a new round and can choose to start with any card(s). 
Please note that when 2 is played, it does not need to be higher ranked than the current card(s) but can only be played during your turn. 

### The ranking of plays is as follows:

- Single cards: Higher-ranking cards beat lower-ranking cards.
- Pairs: Two cards of the same rank beat single cards.
- Triples: Three cards of the same rank beat pairs and single cards.
- Bombs: Four cards of the same rank (e.g., four Aces) beat all other plays. Bombs can only be beaten by higher-ranked bombs.

Once a player plays a higher-ranking card or set of cards, the next player must play an even higher-ranking play or pass. If all players pass consecutively, the last player who played a card(s) gets to start a new round with any card(s) they choose.

The first player to get rid of all their cards becomes the President for the next round and the last player to get rid of their cards becomes the Scum.The President gets the advantage of starting each round.The game continues for multiple rounds until players decide to stop. 

## Game Logic

#### The game logic is implemented in the PlayRounds function of PresidentGame.

The output card validation mainly happens in a while loop where it has one variable, validDiscard. This variable checks whether the outputted card is a valid card, it set this bool variable to false whenever the players tried to output a card that is not in the deck, the pairing cards are not in the same rank, same card is chosen multiple times, the outputted card is having less card than the current card, the outputted card is smaller than the previous card. It then quits the respective loop and goes back to the while loop for validation. Validation happens in the functions below in order:

![Untitled Diagram drawio](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/7c400d9c-1d27-4bc5-b9f9-76b7abf97836)

If the value = “pass”, the current player is passed. The consecutivePass counter is increased. The nextRoundFlg is set as true, and the validDiscard is set as true. If all players passed, the currentCard is set as 0 and the currentPlayer can choose to output any card again.


## Object-Oriented Based Game

The code of the President(Scum) game defined three classes: Player, CardDeck, and PresidentGame. These classes encapsulate data and behavior related to players, card decks, and the game itself. The data member of class Player is the CardNode, which defines the linked list of cards that players owned. This member functions simulate the ability of the players such as below:
- AddCard - simulates the players add the card to her/his own hands when distributed from the card deck
- RemoveCard - simulates the players discarding the card from her/his hands 
- PrintHand - simulates the players looking at his/her cards on hands
- HasCard - simulates the players checking whether she/he has the card
- HasSameRank - simulates the players checking whether the cards that she/he choosing are having the same rank
- HasDifferentSuit - simulates the players choosing different card of same rank
- IsEmpty - simulates whether the hands of the players is empty
- GetSize - simulates the players counting the card that is left on hands

The data member of class CardDeck is Card, which represents the linked list of decks of full poker cards. The member function GenerateShuffledDeck is a function that generates the deck of cards with ranks from 2 to 10 and includes J, K, Q, A, much like the poker card that we have in real-life, just that the suit is in !, @, #, $. After it generates the deck, the deck is then shuffled using Fisher-Yates shuffle algorithm. This simulates the card shuffling in real life. It then passed the cards to the players evenly, with the leftover cards being discarded. This is then passed to the players in class Players using the AddCard functions. The process is done by passing as parameter, where the players object is passed into this DistributedDeck function, much like in real life, where we provide how many players to the card distributor to distribute the deck. 

The data members of class PresidentGame are as follows: numPlayers, currentPlayer, roundFinished, currentCard, cardsDiscarded, previousCardCounter, consecutivePass, ranking, playerOrder and playerName. All these members are declared as private members as this information is only important within this class, where they define the process of the game. It should not be known or handled by other classes. 
- numPlayer - keep the number of players
- currentPlayer - keep track of player that is playing
- roundFinished - check whether the round is done
- currentCard - keep track of the card that is successfully discarded
- previousCardCounter - keep track of how many cards was discarded
- consecutivePass - to acknowledge whether everyone has passed
- ranking - keep the rank of players
- playerOrder - record the order of players
- playerName - keep the players’ Name

As clearly shown, every information stated is only important in this class, where the game process is defined. It has three main member functions which are introduction, which serves as the landing page of the game, StartGame, where it sets the states for each round of games and PlayRounds functions, where all the games logic is written. It also has a member, CheckRoundCompletion, to check whether the round is completed. 

In this code, encapsulation is practiced as the classes encapsulate data and methods by defining private and public access specifiers. Private data and methods are encapsulated within the class and can only be accessed by other members of the same class that perform specific tasks that serves for respective objects, such as the private member of class PresidentGame, currentCard is only important when the game is played, hence it is not accessed by the Player object or the CardDeck object. Public methods provide an interface to interact with the objects of the class. For example, the AddCard and RemoveCard provide a function for the CardDeck object to add the card for the Player objects. This ensures that the data can only be accessed and modified using the defined methods, providing better control and abstraction.

Composition relationship happens when the Player object and CardDeck is declared as a private member of PresidentGame. This is because the game, PresidentGame, consists of players and card deck, which establish the relationship of has-a. This depicts the object-oriented concept where objects are created from the defined classes such that the instances of the Player class are created as players in the PresidentGame class, and the instance of the CardDeck class is created as a cardDeck in the PresidentGame class.

In short, this game has classes that  represent an abstraction of a real-world concept. The Player class represents a player in the game, the CardDeck class represents a deck of cards, and the PresidentGame class represents the game itself. The classes use private member variables to encapsulate and hide data. The classes interact with each other by passing objects as parameters to member functions or using objects to invoke member functions of other classes. 

## Linked List as Core Data Structure
In this game code, the card is the core element and we have chosen to implement the card as a linked list. A linked list is a data structure in computer science that consists of nodes, where each node contains a value and a pointer to the next node in the list. This structure allows for dynamic memory allocation and efficient insertion and removal of elements. We have defined a class, CardDeck, that has a structure Card to represent a card, which includes a value of the card as a string that is composed of one rank and one suit as well as a pointer to the next card in the list. Each card object is a node in the linked list.

When a new card is added to the game, a new instance of the card class is created and with the value set appropriately in the DistributedDeck function of CardDeck class. Then, the pointers are updated to link the new card with the existing cards in the list. For example, if the new card is being added to the end of the list, the pointer of the previous last card is updated to point to the new card. In this game, we do not just implement the append function where every card is added to the back of the list, but we have chosen to implement an insert function where every card is arranged in ascending order in the ASCII table to improve the readability of players when they wanted to choose the cards. 

Similarly, when a card is removed from the game, the pointer is adjusted to bypass the removed card and delete the chosen card. For instance, a card will be chosen by the player and the string of the card chosen is passed to the RemoveCard or RemoveCards function. The linked list structure allows for easy traversal of the cards to locate the desired card. The pointer of the previous card is then adjusted to point to the next card, effectively removing the chosen card.

This dynamic behavior of adding and removing cards aligns well with the nature of card playing where the number of cards is uncertain and may change over time. Linked lists allow for efficient insertion and removal operations because they only require updating the pointers, rather than shifting or resizing the entire data structure. By using a linked list to represent the cards, this game can easily accommodate the uncertain number of cards and their constant addition and removal. The linked list structure provides a convenient way to maintain the sequence of the cards and facilitates various card-related operations within the game. Hence, this choice allows for the dynamic management of the cards which cannot be achieved by other static data structures.


## Previews of the Game
### The landing page
![landing](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/b46db0df-acce-4937-90b8-9e60192d225a)

### The buffer screen to prevent your friend see your screen
![buffer](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/5a00f402-99c5-4dbe-be08-cfd659580324)

### The player screen
![playerScreen](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/1a539826-34b1-4e53-bc51-23a6a84cecba)

### The more card you discarded, the higher rank you are
![ranks](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/952e9a36-1457-4ac8-876a-9f75d574fca3)

### You can discard equal rank card
![image](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/97696c97-f575-4d50-9f85-703da5c45739)


### Error showing
![errorShowing](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/40015ec4-0ec9-4453-8950-43e3d15b14e5)

![error2](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/e7e289bf-2626-47b2-8a3d-3614548e58c6)

![error3](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/b34db028-9093-4440-8f71-ba77ee7c4cd6)


### When card 2 is discard, the round is cleared
![roundClear](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/f4f0eaea-acf8-4744-a5de-a240adf1905d)

### Ending
![ending](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/16789c22-a8e4-4e51-a35d-e938bef95bcd)

### Save and load function 
#### Save at the end of game
![Save](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/3460240a-b2eb-4f29-b572-3fc9bb868e0a)

#### Load at the starting of game
![load](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/985533d5-79fa-4a77-a0cb-177f29f63999)

#### It will then starts with the President of the saved history and follow the ranking of players until the Scum, being the last one to start from this game
![newRoundFirst](https://github.com/STELLY-02/G26_Hackathon2/assets/116903730/a76585cf-e7fb-429e-9f19-34b0666d1880)



## A Quick Demo of Our Game
[Click on this to watch the video]()
