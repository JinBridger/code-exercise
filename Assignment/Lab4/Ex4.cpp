#include <iostream>
using namespace std;

int main() {
    cout << "The Twelve days of Christmas" << endl << endl;
    for (int day = 1; day <= 12; day++) {
        cout << "On the ";
        switch (day) {
            case 1: {
                cout << "first";
                break;
            }
            case 2: {
                cout << "second";
                break;
            }
            case 3: {
                cout << "third";
                break;
            }
            case 4: {
                cout << "fourth";
                break;
            }
            case 5: {
                cout << "fifth";
                break;
            }
            case 6: {
                cout << "sixth";
                break;
            }
            case 7: {
                cout << "seventh";
                break;
            }
            case 8: {
                cout << "eighth";
                break;
            }
            case 9: {
                cout << "ninth";
                break;
            }
            case 10: {
                cout << "tenth";
                break;
            }
            case 11: {
                cout << "eleventh";
                break;
            }
            case 12: {
                cout << "twelfth";
                break;
            }
            default: {
                cout << "Never here!";
                break;
            }
        }
        cout << " day of Christmas\nmy true love sent to me:" << endl;
        if (day == 1) {
            cout << "A Partridge in a Pear Tree" << endl << endl;
            continue;
        }
        switch (day) {
            case 12: {
                cout << "12 Drummers Drumming" << endl;
            }
            case 11: {
                cout << "Eleven Pipers Piping" << endl;
            }
            case 10: {
                cout << "Ten Lords a Leaping" << endl;
            }
            case 9: {
                cout << "Nine Ladies Dancing" << endl;
            }
            case 8: {
                cout << "Eight Maids a Milking" << endl;
            }
            case 7: {
                cout << "Seven Swans a Swimming" << endl;
            }
            case 6: {
                cout << "Six Geese a Laying" << endl;
            }
            case 5: {
                cout << "Five Golden Rings" << endl;
            }
            case 4: {
                cout << "Four Calling Birds" << endl;
            }
            case 3: {
                cout << "Three French Hens" << endl;
            }
            case 2: {
                cout << "Two Turtle Doves" << endl;
            }
            case 1: {
                cout << "and a Partridge in a Pear Tree" << endl;
                break;
            }
            default: {
                cout << "Never here!";
                break;
            }
        }
        cout << endl;
    }
    return 0;
}