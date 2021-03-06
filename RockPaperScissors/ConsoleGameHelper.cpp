#include "ConsoleGameHelper.h"

//boardManager->loadPosFromFile(piece, col, row, playerNumber, pieceValidation);

void ConsoleGameHelper::increasePieceArray(char _validationPiece, int playerNumber)
{
	if (playerNumber == 1) {
		switch (_validationPiece)
		{
		case 'R':
			downCounterOfPiecesPlayer1[0]++;
			break;
		case 'P':
			downCounterOfPiecesPlayer1[1]++;
			break;
		case 'S':
			downCounterOfPiecesPlayer1[2]++;
			break;
		case 'B':
			downCounterOfPiecesPlayer1[3]++;
			break;
		case 'J':
			downCounterOfPiecesPlayer1[4]++;
			break;
		case 'F':
			downCounterOfPiecesPlayer1[5]++;
			break;
		default:
			break;
		}
	}
	else {
		switch (_validationPiece)
		{
		case 'R':
			downCounterOfPiecesPlayer2[0]++;
			break;
		case 'P':
			downCounterOfPiecesPlayer2[1]++;
			break;
		case 'S':
			downCounterOfPiecesPlayer2[2]++;
			break;
		case 'B':
			downCounterOfPiecesPlayer2[3]++;
			break;
		case 'J':
			downCounterOfPiecesPlayer2[4]++;
			break;
		case 'F':
			downCounterOfPiecesPlayer2[5]++;
			break;
		default:
			break;
		}
	}
}

void ConsoleGameHelper::consoleInsertPos(BoardManager * _boardManager, Player& p1, Player& p2)
{
	cout << "Both players, please enter.... " << endl;

	int pCol;
	int pRow;
	char presentationPiece;
	char validationPiece;
	int input_validation;

	int completed = 0;
	int completedPlayer = 0;
	GamePlayHelper::setCurrentPlayer(p1);

	// We need to move from one player to the other, inserting the peices, all of them deduing whatever he entred from the array and one he reaches zero he finish i can also print to the screen after each intercation how many pices of each kind he needs to put.
	while (!completed || !completedPlayer) {

		if (GamePlayHelper::getCurrentPlayer().getplayerNumber() == 1) {
			_boardManager->getBoardPrint().printBoard(*_boardManager, GamePlayHelper::getCurrentPlayer().getplayerNumber());
			cout << "Player1, please enter one of the following pieces left." << endl;
			cout << "Rocks left: " << downCounterOfPiecesPlayer1[0] << "." << endl;
			cout << "Papers left: " << downCounterOfPiecesPlayer1[1] << "." << endl;
			cout << "Scissors left: " << downCounterOfPiecesPlayer1[2] << "." << endl;
			cout << "Bombs left: " << downCounterOfPiecesPlayer1[3] << "." << endl;
			cout << "Joers left: " << downCounterOfPiecesPlayer1[4] << "." << endl;
			cout << "Flag left: " << downCounterOfPiecesPlayer1[5] << "." << endl;
			cout << "The game will not start until all pieces are played with." << endl;
			cin >> presentationPiece;
			cin >> pCol;
			cin >> pRow;
			validationPiece = presentationPiece;
			if (presentationPiece == 'J') {
				cin >> validationPiece;
			}
			system("cls");

			input_validation = validatePieceConsole(presentationPiece, pCol, pRow,1);

			if (input_validation) {

				//if player try to put 2 pices @ the same square we will get false here

				completedPlayer = _boardManager->loadPosFromFile(validationPiece, pCol, pRow, GamePlayHelper::getCurrentPlayer(), presentationPiece);

				if (completedPlayer == 1) {
					GamePlayHelper::setCurrentPlayer(p2);
				}
				else {
					increasePieceArray(presentationPiece, 1);
				}
			}
		}
		else {
			_boardManager->getBoardPrint().printBoard(*_boardManager, GamePlayHelper::getCurrentPlayer().getplayerNumber());
			cout << "Player2, please enter one of the following pieces left." << endl;
			cout << "Rocks left: " << downCounterOfPiecesPlayer2[0] << "." << endl;
			cout << "Papers left: " << downCounterOfPiecesPlayer2[1] << "." << endl;
			cout << "Scissors left: " << downCounterOfPiecesPlayer2[2] << "." << endl;
			cout << "Bombs left: " << downCounterOfPiecesPlayer2[3] << "." << endl;
			cout << "Joers left: " << downCounterOfPiecesPlayer2[4] << "." << endl;
			cout << "Flag left: " << downCounterOfPiecesPlayer2[5] << "." << endl;
			cout << "The game will not start until all pieces are played with." << endl;
			cin >> presentationPiece;
			cin >> pCol;
			cin >> pRow;
			validationPiece = presentationPiece;

			if (presentationPiece == 'J') {
				cin >> validationPiece;
			}
			system("cls");
			input_validation = validatePieceConsole(presentationPiece, pCol, pRow, 2);

			if (input_validation) {

				//if player try to put 2 pices @ the same square we will get false here
				completedPlayer = _boardManager->loadPosFromFile(validationPiece, pCol, pRow, GamePlayHelper::getCurrentPlayer(), presentationPiece);

				if (completedPlayer == 1) {
					GamePlayHelper::setCurrentPlayer(p1);
				}
				else {
					increasePieceArray(presentationPiece, 2);
				}
			}
		}
		if (checkIfFinsihedLoading()) {
			completed = 1;
		}
	}
}

