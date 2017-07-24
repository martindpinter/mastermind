#include <iostream>
#include <random>
#include <algorithm>

int getMTrnd() {
    std::random_device rd;
    std::mt19937 mt(rd());  // seed the Mersenne Twister generator
    std::uniform_int_distribution<> dist(1000, 9999); 
    return dist(mt);
}

void SplitInt(int x, std::vector<int>& o) {
   
   while (x) {
        o.push_back(x % 10);
        x /= 10;
    }
    
    std::reverse(o.begin(), o.end());
}

void evaluate(int iGuess, int iSolution) {
    
    // split integer >> vector<int>
    std::vector<int> vGuess;
    std::vector<int> vSolution;
    
    SplitInt(iGuess, vGuess);
    SplitInt(iSolution, vSolution);
    
    
    // calculate Bulls and Cows
    int bulls = 0;
    int cows = 0;
    
    for (int i = 0; i < vGuess.size(); ++i) {
        if (std::find(vSolution.begin(), vSolution.end(), vGuess[i]) != vSolution.end()) 
            if (vGuess[i] == vSolution[i])
                bulls++;
            else
                cows++;
    }
    std::cout << bulls << "B " << cows << "C" << std::endl << std::endl;
}

int main() {
    std::cout << "M A S T E R M I N D\t(Bulls and Cows)";
    std::string PlayAgain = "";
    
    while ((PlayAgain == "") || (PlayAgain == "Y") || (PlayAgain == "YES")) {   // "" does not continue
        std::cout << std::endl << "####" << std::endl << std::endl;
        int Guess = 0;
        int Solution = getMTrnd();
        PlayAgain = "";
        
        std::cout << Solution << std::endl;
        
        while (Guess != Solution) {
            std::cin >> Guess;   
            std::cout << "\t";
            evaluate(Guess, Solution);
        }
        
        std::cout << "Congratulations! Play again? [Y/n]";
        std::cin >> PlayAgain;
        std::transform(PlayAgain.begin(), PlayAgain.end(), PlayAgain.begin(), ::toupper);
    }
    
    
    return 0;
}