#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Heros {
protected:
    string _nameHero;
    int _bloodHero;
    int _power;
public:
    int GetPower() {
        return _power;
    }
    int& GetBloodHero() {
        return _bloodHero;
    }
    string GetNameHero() {
        return _nameHero;
    }
    void Hit(Heros* heros) {
        heros->GetBloodHero() = heros->GetBloodHero() - _power;
        if (heros->GetBloodHero() <= 0) {
            cout << "After " << _nameHero << " hit, " << heros->GetNameHero() << " was died" << endl;
        }
        else {
            cout << "After " << _nameHero << " hit, " << heros->GetNameHero() << " remain " << heros->GetBloodHero() << " blood" << endl;

        }
    }
};

class Thanos : public Heros {
private:
    Thanos();
    Thanos(int bloodHero, int power) {
        _nameHero = "Thanos";
        _bloodHero = bloodHero;
        _power = power;
    }
    static Thanos* instance;
public:
    Thanos(const Thanos&) = delete;
    void operator=(Thanos&) = delete;
    static Thanos* GetInstance(int bloodHero, int power) {
        if (instance == nullptr) {
            instance = new Thanos(bloodHero, power);
        }
        return instance;
    }
};
Thanos* Thanos::instance = nullptr;

class CaptainAmerica : public Heros {
private:
    CaptainAmerica();
    CaptainAmerica(int bloodHero, int power) {
        _nameHero = "CaptainAmerica";
        _bloodHero = bloodHero;
        _power = power;
    }
    static CaptainAmerica* instance;
public:
    CaptainAmerica(const CaptainAmerica&) = delete;
    void operator=(CaptainAmerica&) = delete;
    static CaptainAmerica* GetInstance(int bloodHero, int power) {
        if (instance == nullptr) {
            instance = new CaptainAmerica(bloodHero, power);
        }
        return instance;
    }
};
CaptainAmerica* CaptainAmerica::instance = nullptr;

class IronMan : public Heros {
private:
    IronMan();
    IronMan(int bloodHero, int power) {
        _nameHero = "IronMan";
        _bloodHero = bloodHero;
        _power = power;
    }
    static IronMan* instance;
public:
    IronMan(const IronMan&) = delete;
    void operator=(IronMan&) = delete;
    static IronMan* GetInstance(int bloodHero, int power) {
        if (instance == nullptr) {
            instance = new IronMan(bloodHero, power);
        }
        return instance;
    }
};
IronMan* IronMan::instance = nullptr;

class Thor : public Heros {
private:
    Thor();
    Thor(int bloodHero, int power) {
        _nameHero = "Thor";
        _bloodHero = bloodHero;
        _power = power;
    }
    static Thor* instance;
public:
    Thor(const Thor&) = delete;
    void operator=(Thor&) = delete;
    static Thor* GetInstance(int bloodHero, int power) {
        if (instance == nullptr) {
            instance = new Thor(bloodHero, power);
        }
        return instance;
    }
};
Thor* Thor::instance = nullptr;

enum TypeHeros {
    CAPTAINAMERICA = 0,
    IRONMAN,
    THOR
};

class CreateHero {
public:
    static Heros* GetHero(TypeHeros type) {
        Heros* heros;
        switch(type) {
            case CAPTAINAMERICA:
                heros = CaptainAmerica::GetInstance(60, 5);
                break;
            case IRONMAN:
                heros = IronMan::GetInstance(40, 10);
                break;
            case THOR:
                heros = Thor::GetInstance(80, 15);
                break;
            default:
                heros = CaptainAmerica::GetInstance(60, 5);
                break;
        }
        return heros;
    }
};

class Avenger {
private:
    vector<Heros*> arrHeros;
public:
    void AddHero(Heros* heros) {
        arrHeros.push_back(heros);
    }
    vector<Heros*> GetHerosList() {
        return arrHeros;
    }
};

void EndGame(Heros* thanos, vector<Heros*> arrHeros) {
    while(thanos->GetBloodHero() > 0 && arrHeros.size() > 0) {
        for (int i = 0; i < arrHeros.size(); i++) {
            if (thanos->GetBloodHero() <= 0) {
                break;
            }
            arrHeros[i]->Hit(thanos);
        }
        cout << endl;
        int j = 0;
        if (thanos->GetBloodHero() <= 0) {
            break;
        }
        thanos->Hit(arrHeros[j]);
        if (arrHeros[j]->GetBloodHero() <= 0) {
            arrHeros.erase(arrHeros.begin());
        }
        cout << endl;
    }
}

int main() {
    Heros* thanos = Thanos::GetInstance(125, 30);
    Heros* captain = CreateHero::GetHero(TypeHeros::CAPTAINAMERICA);
    Heros* ironman = CreateHero::GetHero(TypeHeros::IRONMAN);
    Heros* thor = CreateHero::GetHero(TypeHeros::THOR);
    Avenger avenger;
    avenger.AddHero(captain);
    avenger.AddHero(ironman);
    avenger.AddHero(thor);
    EndGame(thanos, avenger.GetHerosList());

}