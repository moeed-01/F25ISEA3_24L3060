//#include<iostream>
//#include <string>
//#include <conio.h>  // "Used for _getch()  to handle keyboard input"
//using namespace std;
//
//// upper to lower character
//char toLowerManual(char ch) {
//    if (ch >= 'A' && ch <= 'Z')
//        return ch + 32;
//    return ch;
//}
//
//// "Checks if the given string is a palindrome "
//bool isPalindrome(const string& text) {
//    int left = 0;
//    int right = static_cast<int>(text.length()) - 1;
//
//    while (left < right) {
//        char leftChar = toLowerManual(text[left]);
//        char rightChar = toLowerManual(text[right]);
//        if (leftChar != rightChar)
//            return false;
//        left++;
//        right--;
//    }
//    return true;
//}
//
//int main() {
//    cout << "=================================" << endl;
//    cout << "     Palindrome Checker Tool" << endl;
//    cout << "=================================" << endl;
//    cout << "Press esc anytime to quit." << endl << endl;
//
//    string input;
//
//    while (true) {
//        cout << "Enter a word: ";
//        input.clear();
//
//		// read input character by character and check for esc at same time
//        while (true) {
//            int ch = _getch();
//            if (ch == 27) { // "ESC key pressed"
//                cout << endl << "Program terminated successfully." << endl;
//                return 0;
//            }
//            if (ch == '\r') { // "Enter key pressed"
//                cout << endl;
//                break;
//            }
//            if (ch == '\b') { // "Backspace key pressed"
//                if (!input.empty()) {
//                    input.pop_back();
//                    cout << "\b \b";
//                }
//            } else if (isprint(ch)) {
//                input += static_cast<char>(ch);
//                cout << static_cast<char>(ch);
//            }
//        }
//
//        if (input.empty()) {
//            cout << "Please enter a valid word." << endl;
//            continue;
//        }
//
//        if (isPalindrome(input))
//            cout << " " << input << " is a Palindrome." << endl;
//        else
//            cout << " " << input << " is Not a Palindrome." << endl;
//
//        cout << "---------------------------------" << endl;
//        cout << "Press any key to continue or ESC to quit..." << endl;
//
//        int ch = _getch();
//        if (ch == 27) { // "ESC key pressed"
//            cout << endl << "Program terminated successfully." << endl;
//            break;
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

