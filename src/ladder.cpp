#include "ladder.h"

void error(string word1, string word2, string msg) {std::cout << "Key Error 1: " << word1 << "Key Error 2: " << word2 << "\nError message: " << msg << std::endl;}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int strlen1 = str1.length();
    int strlen2 = str2.length();

    if (abs(strlen1 - strlen2) > d)
        return false;

    int i = 0;
    int j = 0;
    int diff = 0;
    while (i < strlen1 && j < strlen2) {
        if (str1[i] != str2[j]) {
            diff++;
            if (diff > d) {return false;} 
            if (strlen1 > strlen2)
                i++;
            else if (strlen1 < strlen2)
                j++;
            else{  
                i++;
                j++;
            }
        }
        else{
            i++;
            j++;
        }
    }
    diff += (strlen1 - i);
    diff += (strlen2 - j);
    return diff <= d;
}

bool is_adjacent(const string& word1, const string& word2) {return edit_distance_within(word1, word2, 1);}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);
void load_words(set<string> & word_list, const string& file_name);
void print_word_ladder(const vector<string>& ladder);

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}