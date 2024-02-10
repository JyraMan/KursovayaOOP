#include <iostream>
using namespace std;

#include <Windows.h>
#include <thread>
#include <vector>

#define XPADDING 34
#define YPADDING 5

// Screen buffer class
//==============================================================

class Screen
{
public:

    Screen(int, int);

    const int screenWidth;
    const int screenHeight;


    wchar_t *screen;

    HANDLE hConsole;
    DWORD dwBytesWritten;   
};

Screen::Screen(int screenWidth, int screenHeight)
    : screenWidth(screenWidth), screenHeight(screenHeight)
{
    screen = new wchar_t[screenWidth * screenHeight];
    for (int i = 0; i < screenWidth * screenHeight; i++) screen[i] = L' ';
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    dwBytesWritten = 0;
}

// Tetromino Class
//==============================================================

class Tetromino
{
public:
    Tetromino(wstring, int, int, int);

    int y;
    int x;
    int rotation;

    wstring layout;

    int rotate(int, int);
};

Tetromino::Tetromino(wstring layout, int startingX, int startingY, int startingRotation)
    : layout(layout), y(startingY), x(startingX), rotation(startingRotation)
{}

int Tetromino::rotate(int x, int y)
{
    /*
    * Rotates piece layout
    * string based on given angle 
    * 'rotation'
    */
    switch (rotation % 4) {
        case 0: return y * 4 + x;          // 0 degress
        case 1: return 12 + y - (x * 4);   // 90 degress
        case 2: return 15 - (y * 4) - x;   // 180 degress
        case 3: return 3 - y + (x * 4);    // 270 degress
    }

    return 0;
}

// Playing Field Class
//==============================================================

class PlayingField
{
public:
    PlayingField(int, int);

    const int fieldWidth;
    const int fieldHeight;

    unsigned char *pField;

    bool doesPieceFit(Tetromino*, int, int, int);
};

PlayingField::PlayingField(int fieldWidth, int fieldHeight)
    : fieldWidth(fieldWidth), fieldHeight(fieldHeight), pField(nullptr)
{
    // Creating play field buffer
    pField = new unsigned char[fieldHeight * fieldWidth];
    for (int x = 0; x < fieldWidth; x++)
        for (int y = 0; y < fieldHeight; y++)
            // 0 characters are spaces and 9 are borders
            pField[y * fieldWidth + x] = (x == 0 || x == fieldWidth - 1 || y == fieldHeight - 1) ? 9 : 0;
}

bool PlayingField::doesPieceFit(Tetromino *tetromino, int rotation, int x, int y)
{
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++) {
            int pi = tetromino->rotate(px, py);
            int fi = (y + py) * fieldWidth + (x + px);
            if (x + px >= 0 && x + px < fieldWidth)
                if (y + py >= 0 && y + py < fieldHeight)
                    // if cell value != 0, it's occupied
                    if (tetromino->layout[pi] == L'X' && pField[fi] != 0)
                        return false;
        }
    return true;
}

// Game class
//==============================================================

class Tetris
{
public:
    Tetris(Screen*, PlayingField*, int);

    bool gameOver;

    int score;

    void draw();
    void checkLines();
    void computeNextState();
    void lockPieceOnField();
    void processInput();
    void synchronizeMovement();

private:
    int lines;
    int speed;
    int nextPiece;
    int pieceCount;
    int currentPiece;
    int speedCounter;

    bool key[4];
    bool forceDown;
    bool rotateHold;

    Screen *screenBuffer;
    Tetromino *tetromino[7];
    PlayingField *playingField;

    vector<int> fullLines;

};

