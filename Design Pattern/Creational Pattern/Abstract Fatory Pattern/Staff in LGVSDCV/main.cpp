#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class StaffInCDepartment {
protected:
    string _name;
    int _mark;
public:
    void setMark(int mark) {
		_mark = mark;
	} 
    int GetMark() {
        return _mark;
    }
    virtual string showName() = 0;
};

class QBao : public StaffInCDepartment {
private:
    QBao() {
    }
    static QBao* instance;
public:
    QBao(const QBao&) = delete;
    void operator=(QBao&) = delete;
    static QBao* GetInstance() {
        if (instance == nullptr) {
            instance = new QBao();
        }
        return instance;
    }
    string showName() {
        return "Truong Quang Bao";
    }
};
QBao* QBao::instance = nullptr;

class Quan : public StaffInCDepartment {
private:
    Quan() {
    }
    static Quan* instance;
public:
    Quan(const Quan&) = delete;
    void operator=(Quan&) = delete;
    static Quan* GetInstance() {
        if (instance == nullptr) {
            instance = new Quan();
        }
        return instance;
    }
    string showName() {
        return "Nguyen Chon Quan";
    }
};
Quan* Quan::instance = nullptr;

class Dao : public StaffInCDepartment {
private:
    Dao() {
    }
    static Dao* instance;
public:
    Dao(const Dao&) = delete;
    void operator=(Dao&) = delete;
    static Dao* GetInstance() {
        if (instance == nullptr) {
            instance = new Dao();
        }
        return instance;
    }
    string showName() {
        return "Huynh Tan Dao";
    }
};
Dao* Dao::instance = nullptr;

class StaffInJavaDepartment {
protected:
    string _name;
    int _mark;
public:
    void setMark(int mark) {
		_mark = mark;
	}
    int GetMark() {
        return _mark;
    }
    virtual string showName() = 0;
};

class Thanh : public StaffInJavaDepartment {
private:
    Thanh() {
    }
    static Thanh* instance;
public:
    Thanh(const Thanh&) = delete;
    void operator=(Thanh&) = delete;
    static Thanh* GetInstance() {
        if (instance == nullptr) {
            instance = new Thanh();
        }
        return instance;
    }
    string showName() {
        return "Hi Phuoc Thanh";
    }
};
Thanh* Thanh::instance = nullptr;

class Thuat : public StaffInJavaDepartment {
private:
    Thuat() {
    }
    static Thuat* instance;
public:
    Thuat(const Thuat&) = delete;
    void operator=(Thuat&) = delete;
    static Thuat* GetInstance() {
        if (instance == nullptr) {
            instance = new Thuat();
        }
        return instance;
    }
    string showName() {
        return "Nguyen Quang Thuat";
    }
};
Thuat* Thuat::instance = nullptr;

class StaffInLGVSDCV {
public:
    virtual StaffInCDepartment* GetCStaff() = 0;
    virtual StaffInJavaDepartment* GetJavaStaff() = 0;
};

class StaffInHN : public StaffInLGVSDCV {
public:
    StaffInCDepartment* GetCStaff() {
        return Dao::GetInstance();
    }
    StaffInJavaDepartment* GetJavaStaff() {
        return Thuat::GetInstance();
    }
};

enum TypeStaff {
    QBAO = 0,
    QUAN
};

class StaffInDN : public StaffInLGVSDCV {
private:
    TypeStaff _type;
public:
    StaffInDN() {}
    StaffInDN(TypeStaff type) {
        _type = type;
    }
    StaffInCDepartment* GetCStaff() {
        switch(_type) {
            case QBAO:
                return QBao::GetInstance();
                break;
            case QUAN:
                return Quan::GetInstance();
                break;
            default:
                return QBao::GetInstance();
                break;
        }
    }
    StaffInJavaDepartment* GetJavaStaff() {
        return Thanh::GetInstance();
    }
};

class CompetitionInLGVSDCV {
private:
    StaffInLGVSDCV* staffinhn = new StaffInHN();
    StaffInCDepartment* dao = staffinhn->GetCStaff();
    StaffInJavaDepartment* thuat = staffinhn->GetJavaStaff();
    StaffInLGVSDCV* staffindn = new StaffInDN(QBAO);
    StaffInCDepartment* qbao = staffindn->GetCStaff();
    StaffInCDepartment* quan = (new StaffInDN(QUAN))->GetCStaff();
    StaffInJavaDepartment* thanh = staffindn->GetJavaStaff();
public:
    void SetMarkInCompetition() {
        int temp;
        cout << "Enter the mark of C++ Team: " << endl;
        cout << "Enter the mark of " << dao->showName() << ": ";
        cin >> temp;
        dao->setMark(9);
        cout << "Enter the mark of " << qbao->showName() << ": ";
        cin >> temp;
        qbao->setMark(10);
        cout << "Enter the mark of " << quan->showName() << ": ";
        cin >> temp;
        quan->setMark(6);
        cout << endl;
        cout << "Enter the mark of Java Team: " << endl;
        cout << "Enter the mark of " << thuat->showName() << ": ";
        cin >> temp;
        thuat->setMark(8);
        cout << "Enter the mark of " << thanh->showName() << ": ";
        cin >> temp;
        thanh->setMark(8);
    }
    void FindStaffHighestMark() {
        vector<StaffInCDepartment*> arrCStaff;
        arrCStaff.push_back(dao);
        arrCStaff.push_back(qbao);
        arrCStaff.push_back(quan);
        int MAX =  arrCStaff[0]->GetMark();
        int person = 0;
        for (int i = 0; i < arrCStaff.size(); i++) {
            if (arrCStaff[i]->GetMark() > MAX) {
                MAX =  arrCStaff[i]->GetMark();
                person = i;
            }
        }
        cout << endl << "The person who has highest mark in C++ department: " << arrCStaff[person]->showName() << endl << endl;
        vector<StaffInJavaDepartment*> arrJavaStaff;
        arrJavaStaff.push_back(thuat);
        arrJavaStaff.push_back(thanh);
        MAX = arrJavaStaff[0]->GetMark();
        person = 0;
        for (int i = 0; i < arrJavaStaff.size(); i++) {
            if (arrJavaStaff[i]->GetMark() > MAX) {
                MAX =  arrJavaStaff[i]->GetMark();
                person = i;
            }
        }
        cout << endl << "The person who has highest mark in Java department: " << arrJavaStaff[person]->showName() << endl << endl;
    }
};

int main() {
    CompetitionInLGVSDCV a;
    a.SetMarkInCompetition();
    a.FindStaffHighestMark();
}
