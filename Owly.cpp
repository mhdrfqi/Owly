#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <mutex>
#include <set>

using namespace std;

mutex mtx;  // Mutex to protect file writing

// List of commonly used passwords (this can be expanded)
const vector<string> commonPasswords = {
    "123456", "password", "123456789", "12345", "12345678", "qwerty", "abc123", "letmein", "1q2w3e4r", "password123",
    "welcome", "1234", "qwerty123", "admin", "root", "welcome1", "monkey", "123123", "sunshine", "qwertyuiop", "iloveyou"
};

// Function to convert a word into Leetspeak
string toLeetSpeak(string word) {
    for (char &c : word) {
        switch (c) {
            case 'a': case 'A': c = '4'; break;
            case 'e': case 'E': c = '3'; break;
            case 'i': case 'I': c = '1'; break;
            case 'o': case 'O': c = '0'; break;
            case 's': case 'S': c = '$'; break;
            case 't': case 'T': c = '7'; break;
            case 'l': case 'L': c = '|'; break;   // Added L variation
            case 'g': case 'G': c = '9'; break;   // Added G variation
            case 'b': case 'B': c = '8'; break;   // Added B variation
        }
    }
    return word;
}

// Function to generate passwords and save them to a file (in a separate thread)
void generatePasswords(int id, vector<string>& words, int totalPasswords, ofstream& outfile) {
    srand(time(0) + id); // Unique seed for each thread to avoid collisions
    int count = 0;

    while (count < totalPasswords) {
        // Select random words for generating combinations
        string word1 = words[rand() % words.size()];
        string word2 = words[rand() % words.size()];

        vector<string> tempList = {
            word1 + word2,
            word2 + word1,
            word1 + "123",
            word1 + "!",
            word1 + word2 + "@",
            toLeetSpeak(word1 + word2),
            toLeetSpeak(word2 + word1),
            word1 + "2024",
            word2 + "#1",
            "!" + word1,
            toLeetSpeak(word1) + "_secure"
        };

        // Add common passwords to the list
        for (const auto& commonPass : commonPasswords) {
            tempList.push_back(commonPass + word1);
            tempList.push_back(commonPass + word2);
            tempList.push_back(word1 + commonPass);
            tempList.push_back(word2 + commonPass);
            tempList.push_back(toLeetSpeak(commonPass) + word1);
            tempList.push_back(toLeetSpeak(commonPass) + word2);
        }

        for (const auto& pass : tempList) {
            if (pass.length() >= 6 && pass.length() <= 16) {
                mtx.lock();
                outfile << pass << endl;  // Write to file using mutex for thread safety
                mtx.unlock();
                count++;

                // Update progress every 1000 passwords
                if (count % 1000 == 0) {
                    cout << "Thread " << id << " Progress: " << (count * 100) / totalPasswords << "% done\n";
                }
            }

            if (count >= totalPasswords) break;
        }
    }
    cout << "Thread " << id << " finished generating passwords." << endl;
}

int main() {
    vector<string> words;
    string input;

    cout << "\n    (o_o) Owly - Advanced Dictionary Generator" << endl;
    cout << "    ----------------------------------------" << endl;
    cout << "    Instagram: @dannyk_739 | GitHub: Danyalkhattak" << endl;
    cout << "    ----------------------------------------\n" << endl;

    // Collect input from the user
    cout << "Enter first name: ";
    cin >> input;
    words.push_back(input);

    cout << "Enter last name: ";
    cin >> input;
    words.push_back(input);

    cout << "Enter birth year or special number: ";
    cin >> input;
    words.push_back(input);

    cout << "Enter a keyword (pet, favorite team, etc.): ";
    cin >> input;
    words.push_back(input);

    int totalPasswords = 50000;  // Target number of passwords
    int numThreads = 4;  // Number of threads to use (you can change this)

    cout << "Generating wordlist...\n";

    // Open the output file
    ofstream outfile("wordlist.txt");
    if (!outfile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    // Start generating passwords using multiple threads
    vector<thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(thread(generatePasswords, i, ref(words), totalPasswords / numThreads, ref(outfile)));
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    outfile.close();
    cout << "Wordlist saved to wordlist.txt successfully!\n";
    return 0;
}