Tetris::Tetris(Screen *screenBuffer, PlayingField *playingField, int speed) 
    : speed(speed), screenBuffer(screenBuffer), playingField(playingField)
{
    // Set game initial state
    score = 0;
    lines = 0;
    pieceCount = 0;
    speedCounter = 0;
    gameOver = false;
    forceDown = false;
    nextPiece = rand() % 7;
    currentPiece = rand() % 7;

    // Generate pieces
    int startingPieceX = playingField->fieldWidth / 2;
    tetromino[0] = new Tetromino(L"..X...X...X...X.", startingPieceX, 0, 0);
    tetromino[1] = new Tetromino(L"..X..XX...X.....", startingPieceX, 0, 0);
    tetromino[2] = new Tetromino(L".....XX..XX.....", startingPieceX, 0, 0);
    tetromino[3] = new Tetromino(L"..X..XX..X......", startingPieceX, 0, 0);
    tetromino[4] = new Tetromino(L".X...XX...X.....", startingPieceX, 0, 0);
    tetromino[5] = new Tetromino(L".X...X...XX.....", startingPieceX, 0, 0);
    tetromino[6] = new Tetromino(L"..X...X..XX.....", startingPieceX, 0, 0);

    rotateHold = true;
}

void Tetris::synchronizeMovement()
{
    // Timing game ticks
    this_thread::sleep_for(50ms);
    speedCounter++;
    forceDown = (speed == speedCounter);
}

void Tetris::processInput()
{
    // x27 = right arrow key
    // x25 = left arrow key
    // x28 = down arrow key
    for (int k = 0; k < 4; k++)
        key[k] = (0x8000 & GetAsyncKeyState((unsigned char) ("\x27\x25\x28Z"[k]))) != 0;

    // Handling input
    Tetromino *currentTetromino = tetromino[currentPiece];
    currentTetromino->x += (key[0] && playingField->doesPieceFit(currentTetromino, currentTetromino->rotation, currentTetromino->x + 1, currentTetromino->y)) ? 1 : 0;
    currentTetromino->x -= (key[1] && playingField->doesPieceFit(currentTetromino, currentTetromino->rotation, currentTetromino->x - 1, currentTetromino->y)) ? 1 : 0;
    currentTetromino->y += (key[2] && playingField->doesPieceFit(currentTetromino, currentTetromino->rotation, currentTetromino->x, currentTetromino->y + 1)) ? 1 : 0;

    if (key[3]) {
        currentTetromino->rotation += (rotateHold && playingField->doesPieceFit(currentTetromino, currentTetromino->rotation + 1, currentTetromino->x, currentTetromino->y)) ? 1 : 0;
        rotateHold = false;
    } else {
        rotateHold = true;
    }
}

void Tetris::computeNextState()
{
    if (forceDown) {
        Tetromino *currentTetromino = tetromino[currentPiece];
        if (playingField->doesPieceFit(currentTetromino, currentTetromino->rotation, currentTetromino->x, currentTetromino->y + 1)) {
            currentTetromino->y++;
        } else {
            lockPieceOnField();

            // Set up new piece
            currentPiece = nextPiece;
            nextPiece = rand() % 7;
            tetromino[currentPiece]->rotation = 0;
            tetromino[currentPiece]->y = 0;
            tetromino[currentPiece]->x = playingField->fieldWidth / 2;

            // Increse game speed every 10 tics
            pieceCount++;
            if (pieceCount % 10 == 0)
                if (speed >= 10) speed--;

            checkLines();

            score += 25;
            if (!fullLines.empty()) score += (1 << fullLines.size()) * 100;

            // Game over if it doesn't fit
            gameOver = !playingField->doesPieceFit(tetromino[currentPiece], tetromino[currentPiece]->rotation, tetromino[currentPiece]->x, tetromino[currentPiece]->y);

        }
        speedCounter = 0;
    }
}

void Tetris::lockPieceOnField()
{
    Tetromino *currentTetromino = tetromino[currentPiece];
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++)
            if (currentTetromino->layout[currentTetromino->rotate(px, py)] == L'X')
                // nCurrentPiece + 1 because 0 means empty spots in the playing field
                playingField->pField[(currentTetromino->y + py) * playingField->fieldWidth + (currentTetromino->x + px)] = currentPiece + 1;
}

