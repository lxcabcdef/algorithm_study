#include<string>

class Kmp{
public:
    Kmp(std::string key) : key_(key) {
        next_ = new int[key.size()];
        next_[0] = 0;
        int i,j;
        for (i = 1, j = 0; i < key.size(); i++) {
            while (j>0 && key[i] != key[j]) {
                j = next_[j-1];
            }
            if (key[i] == key[j]) {
                j++;
            }
            next_[i] = j;
        }
    }
    ~Kmp() {
        delete next_;
    }

    int search(std::string txt) {
        int i,j;
        for (i = 0, j = 0; i < txt.size(); i++) {
            while (txt[i] != key_[j] && j != 0) {
                j = next_[j];
            }
            j++;
            if (j == key_.size()) 
                break;
        }
        i = i == txt.size() ? -1 : i - key_.size() + 2;
        return i;
    }
private:
    std::string key_;
    int *next_;
};