ConsoleGameHelper::ConsoleGameHelper(){}

ConsoleGameHelper::~ConsoleGameHelper()
{
}

bool ConsoleGameHelper::validatePieceConsole(char _validationPiece, int pCol, int pRow, int playerNumber)
{

	if ( !((pCol <= 10 && pCol >= 1) && (pRow <= 10 && pRow >= 1)) ) {
		cout << "Incorrect colum or row inserted, please try again." << endl;
		return 0;
	}

	if (playerNumber == 1) {
		if (!(validatePieceChar(_validationPiece, 1))) {
			return 0;
		}
		else {
			return 1;
		}

	}
	else {
		if (!(validatePieceChar(_validationPiece, 2))) {
			return 0;
		}
		else {
			return 1;
		}
	}

	
}

bool ConsoleGameHelper::validatePieceChar(char _validationPiece, int _playerNumber)
{

	bool status = 1;

	if (_playerNumber == 1) {
		switch (_validationPiece)
		{
		case 'R':
			downCounterOfPiecesPlayer1[0]--;
			break;
		case 'P':
			downCounterOfPiecesPlayer1[1]--;
			break;
		case 'S':
			downCounterOfPiecesPlayer1[2]--;
			break;
		case 'B':
			downCounterOfPiecesPlayer1[3]--;
			break;
		case 'J':
			downCounterOfPiecesPlayer1[4]--;
			break;
		case 'F':
			downCounterOfPiecesPlayer1[5]--;
			break;
		default:
			cout << "incorrect piece entered or Joker format, please try again" << endl;
			status = 0;
		}
	}
	else {
		switch (_validationPiece)
		{
		case 'R':
			downCounterOfPiecesPlayer2[0]--;
			break;
		case 'P':
			downCounterOfPiecesPlayer2[1]--;
			break;
		case 'S':
			downCounterOfPiecesPlayer2[2]--;
			break;
		case 'B':
			downCounterOfPiecesPlayer2[3]--;
			break;
		case 'J':
			downCounterOfPiecesPlayer2[4]--;
			break;
		case 'F':
			downCounterOfPiecesPlayer2[5]--;
			break;
		default:
			cout << "incorrect piece entered or Joker format, please try again" << endl;
			status = 0;
		}
	}


		for (int i = 0; i <= 5; i++) {
			if (downCounterOfPiecesPlayer1[i] < 0 || downCounterOfPiecesPlayer2[i] < 0) {
				cout << "Too many pieces of the same kind, please try again" << endl;
				cout << endl;
				if (downCounterOfPiecesPlayer1[i] <= 0) {
					downCounterOfPiecesPlayer1[i]++;
				}
				else if (downCounterOfPiecesPlayer1[i] <= 0) {
					downCounterOfPiecesPlayer2[i]++;
				}
				status = 0;
			}

		}
	return status;
}

bool ConsoleGameHelper::checkIfFinsihedLoading()
{
	int counter = 0;

	for (int i = 0; i <= 5; i++) {
		if (downCounterOfPiecesPlayer1[i] == 0 && downCounterOfPiecesPlayer2[i] == 0) {
			counter++;
		}
	}

	return counter == 6 ? TRUE:FALSE;
}