void Tetris::checkLines()
{
    Tetromino *currentTetromino = tetromino[currentPiece];
    for (int py = 0; py < 4; py++) {
        if (currentTetromino->y + py < playingField->fieldHeight - 1) {
            bool bLine = true;
            for (int px = 1; px < playingField->fieldWidth; px++)
                // if any cell is empty, line isn't complete
                bLine &= (playingField->pField[(currentTetromino->y + py) * playingField->fieldWidth + px]) != 0;
            if (bLine) {
                // draw '=' symbols
                for (int px = 1; px < playingField->fieldWidth - 1; px++)
                    playingField->pField[(currentTetromino->y + py) * playingField->fieldWidth + px] = 8;
                fullLines.push_back(currentTetromino->y + py);
                lines++;
            }
        }
    }
}

void Tetris::draw()
{
    // Draw playing field
    for (int x = 0; x < playingField->fieldWidth; x++)
        for (int y = 0; y < playingField->fieldHeight; y++)
            //mapping playing field (' ', 1,..., 9) to Screen characters (' ', A,...,#)
            screenBuffer->screen[(y + YPADDING) * screenBuffer->screenWidth + (x + XPADDING)] = L" ABCDEFG=#"[playingField->pField[y * playingField->fieldWidth + x]];

    // Draw pieces
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++) {
            if (tetromino[currentPiece]->layout[tetromino[currentPiece]->rotate(px, py)] == L'X')
                // Drawing current piece ( n + ASCII code of character 'A') 0 -> A, 1 - > B, ...
                screenBuffer->screen[(tetromino[currentPiece]->y + py + YPADDING) * screenBuffer->screenWidth + (tetromino[currentPiece]->x + px + XPADDING)] = currentPiece + 65;
            if (tetromino[nextPiece]->layout[tetromino[nextPiece]->rotate(px, py)] == L'X')
                // Drawing next piece ( n + ASCII code of character 'A') 0 -> A, 1 - > B, ...
                screenBuffer->screen[(YPADDING + 3 + py) * screenBuffer->screenWidth + (XPADDING / 2 + px + 3)] = nextPiece + 65;
            else
                screenBuffer->screen[(YPADDING + 3 + py) * screenBuffer->screenWidth + (XPADDING / 2 + px + 3)] = ' ';

        }

    swprintf_s(&screenBuffer->screen[YPADDING * screenBuffer->screenWidth + XPADDING / 4], 16, L"SCORE: %8d", score);
    swprintf_s(&screenBuffer->screen[(YPADDING + 1) * screenBuffer->screenWidth + XPADDING / 4], 16, L"LINES: %8d", lines);
    swprintf_s(&screenBuffer->screen[(YPADDING + 4) * screenBuffer->screenWidth + XPADDING / 4], 13, L"NEXT PIECE: ");

    if (!fullLines.empty()) {
        WriteConsoleOutputCharacter(screenBuffer->hConsole, screenBuffer->screen, screenBuffer->screenWidth * screenBuffer->screenHeight, {0,0}, &screenBuffer->dwBytesWritten);
        this_thread::sleep_for(400ms);
        for (auto &v : fullLines)
            for (int px = 1; px < playingField->fieldWidth - 1; px++) {
                for (int py = v; py > 0; py--)
                    // clear line, moving lines above one unit down
                    playingField->pField[py * playingField->fieldWidth + px] = playingField->pField[(py - 1) * playingField->fieldWidth + px];
                playingField->pField[px] = 0;
            }
        fullLines.clear();
    }

    // Display Frame
    WriteConsoleOutputCharacter(screenBuffer->hConsole, screenBuffer->screen, screenBuffer->screenWidth * screenBuffer->screenHeight, {0,0}, &screenBuffer->dwBytesWritten);
}

int main(void){

    Screen *screenBuffer = new Screen(80, 30);
    PlayingField *playingField = new PlayingField(12, 18);
    Tetris *tetrisGame = new Tetris(screenBuffer, playingField, 20);

    // Main game loop
    while (!tetrisGame->gameOver) {
        // Timing
        tetrisGame->synchronizeMovement();
        // Input
        tetrisGame->processInput();
        // Logic
        tetrisGame->computeNextState();
        //Render Output
        tetrisGame->draw();
    }

    CloseHandle(screenBuffer->hConsole);
    cout << "Game Over! Score:" << tetrisGame->score << endl;
    system("pause");                                       

    return 0;
}