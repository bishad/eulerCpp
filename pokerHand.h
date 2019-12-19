//
// Created by Mehedi on 19-Dec-19.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#define royalflush 1
#define strightflush 2
#define  fourofakind 3
#define fullhouse 4
#define flush 5
#define stright 6
#define threeofakind 7
#define twopair 8
#define onepair 9
#define other 10
using namespace std;
struct Card {
    int value;
    string suit;
};
struct Hand {
    struct Card c[5];
    int coeffecient;
};
struct Hand playerOne[1000];
struct Hand playerTwo[1000];

int comp(struct Card a, struct Card b);

int tieBreak(struct Hand *h1, struct Hand *h2, int coefficient);

int coefficient(Hand *h);

void print(Hand *h) {
    for (int i = 0; i < 5; ++i) {
        cout << h->c[i].value << h->c[i].suit << "\t";
    }
}

//int main() {
//    int ans = 0;
//    string line;
//    ifstream myFile;
//    myFile.open("input.txt");
//    if (myFile.is_open()) {
//        while (getline(myFile, line)) {
//            for (int i = 0, j = 0; i < line.length(); ++i, ++j) {
//                if (i < 16) {
//                    if (line.at(i) != ' ') {
//                        switch (line.at(i)) {
//                            case 2:
//                                playerOne->c[j].value = 2;
//                                break;
//                            case 3:
//                                playerOne->c[j].value = 3;
//                                break;
//                            case 4:
//                                playerOne->c[j].value = 4;
//                                break;
//                            case 5:
//                                playerOne->c[j].value = 5;
//                                break;
//                            case 6:
//                                playerOne->c[j].value = 6;
//                                break;
//                            case 7:
//                                playerOne->c[j].value = 7;
//                                break;
//                            case 8:
//                                playerOne->c[j].value = 8;
//                                break;
//                            case 9:
//                                playerOne->c[j].value = 9;
//                                break;
//                            case 'T':
//                                playerOne->c[j].value = 10;
//                                break;
//                            case 'J':
//                                playerOne->c[j].value = 11;
//                                break;
//                            case 'Q':
//                                playerOne->c[j].value = 12;
//                                break;
//                            case 'K':
//                                playerOne->c[j].value = 13;
//                                break;
//                            case 'A':
//                                playerOne->c[j].value = 14;
//                                break;
//                            case 'S':
//                                playerOne->c[j].suit = "Spade";
//                                break;
//                            case 'C':
//                                playerOne->c[j].suit = "Club";
//                                break;
//                            case 'H':
//                                playerOne->c[j].suit = "Hearts";
//                                break;
//                            case 'D':
//                                playerOne->c[j].suit = "Diamond";
//                                break;
//                        }
//
//                    }
//                } else {
//                    if (line.at(i) != ' ') {
//                        switch (line.at(i)) {
//                            case 2:
//                                playerTwo->c[j].value = 2;
//                                break;
//                            case 3:
//                                playerTwo->c[j].value = 3;
//                                break;
//                            case 4:
//                                playerTwo->c[j].value = 4;
//                                break;
//                            case 5:
//                                playerTwo->c[j].value = 5;
//                                break;
//                            case 6:
//                                playerTwo->c[j].value = 6;
//                                break;
//                            case 7:
//                                playerTwo->c[j].value = 7;
//                                break;
//                            case 8:
//                                playerTwo->c[j].value = 8;
//                                break;
//                            case 9:
//                                playerTwo->c[j].value = 9;
//                                break;
//                            case 'T':
//                                playerTwo->c[j].value = 10;
//                                break;
//                            case 'J':
//                                playerTwo->c[j].value = 11;
//                                break;
//                            case 'Q':
//                                playerTwo->c[j].value = 12;
//                                break;
//                            case 'K':
//                                playerTwo->c[j].value = 13;
//                                break;
//                            case 'A':
//                                playerTwo->c[j].value = 14;
//                                break;
//                            case 'S':
//                                playerTwo->c[j].suit = "Spade";
//                                break;
//                            case 'C':
//                                playerTwo->c[j].suit = "Club";
//                                break;
//                            case 'H':
//                                playerTwo->c[j].suit = "Hearts";
//                                break;
//                            case 'D':
//                                playerTwo->c[j].suit = "Diamond";
//                                break;
//                        }
//
//                    }
//                }
//                if (j == 4)
//                    j = 0;
//            }
//            playerOne->coeffecient = coefficient(playerOne);
//            playerTwo->coeffecient = coefficient(playerTwo);
//            if (playerOne->coeffecient < playerTwo->coeffecient) {
//                ans++;
//            } else if(playerOne->coeffecient == playerTwo->coeffecient){
//                int ab=tieBreak(playerOne,playerTwo,playerOne->coeffecient);
//                if(ab==1)
//                    ans++;
//            }
//        }
//        myFile.close();
//    }
//    cout << "Ans :: " << ans << endl;
//    return 0;
//}


