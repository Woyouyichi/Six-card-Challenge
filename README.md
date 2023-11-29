# Six-card-Challenge
Team Members

Li Chengpu (3036087236, GitHub: paojiaoLI)
Han Shicheng (3035973232, Github: Woyouyichi)

Description of the project:

Title: Six-Card challenge

Description:
This is a card-based game. Players and the computer will take turns drawing two cards, up to three rounds, and compare the final points and sizes. At the beginning of each round, both players can choose to raise or withdraw.

Rules:

-At the beginning of the game, the player is given an initial fund of 200 HKD. Each round of the game requires a cost of 10 HKD from the players' funds to participate.

-The player and the computer are dealt a total of 6 cards each, distributed in turns.

-The player has the option to raise or not raise the bet by pressing 'c' (continue) or 's' (stop), respectively. Each raise costs an additional 10 HKD from the player's fund.

-The computer's decision to raise or stop is determined by the computer1 function, which takes into account the points of the known cards.

-The game consists of multiple rounds, and the player and computer take turns deciding to raise or stop. The number of rounds is tracked by the NumRound variable. After each round, the result is calculated using the Resultfunction. The fund is adjusted based on the outcome of the round.

-The game continues as long as the player has more than 9 HKD in their fund and does not choose to exit by pressing 'N'.

-If the player's fund becomes less than or equal to 9 HKD, the game ends, and the player loses.

-The player is prompted to start the game by pressing 'Y' and can choose to continue playing the next round or exit the game by pressing 'N' at the end of each round.


Features：

Game initialization:
When the game starts, the player's fund is set to HKD 200 and is displayed on the screen.
Players can choose whether to start the game.

Licensing:
The Send_Card function is used to deal cards. Each time this function is called, a pair of cards will be sent to the player and the computer respectively.
The player and computer cards are gradually added until each person has 6 cards.

Raising decision:
Players can choose whether to raise a bet during each decision-making round.
The program prompts the player to make a raise selection and receives input from the player.
Players can press 'c' (continue) to raise or 's' (stop) not to raise.
The program records the number of raises and the player's choice.

Computer decision-making:
The computer1 function is used to determine whether the computer decides whether to raise based on the known card value.
Based on the current round and the known card points, the computer will evaluate the total points of the card and make decisions based on specific conditions.
If the card value falls below a certain threshold, the computer will choose to stop raising (returning 's'), otherwise it will choose to continue raising (returning 'c').

Results calculation and fund adjustment:
The Result function is used to calculate the results of each round and adjust the fund based on the results.
This function receives as parameters the player's and computer's cards, the number of raises, and the raise selection.
Based on the comparison of game rules and card points, it is determined whether the result of each round is a player victory, a computer victory or a draw.
Depending on the results, the fund will increase or decrease accordingly.

Game loop:
The game progresses through multiple rounds through loops.
The conditions in the loop determine whether the player's funds are sufficient to continue the game, and also check whether the player chooses to exit the game.
After each round, the results are calculated and the funds adjusted by calling the Result function.
The program will ask the player whether to continue to the next round and decide whether to continue the cycle based on the player's choice.

Input and output:
Games interact with players through input and output.
The output part uses cout statements to display game status information, raise tips, and result information to players.
The input part uses the cin statement to receive the player's raise selection and decision to continue the game.

Compilation and Execution Instructions

Download the ZIP containing the files, and extract it onto your desktop, or any other working directory.
In the terminal, navigate to the working directory containing the files, and run the command 'make sixcard'
Run the command './sixcard ' on the terminal to play the game.
