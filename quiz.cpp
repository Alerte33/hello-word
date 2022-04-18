#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

int guess;

int total;


class Question
{
private:
    string question_text;
    string answer_1;
    string answer_2;
    string answer_3;
    string answer_4;
    int correct_answer;
    int question_score;

public:
    void setValues(string, string, string, string, string, int, int);
    void askQuestion();

};

void Question::setValues(string q, string a1, string a2, string a3, string a4, int ca, int pa)
{
    question_text = q;
    answer_1 = a1;
    answer_2 = a2;
    answer_3 = a3;
    answer_4 = a4;
    correct_answer = ca;
    question_score = pa;
}

void Question::askQuestion()
{
    cout << question_text << endl;
    cout << "1. " << answer_1 << endl;
    cout << "2. " << answer_2 << endl;
    cout << "3. " << answer_3 << endl;
    cout << "4. " << answer_4 << endl;

    cout << "Jaka jest twoja odpowiedź? ";
    cin >> guess;

    while (guess != 1 && guess != 2 && guess  != 3 && guess != 4)
    {
        cout << "Nie ma odpowiedzi o takim numerze" << endl;
        cout << "Jaka jest twoja odpowiedź? ";
        cin >> guess;
    }

    if (guess == correct_answer)
    {
        cout << "Zgadza się! To poprawna odpowiedź." << endl;
        total = total + question_score;

        cout << "Wynik: " << question_score << " / " << question_score << "!" << endl;
    }
    else
    {
        cout << "Źle! To nie jest poprawna odpowiedź." << endl;
        cout << "Wynik: 0" << "/ " << question_score << "!" << endl;
        cout << "Prawidlowa odpowiedz to " << correct_answer << "." << endl;
    }

}

class Quiz {
private:
    Question q1, q2, q3, q4, q5, q6, q7, q8, q9, q10;
    
public:
    void setGame();
    void display();
};

void Quiz::setGame()
{
    q1.setValues("Która funkcje musza zawierac wszyskie programy w c++?",
        "start*()",
        "system()",
        "main()",
        "program()",
        3,
        10);

    q2.setValues("Jak poprawnie uzywac komentarzy?",
        "*/ komentarz */",
        "/* komentarz */",
        "** komentarz **",
        " { komentarz } ",
        2,
        10);

    q3.setValues("Jakim znakiem kończy się każda instrukcja?",
        ";",
        ".",
        "*",
        ",",
        1,
        10);
    q4.setValues("Który typ danych przechowuje liczby całkowite?",
        "string",
        "bool",
        "double",
        "int",
        4,
        10
    );
    q5.setValues("Który operator porównuje dwie wartości",
        "==",
        "*",
        "-",
        "=",
        1,
        10
    );
    q6.setValues("Które słowo kluczowe jest używane, by utworzyć klasę?",
        "Class",
        "MyClass",
        "class",
        "createClass",
        3,
        10
    );
    q7.setValues("Nazwą zmiennej w języku c++ nie może być",
        "liczba",
        "while",
        "znak",
        "samochód",
        2,
        10
    );
    q8.setValues("Funkcja którego typu nie zwraca żadnej wartości",
        "int",
        "string",
        "void",
        "double",
        3,
        10
    );
    q9.setValues("Który operator logiczny odpowiada koniunkcji",
        "||",
        "!",
        "^",
        "&&",
        4,
        10
    );
    q10.setValues("Jaki jest rozmiar zmiennej typu int?",
        "2 bajty",
        "4 bajty",
        "8 bajtów",
        "16 bajtów",
        3,
        10
    );

    

}

void Quiz::display() {

    q1.askQuestion();
    q2.askQuestion();
    q3.askQuestion();
    q4.askQuestion();
    q5.askQuestion();
    q6.askQuestion();
    q7.askQuestion();
    q8.askQuestion();
    q9.askQuestion();
    q10.askQuestion();
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    int number_of_games = 0;
    Quiz quiz;
    quiz.setGame();
    char choice;

    cout << "Czy chcesz zagrać w quiz o c++?[t/n]" << endl;
    cin >> choice;
    
    while (choice == 't')
    {
        number_of_games++;
        quiz.display();
        cout << "Twój wynik to  " << total << "/ 100 ";
        cout << endl;
        total = 0;
        cout << "Czy chcesz zagrać ponownie?[t/n]" << endl;
        cin >> choice;
    }
       
    if (number_of_games >= 1)
        cout << "Dziękuję za wzięcie udziału w quizie" << endl;
    else
        cout << "Szkoda! Zapraszam innym razem!" << endl;

    return 0;
}


