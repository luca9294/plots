#include <deque>
#include <string>

class tokenizer {
        std::string delimiters; //the string which holds our desired delimiters to separate the text based on
        std::deque<std::string> tokens; //the double-ended queue which holds all the parts of the parsed text

        bool isdelimiter(char c) { //an inline private function which tells us if a given character is in the delimiters
            return delimiters.find( c ) != std::string::npos; //confused? hahaha DON'T be, it says return the result of this sentence
            //will be true when there exists a character in the string "delimiters", and will be false if the result is equal to npos, which means the "find" function did not find a match
        }
public: //now we define these member functions as public so that they can be called from outside
        tokenizer(const std::string& is, const std::string& delim) : delimiters(delim) { //call the constructor of delimiters string which assigns the delim to it
            std::string tmp; //a temporary string used to hold the parts
            std::size_t p, end = is.length(); //these are for holding location indexes of string
            for(p=0; p<end; p++) { //loop through all the characters in the string
                if( isdelimiter(is.at(p)) ) { //if this character of string is a delimiter,
                    if(tmp.length() != 0) { //if the length of the tmp string which holds the current part is not zero
                        tokens.push_back(tmp); //add this part to the deque
                        tmp = ""; //empty the string
                    }
                } else {
                    tmp += is.at(p); //the character was not a delimiter, so add it to the tmp which holds the current part
                }
             }
        }

        bool has_next() { //used to check if the deque has got empty
            return !tokens.empty(); //will return true if deque is NOT empty
        }

        std::string next_token() {
            std::string token( tokens.front() ); //assign the first string located in deque to the token string
            tokens.pop_front(); //remove the first item in the deque which we just assigned to token
            return token;
        }
};