void ConsoleGameHelper::readMoveFileFromConsole(BoardManager * boardManager, int & _weGotAWinner, Player& p1, Player& p2)
{
	int moveAndJockerData[6] = { -1,-1,-1,-1,-1,-1 };
	char jokerPresentationChange;
	int completedPlayer = 1;
	int input_validation;
	char jokerNewPres = -1;
	bool continoue;

	while (_weGotAWinner == -1 || completedPlayer) {
		if (GamePlayHelper::getCurrentPlayer().getplayerNumber() == 1) {
			jokerPresentationChange = 'G';
			continoue = 1;
			completedPlayer = 1;
			boardManager->getBoardPrint().printBoard(*boardManager, GamePlayHelper::getCurrentPlayer().getplayerNumber());
			while (continoue) {
				cout << "Player1, Do you want to change Joker presentiation? Y/N: ";
				cin >> jokerPresentationChange;
				if (jokerPresentationChange == 'N' || jokerPresentationChange == 'Y') {
					continoue = 0;
				}
				else {
					cout << "Invalid Input!" << endl;
				}
			}
			system("cls");
			boardManager->getBoardPrint().printBoard(*boardManager, GamePlayHelper::getCurrentPlayer().getplayerNumber());
			cout << "Player 1, please move... ";
			cin >> moveAndJockerData[0];
			cin >> moveAndJockerData[1];
			cin >> moveAndJockerData[2];
			cin >> moveAndJockerData[3];
			if (jokerPresentationChange == 'N') {
				moveAndJockerData[4] = -1;
				moveAndJockerData[5] = -1;
			}
			else {
				cin >> jokerNewPres;
				cin >> jokerNewPres;
				cin >> moveAndJockerData[4];
				cin >> moveAndJockerData[5];
				cin >> jokerNewPres;
			}

			input_validation = validataeMoveConsole(moveAndJockerData, jokerPresentationChange, jokerNewPres);
			if (input_validation) {
				completedPlayer = boardManager->checkMovePiece(moveAndJockerData, GamePlayHelper::getCurrentPlayer().getplayerNumber(), jokerNewPres, _weGotAWinner);
			}
			system("cls");
			if (completedPlayer == 0) {
				GamePlayHelper::setCurrentPlayer(p2);
			}
			else {
				cout << "Error" << endl;
			}
		}
		else {
			jokerPresentationChange = 'G';
			continoue = 1;
			completedPlayer = 1;
			boardManager->getBoardPrint().printBoard(*boardManager, GamePlayHelper::getCurrentPlayer().getplayerNumber());
			while (continoue) {
				cout << "Player2, Do you want to change Joker presentiation? Y/N: ";
				cin >> jokerPresentationChange;
				if (jokerPresentationChange == 'N' || jokerPresentationChange == 'Y') {
					continoue = 0;
				}
				else {
					cout << "Invalid Input!" << endl;
				}
			}
			system("cls");
			boardManager->getBoardPrint().printBoard(*boardManager, GamePlayHelper::getCurrentPlayer().getplayerNumber());
			cout << "Player 2, please move... ";
			cin >> moveAndJockerData[0];
			cin >> moveAndJockerData[1];
			cin >> moveAndJockerData[2];
			cin >> moveAndJockerData[3];
			if (jokerPresentationChange == 'N') {
				moveAndJockerData[4] = -1;
				moveAndJockerData[5] = -1;
			}
			else {
				cin >> jokerNewPres;
				cin >> jokerNewPres;
				cin >> moveAndJockerData[4];
				cin >> moveAndJockerData[5];
				cin >> jokerNewPres;
			}

			input_validation = validataeMoveConsole(moveAndJockerData, jokerPresentationChange, jokerNewPres);

			if (input_validation) {
				completedPlayer = boardManager->checkMovePiece(moveAndJockerData, GamePlayHelper::getCurrentPlayer().getplayerNumber(), jokerNewPres, _weGotAWinner);
			}
			system("cls");
			if (completedPlayer == 0) {
				GamePlayHelper::setCurrentPlayer(p1);
			}
			else {
				cout << "Error" << endl;
			}
		}

		for (int i = 0; i < 6; i++) {
			moveAndJockerData[i] = -1;
		}
	}
}

bool ConsoleGameHelper::validataeMoveConsole(int * _arr, char _jokerPresentationChange, char _jokerNewPres)
{
	bool status = 1;
	
	if (!((_arr[0] <= 10 && _arr[0] >= 1) && (_arr[1] <= 10 && _arr[1] >= 1))) {
		cout << "Incorrect colum or row inserted, please try again." << endl;
		status = 0;
	}

	if (!((_arr[3] <= 10 && _arr[3] >= 1) && (_arr[2] <= 10 && _arr[2] >= 1))) {
		cout << "Incorrect colum or row inserted, please try again." << endl;
		status = 0;
	}

	if (!(GamePlayHelper::checkMoveApplicable(_arr))) {
		status = 0;
	}

	if (_jokerPresentationChange == 'Y') {
		if (!((_arr[4] <= 10 && _arr[4] >= 1) && (_arr[5] <= 10 && _arr[5] >= 1))) {
			cout << "Incorrect colum or row inserted, please try again." << endl;
			status = 0;
		}
		if (!checkPiece(_jokerNewPres)) {
			status = 0;
		}
	}
	if ( !(GamePlayHelper::checkMoveApplicable(_arr))) {
		status = 0;
	}
	return status;
}

bool ConsoleGameHelper::checkPiece(char piece) {

	if (piece == 'R' || piece == 'B' || piece == 'P' || piece == 'S') {
		return true;
	}
	else
		return false;
}