int coefficient(Hand *h) {
    int value = 0;
    sort(h->c, h->c + 5, comp);
    int cardValue[5];
    for (int i = 0; i < 5; ++i) {
        cardValue[i] = h->c[i].value;
    }

    if (h->c[0].suit == h->c[1].suit && h->c[1].suit == h->c[2].suit && h->c[3].suit == h->c[2].suit &&
        h->c[3].suit == h->c[4].suit) {
        if (h->c[0].value == 10 && h->c[4].value - h->c[0].value == 4) {
            value = royalflush;
        } else if (h->c[4].value - h->c[0].value == 4) {
            value = strightflush;
        } else {
            value = flush;
        }
    } else {
        if (h->c[0].value == h->c[1].value || h->c[1].value == h->c[2].value) {
            int x = count(cardValue, cardValue + 5, h->c[0].value);
            int y = count(cardValue, cardValue + 5, h->c[1].value);
            if (x == 4 || y == 4) {
                value = fourofakind;
            }
        } else if (h->c[0].value == h->c[1].value && h->c[3].value == h->c[4].value) {
            int x = count(cardValue, cardValue + 5, h->c[0].value);
            int y = count(cardValue, cardValue + 5, h->c[4].value);
            if ((x == 2 && y == 3) || ((x == 3 && y == 2))) {
                value = fullhouse;
            }
        } else if (h->c[4].value - h->c[0].value == 4) {
            value = stright;
        } else {
            int x = count(cardValue, cardValue + 5, h->c[0].value);
            int y = count(cardValue, cardValue + 5, h->c[2].value);
            int z = count(cardValue, cardValue + 5, h->c[4].value);
            int a = count(cardValue, cardValue + 5, h->c[1].value);
            int b = count(cardValue, cardValue + 5, h->c[3].value);
            if (x == 3 || y == 3 || z == 3) {
                value = threeofakind;
            } else if (a == 2 && b == 2) {
                value = twopair;
            } else if (a == 2 || b == 2 || x == 2 || y == 2 || z == 2) {
                value = onepair;
            } else {
                value = other;
            }
        }
    }
    return value;
}

int comp(struct Card a, struct Card b) {
    int x = a.value;
    int y = b.value;
    return x < y;
}

int tieBreak(struct Hand *h1, struct Hand *h2, int coefficient) {
    int ans = 0;
    int cardValueOne[5], cardValueTwo[5];
    for (int i = 0; i < 5; ++i) {
        cardValueOne[i] = h1->c[i].value;
        cardValueTwo[i] = h2->c[i].value;
    }
    switch (coefficient) {
        case 2: {
            ans = (h1->c[4].value < h2->c[4].value) ? 2 : 1;
            break;
        }
        case 3: {
            if(h1->c[2].value > h2->c[2].value){
                ans =1;
            } else{
                if (h1->c[2].value==h1->c[0].value){
                    //WORK HERE
                }
            }
            break;
        }
        case 4: {
            ans = (h1->c[2].value < h2->c[2].value) ? 2 : 1;
            break;
        }
        case 5: {
            ans = (h1->c[4].value < h2->c[4].value) ? 2 : 1;
            break;
        }
        case 6: {
            ans = (h1->c[4].value < h2->c[4].value) ? 2 : 1;
            break;
        }
        case 7: {
            ans = (h1->c[2].value < h2->c[2].value) ? 2 : 1;
            break;
        }
        case 8: {
            ans = (h1->c[3].value < h2->c[3].value) ? 2 : 1;
            break;
        }
        case 9: {
            int x = *adjacent_find(cardValueOne, cardValueOne + 5);
            int y = *adjacent_find(cardValueTwo, cardValueTwo + 5);
            ans = (x < y) ? 2 : 1;
            break;
        }
        default: {
            ans = (h1->c[4].value < h2->c[4].value) ? 2 : 1;
            break;
        }
    }
    return ans;
}