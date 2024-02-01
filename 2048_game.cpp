/*
Tekijät: Joonatan Linkola, Reko Tainio, Niklas Wall, Elias Elonheimo
Projekti: 2048-peli, ELEC-A4010 Sähköpaja, kevät 2024
Lähteet: alkuperäinen peli selaimessa: https://play2048.co/
*/



// ledien, nappien, yms. alustamista



// pelissä käytettyjen muuttujien alustamista

int board[4][4] = {0};
int gameIsWon = 0;  // 0 -> peli kesken, 1 -> peli voitettu
int gameIsLost = 0; // 0 -> peli kesken, 1 -> peli hävitty
// int score = 0; // jos halutaan kirjata scorea? 
// yms.

// pelissä käytetyt funktiot

void setup() { 

    // alussa 2 ruutua 
    spawnTile();
    spawnTile();
}

void loop() {
    handleInput();
}

void handleInput() {
    if (gameIsWon || gameIsLost) {
        gameIsOver();
    } else if (true /* painetaan "up" */) {
        moveUp();
    } else if (true /* painetaan "right" */) {
        moveRight();
    } else if (true /* painetaan "down" */) {
        moveDown();
    } else if (true /* painetaan "left" */) {
        moveLeft();
    }
}

// up, right, down, left toiminnallisuus
void moveUp() {

}

void moveRight() {
    
}

void moveDown() {
    
}

void moveLeft() {
    
}

// asettaa 2 tai 4 tyhjään ruutuun, esim. 80/20 tod.
void spawnTile() {

    srand(time(NULL));

    int row, col;
    do {
        row = rand() % 4;
        col = rand() % 4;
    } while (board[row][col] != 0);
    
    board[row][col] = (1 + (rand() % 2)) * 2;    

}

// yhdistää kaksi samannumeroista ruutua
void combineTiles() {

    if (true /* ruutu 2048 muodostuu */) {
        gameIsWon = 1;
    }
}

void gameIsOver() {
    if (gameIsWon) {
        // jotakin voittoa indikoivaa tapahtuu
    } else if (gameIsLost) {
        // jotakin häviötä indikoivaa tapahtuu
    }
}
