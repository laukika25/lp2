#include <bits/stdc++.h>
using namespace std;

vector<string> QUESTIONS = {
    "Have you been experiencing persistent feelings of sadness or hopelessness?",
    "Do you find it difficult to enjoy activities that you used to find pleasurable?",
    "Have you been experiencing changes in appetite or weight?",
    "Are you having trouble sleeping or sleeping too much?",
    "Do you have low energy or fatigue most days?",
    "Have you been feeling excessively guilty or worthless?",
    "Do you have difficulty concentrating or making decisions?",
    "Have you had thoughts of harming yourself or others?",
    "Do you feel anxious or on edge most of the time?",
    "Have you been experiencing panic attacks or sudden feelings of intense fear?",
    "Do you have intrusive thoughts or obsessions that are distressing?",
    "Have you been engaging in compulsive behaviors or rituals?",
    "Are you experiencing hallucinations or delusions?",
    "Have you been using substances (such as drugs or alcohol) to cope with your feelings?",
};

const int SEVERE_THRESHOLD = 9;
const int MODERATE_THRESHOLD = 6;
const int MILD_THRESHOLD = 3;

int main()
{
    cout << "\n\n\t\tWelcome To The Mental Health Expert System\n"
         << endl;
    cout << "\tNote: Please answer the following questions honestly.\n\n"
         << endl;

    int score = 0;
    for (string question : QUESTIONS)
    {
        cout << question << " (Y/N)" << endl;
        string ans;
        getline(cin, ans);
        while (ans != "y" && ans != "n")
        {
            cout << "Invalid input! Please enter 'Y' for Yes or 'N' for No." << endl;
            getline(cin, ans);
        }
        if (ans == "y")
        {
            score += 1;
        }
    }

    cout << "\n\n";
    if (score >= SEVERE_THRESHOLD)
    {
        cout << "Severe symptoms..." << endl;
    }
    else if (score >= MODERATE_THRESHOLD)
    {
        cout << "Moderate symptoms..." << endl;
    }
    else if (score >= MILD_THRESHOLD)
    {
        cout << "Mild symptoms..." << endl;
    }
    else
    {
        cout << "No significant symptoms..." << endl;
    }

    cout << "\nFor immediate assistance, contact:" << endl;
    cout << "- National Suicide Prevention Lifeline: 1-800-273-TALK (8255)" << endl;
    cout << "- Crisis Text Line: Text HOME to 741741" << endl;
    cout << "- Local mental health services or emergency services" << endl;

    return 0;
}
