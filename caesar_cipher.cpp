#include <iostream>
#include <string>
#include <cctype>

std::string encrypt(std::string text, int key){
    std::string encrypted_text;
    for (char c: text){
        if(isalpha(c)){
            char base_position = isupper(c) ? 'A' : 'a';
            c = (c - base_position + key) % 26 + base_position;
        }
        encrypted_text += c;
    }

    return encrypted_text;
}

std::string decrypt(std::string text, int key){
    std::string decrypted_text;
    for(char c: text){
        if(isalpha(c)){
            char base_position = isupper(c) ? 'A' : 'a';
            c = (c - base_position - key) % 26 + base_position;
        }
        decrypted_text += c;
    }
    return decrypted_text;
}

int main(){
    std::cout << encrypt("Hello World" , 3);
    std::cout << "\n" << decrypt("Khoor Zruog", 3);
}