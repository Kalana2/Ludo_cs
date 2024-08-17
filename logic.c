Cell cells[52];
Player players[PLAYERCOUNT];

void playgroundSetup(){
    for(int i=0;i<52;i++){
        Cell *cell= &cells[i];
        cell->id=i;
        cell->blockCount= 0;
        cell->player = -1;
        cell->isEmpty=true;
        cell->isBlock=false;
    }
}

//set defaults to playerd
void playerSetup(Player players[PLAYERCOUNT]){

   //player names setup
   strcpy(players[0].name,"Yellow");
   strcpy(players[1].name,"Blue");
   strcpy(players[2].name,"Red");
   strcpy(players[3].name,"Green");

   unsigned short int startIndex=2;

    for(int i=0; i<4; i++){
        Player *player = &players[i];
        player->onplaying=0;
        player->startingPoint=startIndex;
        player->approchPoint=(startIndex+50)%52;
        player->homePices=0;
        player->isWin=false;

        for(int j=0;j<4;j++){
            Piece *piece =&player->pieces[j];
            piece->name = j+1;
            piece->position=0;
            piece->wice=1;
            //piece.stringPosition=0;
            //piece.approshCell=players[i].approchPoint;
            piece->isPlaying=false;
            piece->isStright=false;
            piece->isHome=false;
            piece->canIntoHome=false;
        }

        startIndex= (startIndex+13)%52;
    }
    //The red player has four (04) pieces named R1, R2, R3, and R4.
    for(int i=0; i<4; i++){
        Player *player = &players[i];
        printf("The %s player has four (04) pieces named",player->name);
        for(int j=0;j<4;j++){
            printf(" %c%d",player->name[0],j+1);
            if(j!=3)printf(",");
        }
        printf(".\n");
        
    }
    printf("\n");
    
}

unsigned short int toss(){
    bool toss= rand() % 2;
    if(toss==0){return -1;};
    return toss;
}

unsigned short int diceRolling(char name[]){
    int val = (1 + (rand() % 6));
	printf("%s Rolled %d\n",name,val);
	return val;
};

unsigned short int getFirstplayer(Player players[4]){
    short int curruntPlayer=0,previous=0;
    for(int i=0; i<4;i++){
        unsigned short int value =diceRolling(players[i].name);
        if (previous<value){
            curruntPlayer = i;
            previous= value;
        }
    }
    printf("\n%s player has the highest roll and will begin the game.\n\n",players[curruntPlayer].name); 
    printf("The order of a single round is ");
    for(int i=0;i<4;i++){
        printf("%s ",players[(curruntPlayer+i)%4].name);
        if(i==2) printf("and ");
    }
    printf("\b.\n\n");
    return curruntPlayer;
}

//display fuctions
void displayComesStartingPoint(char player[8],unsigned short int pieceName,unsigned short int onplaying){
    printf("%s player moves piece %c%d to starting point.\n",player,player[0],pieceName);
    printf("%s player now has %d/4 on pieces on the board and %d/4 pieces on the base.\n",player,onplaying,4-onplaying);
}

void displayMove(char player[8], unsigned short int pieceName, unsigned short int position, unsigned short int steps, short int wice){
    char direction [20];
    (wice==1)? strcpy(direction,"clockwise") : strcpy(direction,"counter-clockwise");
    printf("%s moves piece %d from location %d to %d by %d units in %s direction.\n",player,pieceName,position,position+steps,steps,direction);
}

void display(){}

bool comessToX(Player *player,Piece* piece,Cell *startingCell){
    if(!piece->isPlaying && !piece->isHome && startingCell->isEmpty){
        player->onplaying++;
        piece->isPlaying=true;
        //startingCell->isEmpty=false;
        displayComesStartingPoint(player->name,piece->name,player->onplaying);
        piece->wice=toss();
        return true;
    }
}

//currunt player index, playiny cellrttree 
/*
void capture(unsigned short int playerIndex ,unsigned short int cellId,unsigned short int steps,short int wice){
    unsigned short  int captureCount=0;
    unsigned short int pieceColsetToHomeIndex;
    Player *currentPlayer = &players[playerIndex];
    Player *tempPlayer;
    Cell *currentPiece = &cells[cellId];
    Piece pieceColsetToHome = NULL;
= ;//gonning to capture if can

    //in fifth round capture the piece first 4th rounds it check whats closet to home
    for(unsigned short int = 0;i<4; i++){
        tempPlayer=players[i];
        if(tempPlayer==curr)
    }

    for(unsigned short int i=0; i<5;i++){
        tempPlayer[playerIndex];
        if(tempPlayer==currentPlayer) continue;
        short int pieceIndex=0;
        for(unsigned short int j=0;j<4; j++){
            Piece *tempPiece= &tempPlayer->pieces[pieceIndex];
            Cell *nextCell=&cells[tempPiece->position];
            if(captureCount!=4 cell->id+(wice*steps)==tempPiece->position && currentPiece->blockCount>=nextCell->blockCount){
                captureCount++;
                printf("CanCapture");
                if(pieceColsetToHome->id > )

            }

            pieceIndex = (pieceIndex+1)%4;
        }
        playerIndex=(playerIndex+1)%4;
        if(captureCount > 0){

        }
    }*/
}

//yellow player behevious
void YellowPlayer(unsigned short int diceValue){
    
}

//red palyer behevious
void redPlayer(unsigned short int diceVal){
   Player *player  = &players[2];
   unsigned short int staringCellIndex = player->startingPoint;
   if (player->isWin) return; //check player status(win or not)
   
   //check player's piece in the board if not get piece into board
   if(player->onplaying == 0 && diceVal== 6 ){
        Cell *startingCell = &cells[player->startingPoint];
        for(unsigned short int i =1; i<4; i++){
            Piece *piece = &player->pieces[i];
            if (comessToX(player,  piece, startingCell)) return;
        }
        player->onplaying=true;
        return;
    }


    else if(player->onplaying > 0 && diceVal== 6 ){
        Cell *startingCell = &cells[player->startingPoint];
        for(unsigned short int i =1; i<4; i++){
            Piece *piece = &player->pieces[i];
            if (comessToX(player,  piece, startingCell)) return;
        }
    }
}
void movePices(Player player){

}




void logic(){
    playgroundSetup();
    playerSetup(players);

    unsigned int short plyerIndex = getFirstplayer(players);

    redPlayer(6);
    printf("Hello\n");

    //Player *player = &players[2];
    
}
