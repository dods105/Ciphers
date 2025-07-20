#include <iostream>
#include <string>
#include <cctype>

std::string encrypt(std::string text, int a, int b){
    std::string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string encrypted_text;

    for(char c: text){
        if(isalpha(c)){
            int x = (toupper(c) - 'A');
            int position = ((a * x) + b) % 26;
            c = charset[position];
        }
        encrypted_text += c;
    }
    
    for(size_t i = 0; i < text.length(); i++){
        if(islower(text[i])){
            encrypted_text[i] = tolower(encrypted_text[i]);
        }
    }

    return encrypted_text;
}

std::string decrypt(std::string text, int a, int b){
    std::string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string decrypted_text;

    int inverse_a = -1; 
    for(int i = 0; i < 26; i++){
        if((a * i) % 26 == 1){
            inverse_a = i;
            break;
        }
    }
    
    for(char c: text){
        if (isalpha(c))
        {
            int x = toupper(c) - 'A';
            /* 
                charset.length() = 26
                decryption formula ( a**-1 ) mod charset.length()
                but: inverse of a != 1/a
                inverse of a is i:
                    where i statisfy the equation bleow:
                        (a * all of the possible i [1-26]) mod 26 = 1

            */
            int position = ((x - b)*inverse_a);
            position = (position % 26 + 26) % 26;
            c = charset[position];
        }
        decrypted_text += c;
    }  

    for(int i = 0; i < 26; i++){
        if(islower(text[i])){
            decrypted_text[i] = tolower(decrypted_text[i]);
        }
    }

    return decrypted_text;
}


int main(){
    std::string text = "Hello World";

    std::string encrypted = encrypt(text, 5,8);
    std::cout << encrypted << "\n";
    std::cout << decrypt(encrypted, 5,8);
}