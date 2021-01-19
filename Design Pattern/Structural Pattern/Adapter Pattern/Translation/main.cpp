#include <iostream>
#include <string>
using namespace std;

class Language {
protected:
    string _message;
public:
    void setMessage(string message) {
        _message = message;
    }
    string getMessage() {
        return _message;
    }
};

class VietnameseLanguage : public Language {
};

class JapaneseLanguage : public Language {
};

class Vietnamese {
private:
    VietnameseLanguage vnl;
public:
	void VietnameseSay(string message) {
		vnl.setMessage(message);
	}
	void SendMessageToApp() {
        cout << "Send " << vnl.getMessage() << " to app to translate. Waiting..." << endl;
    }
};

class Japanese {
private:
	JapaneseLanguage jpl;
public:
	void ReceiveMessageFromApp(string message) {
        jpl.setMessage(message);
        cout << "Received " << jpl.getMessage() << " from app." << endl;
    }
};
class AppConvertVietnameseToJapanese : public Vietnamese {
private:
    Japanese jp;
public:
    void ConvertVietnameseToJapanese(string message) {
		VietnameseSay(message);
        SendMessageToApp();
        cout << "Translate successfully! " << endl;
        message = "Kimochi";
        jp.ReceiveMessageFromApp(message);
    }
};

int main() {
    AppConvertVietnameseToJapanese a;
    a.ConvertVietnameseToJapanese("Suong qua");
}
