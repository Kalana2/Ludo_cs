#pragma pack(1)

#define PLAYERCOUNT 4


typedef struct {
    unsigned short int name; //p1, p2, p3, p4
    unsigned short int position;
    unsigned short int wice;
    //unsigned short int stringPosition;
    //unsigned short int approshCell;
    unsigned short int blockId; //   
    //bool isBase;
    bool isPlaying;
    bool isCapture;
    bool isStright;
    bool isHome;
    bool canIntoHome; 
    
}Piece; 

typedef struct{
    char name[8];
    Piece pieces[4];
    unsigned short int startingPoint;
    unsigned short int onplaying;
    unsigned short int approchPoint;
    unsigned short int homePices;
    bool isWin; 
}Player;

typedef struct{
    unsigned short int id; 
    unsigned short int blockCount;  //number of block in cell
    short int player;  // yellow 0, blue 1,red 2, green 3
    bool isEmpty; //piece is empty 1;
    bool isBlock;   
}Cell;
