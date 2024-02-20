#include <iostream>
// #include <fstream> // файловый ввод и вывод
#include <string>
#include <ctime>  // псевдо-рандомные числа на основе текущего времени
#include <random> // для рандомайзера
using namespace std;

//const string RED = "\033[1;31m";
//const string YELLOW = "\033[1;33m";
//const string BLUE = "\033[1;34m";  
//const string RESET_COLOR = "\033[0m";

bool includeCharType(string answer, string characterType) { 
    return (answer == "Y" || answer == "y") && !characterType.empty(); // Y||y && не пустой(любой другой символ)
}

char intoRandomCharacter(string characters, mt19937& gen) {
    uniform_int_distribution<int> dist(0, characters.size() - 1); // char.size - 1 чтобы размер ограничить
    return characters[dist(gen)]; // возврат случайного индекса для замещения буквой, символом< числом
}

int calculate_password_strength(string password) {
    return password.length(); // Простая оценка силы пароля от длины
}

int main() {
    string answerUppercase, answerSymbols, answerNumbers;
    int minLength = 0, maxLength = 0; // limits 

    cout << "Enter the minimum password length: ";
    cin >> minLength;

    cout << "Enter the maximum password length: ";
    cin >> maxLength;

    if (minLength >= maxLength) {
        cerr << "Error: Min length should be less than the max." << endl;
        return 1; // Вывод ошибки
    }

    cout << "Include uppercase letters to your password? (Y/y for YES): ";
    cin >> answerUppercase;

    cout << "Include symbols to your password? : ";
    cin >> answerSymbols;
    
    cout << "Include numbers to your password? : ";
    cin >> answerNumbers;
    
    // тут создаем строку-контейнер для наших букв, цифр, символов
    string charContainer = "abcdefghijklmnopqrstuvwxyz"; // by default

    if (includeCharType(answerUppercase, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) // если пользователь нажал на Y, начинает заполнять контейнер
        charContainer += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    if (includeCharType(answerSymbols, "<>{}()[].,/';:_*&^%$#@!?№-"))
        charContainer += "<>{}()[].,/';:_*&^%$#@!?№-";
    
    if (includeCharType(answerNumbers, "1234567890"))
        charContainer += "1234567890";

    mt19937 generator(time(0)); // shuffle mechanism

    cout << "Your password_ ";
    string password;
    for (int i = 0; i < maxLength; i++) {
        char randomChar = intoRandomCharacter(charContainer, generator);
        cout << randomChar;
        password += randomChar;
    }

    cout << endl;
    
    // Simple password strength check
    int passwordStrength = calculate_password_strength(password);
    if (passwordStrength == 0 && passwordStrength <= 4) {
        cout << endl << "Password is weak";
    }
    else if ( passwordStrength > 4 && passwordStrength <= 7) {
        cout << endl << "Password is average";
    }
    else if (passwordStrength > 8) {
        cout << endl << "Password is strong";
    }

    return 0;
}

////

// #include <iostream>
// #include <fstream> // файловый ввод и вывод
// #include <string>
// #include <ctime>  // псевдо-рандомные числа на основе текущего времени
// #include <random> // для рандомайзера
// using namespace std;


// bool includeCharType(string answer, string characterType) { 
    // return (answer == "Y" || answer == "y") && !characterType.empty(); // Y||y && не пустой(любой другой символ)
// }

// char getRandomChar(string characters, mt19937& gen) { // код для рандомайзера позаимствован
//     uniform_int_distribution<int> dist(0, characters.size() - 1); // char.size - 1 чтобы размер ограничить
//     return characters[dist(gen)]; // возврат случайного индекса для замещения буквой, символом< числом
// }

// int calculatePasswordStrength(string password) {
//     return password.length(); // Простая оценка силы пароля от длины
// }

// int main() {
//     // открываем файл
//     ofstream fout("generated_password.txt");
//     // output file stream || file output
//     // файл generatedPword будет создан или перезаписан если есть в текущей директории программы 

//     if (!fout.is_open()) {
//         cerr << "Error opening the output file." << endl; // cerr Для вывода информации об ошибке на консоль
//         return 1; // вывод ошибки
//     }

//     string answerUppercase, answerSymbols, answerNumbers;
//     int minLength = 0, maxLength = 0; // limits 

//     cout << "Enter the minimum password length: ";
//     cin >> minLength;

//     cout << "Enter the maximum password length: ";
//     cin >> maxLength;

//     if (minLength >= maxLength) {
//         cerr << "Error: Minimum length should be less than the maximum length." << endl;
//         return 1;
//     }

//     cout << "Do you want to add uppercase letters to your password? (Y/N): ";
//     cin >> answerUppercase;

//     cout << "Do you want to add symbols to your password? (Y/N): ";
//     cin >> answerSymbols;

//     cout << "Do you want to add numbers to your password? (Y/N): ";
//     cin >> answerNumbers;
    
//     // тут создаем строку-контейнер для наших букв, цифр, символов
//     string charContainer = "abcdefghijklmnopqrstuvwxyz";

//     if (includeCharacterType(answerUppercase, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")))) // если пользователь нажал на Y, начинает заполнять контейнер
//         charContainer += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
//     if (includeCharacterType(answerSymbols, "<>{}()[].,/';:_*&^%$#@!?№-"))
//         charContainer += "_*&^%$#@!?№-";
    
//     if (includeCharacterType(answerNumbers, "0123456789"))
//         charContainer += "0123456789";

//     mt19937 generator(time(0)); // shuffle mechanism

//         fout << "Your password_ ";
//     string password;
//     for (int i = 0; i < maxLength; i++) {
//         char randomChar = getRandomChar(charContainer, generator);
//         fout << randomChar;
//         password += randomChar;
//     }

//     fout << endl;

//     int passwordStrength = calculatePasswordStrength(password);
//     cout << "Password strength: " << passwordStrength << " characters." << endl;

//     fout.close();

//     return 0;
// }
