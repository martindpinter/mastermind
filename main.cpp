#include <iostream>
#include <random>
#include <algorithm>
#include <string>

bool evaluate(std::string Guess, std::string Solution) {
    
    if (Guess.length() == 4) {
        // calculate Bulls and Cows
        int bulls = 0;
        int cows = 0;
        std::vector<int> MarkedIndices;
        std::vector<int> BullValues;
        
        for (int i = 0; i < Solution.length(); ++i) {
            if (Guess[i] == Solution[i]) {
                bulls++;
                MarkedIndices.push_back(i);
                BullValues.push_back(Guess[i]); // Bulls' values must be stored to avoid marking a Cow for a used Bull
            }
            else if ((Solution.find(Guess[i]) != std::string::npos) 
                 && ((std::find(MarkedIndices.begin(), MarkedIndices.end(), i) == MarkedIndices.end()))
                 && ((std::find(BullValues.begin(), BullValues.end(), Guess[i]) == BullValues.end()))) {
                cows++;
                MarkedIndices.push_back(i);
            }
        }
        std::cout << bulls << "B " << cows << "C" << std::endl << std::endl;
        return true;
    } else {
        std::cout << "Invalid input. Your guess must be a 4-digit number." << std::endl << std::endl;
        return false;
    }
}

int main() {
    
    std::random_device rd;
    std::mt19937 mt(rd());  // seed 
    std::uniform_int_distribution<> dist(1000, 9999); 
    
    int maxlives = 8;
    
    std::cout << "M A S T E R M I N D\t(Bulls and Cows)" << std::endl;
    std::cout << "You have " << maxlives << " tries to solve ####" << std::endl << std::endl;
    std::string PlayAgain = "";
    
    
    while ((PlayAgain == "") || (PlayAgain == "Y") || (PlayAgain == "YES")) {   
        
        int lives = maxlives;
        std::string Guess = "";
        std::string Solution = std::to_string(dist(mt));
        PlayAgain = "";
        
        while ((Guess != Solution) && (lives > 0)) {
            if (lives == 1)
                std::cout << "Last try" << std::endl;
            std::cin >> Guess;   
            std::cout << "\t";
        
            if (evaluate(Guess, Solution))
                lives--;
        }
        
        if (lives > 0)
            std::cout << "Congratulations! Play again? [Y/n]";
        else
            std::cout << "Game over. The solution was " << Solution << ". Play Again? [Y/n]";
            
        //std::getline(std::cin, PlayAgain);    // Skips input. Need to flush cin buffer?
        std::cin >> PlayAgain;
        std::transform(PlayAgain.begin(), PlayAgain.end(), PlayAgain.begin(), ::toupper);
    }
    
    
    return 0;
}