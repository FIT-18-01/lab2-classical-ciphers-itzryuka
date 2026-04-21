#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid_message(const string &text) {
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

string rail_fence_encrypt(const string &plaintext, int rails) {
    if (rails <= 1 || plaintext.empty()) return plaintext;

    vector<string> fence(rails, "");
    int rail = 0;
    int direction = 1;

    for (char c : plaintext) {
        fence[rail] += c;
        rail += direction;
        if (rail == rails - 1 || rail == 0) direction = -direction;
    }

    string ciphertext;
    for (const string &row : fence) ciphertext += row;
    return ciphertext;
}

string rail_fence_decrypt(const string &ciphertext, int rails) {
    if (rails <= 1 || ciphertext.empty()) return ciphertext;

    // Bước 1: Tạo ma trận đánh dấu vị trí zigzag
    vector<vector<bool>> mark(rails, vector<bool>(ciphertext.length(), false));
    int row = 0;
    int direction = 1;

    for (size_t i = 0; i < ciphertext.length(); i++) {
        mark[row][i] = true;
        row += direction;
        if (row == rails - 1 || row == 0) direction = -direction;
    }

    // Bước 2: Điền ký tự từ ciphertext vào các vị trí đã đánh dấu
    vector<string> fence(rails, string(ciphertext.length(), ' '));
    size_t idx = 0;
    for (int r = 0; r < rails; r++) {
        for (size_t c = 0; c < ciphertext.length(); c++) {
            if (mark[r][c] && idx < ciphertext.length()) {
                fence[r][c] = ciphertext[idx++];
            }
        }
    }

    // Bước 3: Đọc theo đường zigzag để lấy plaintext
    string plaintext;
    row = 0;
    direction = 1;
    for (size_t i = 0; i < ciphertext.length(); i++) {
        plaintext += fence[row][i];
        row += direction;
        if (row == rails - 1 || row == 0) direction = -direction;
    }
    
    return plaintext;
}

string read_message_from_file(const string &path) {
    ifstream fin(path);
    string line;
    getline(fin, line);
    return line;
}

int main() {
    cout << "=== Rail Fence Cipher Demo ===\n";
    cout << "1. Encrypt\n2. Decrypt\n3. Read from file and encrypt\nChoose: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string message;
    int rails;

    if (choice == 3) {
        message = read_message_from_file("data/input.txt");
        cout << "Message from file: "