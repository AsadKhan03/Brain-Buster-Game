#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <random>    

using namespace std;


struct Question {
    string question;
    string options[4];
    int correctAnswer; 
};


void displayQuestion(const Question &q, int questionNumber) {
    cout << "\nQuestion " << questionNumber + 1 << ": " << q.question << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}


int getUserAnswer() {
    int answer;
    while (true) {
        cout << "Enter your answer (1-4): ";
        cin >> answer;
        if (answer >= 1 && answer <= 4) {
            return answer;
        }
        cout << "Invalid input! Please enter a number between 1 and 4." << endl;
    }
}


void startQuiz(vector<Question> &questions) {
    int score = 0;
    for (size_t i = 0; i < questions.size(); i++) {
        displayQuestion(questions[i], i);
        int userAnswer = getUserAnswer();
        
        
        if (userAnswer == questions[i].correctAnswer) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect! The correct answer was " << questions[i].correctAnswer << ".\n";
        }
    }
    
 
    cout << "\nQuiz Over! Your final score: " << score << "/" << questions.size() << endl;
}


void shuffleQuestions(vector<Question> &questions) {
    // Create a random engine and shuffle the questions
    random_device rd;
    default_random_engine engine(rd());
    shuffle(questions.begin(), questions.end(), engine);
}

int main() {
    vector<Question> questions = {
        {"What is the name of the night when the Quran was first revealed to Prophet Muhammad (PBUH)?", {"Lailat-ul-Miraj", "Lailat-ul-Qadr", "Lailat-ul-Badr", "Lailat-ul-Mawlid"}, 2},
        {"What is the special prayer that is offered in Ramadan after the Isha prayer?", {"Fajr", "Maghrib", "Taraweeh", "Witr"}, 3},
        {"What is the name of the charity given during Ramadan, which is obligatory for Muslims?", {"Zakat", "Sadaqah", "Khums", "Fidyah"}, 1},
        {"Which angel is believed to bring the revelation of the Quran to Prophet Muhammad (PBUH) during Ramadan?", {"Mikail (Michael)", "Israfil (Raphael)", "Jibra'il (Gabriel)", "Azrael (Angel of Death)"}, 3}
    };

    char choice;
    do {
        shuffleQuestions(questions);
        startQuiz(questions);

        
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

        
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Invalid input! Please enter 'y' to play again or 'n' to quit: ";
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
