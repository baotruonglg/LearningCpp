#include <iostream>
#include <string>
using namespace std;

class State {
private:
    string _name;
public:
    virtual void ConvertState(State*) = 0;
};

class IMusicPlayer {
public:
    virtual void setState(State*) = 0;
    virtual State* getState() = 0;
    virtual void ConvertState(State*) = 0;
};

class PlayState : public State {
private:
    IMusicPlayer* imusicplayer;
public:
    PlayState(IMusicPlayer* imusic) {
        imusicplayer = imusic;
    }  
    void ConvertState(State* state) {

    }
};

class PauseState : public State {
private:
    IMusicPlayer* imusicplayer;
public:
    PauseState(IMusicPlayer* imusic) {
        imusicplayer = imusic;
    }  
    void ConvertState(State* state) {
        
    }
};

class StopState : public State {
private:
    IMusicPlayer* imusicplayer;
public:
    StopState(IMusicPlayer* imusic) {
        imusicplayer = imusic;
    }
    void ConvertState(State* state) {

    }
};

class MusicPlayer : public IMusicPlayer {
private:
    State* _currentState;
    State* _playState;
    State* _pauseState;
    State* _stopState;
    enum TypeState {
        STOP_STATE = 0,
        PAUSE_STATE,
        PLAY_STATE
    };
public:
    MusicPlayer() {
        _playState = new PlayState(this);
        _pauseState = new PauseState(this);
        _stopState = new StopState(this);
        _currentState = _stopState;
        cout << "MusicPlayer is stopping" << endl;
    }
    void ConvertState() {
        TypeState type;
        switch(type) {
            case STOP_STATE:
                if (1)
        }
    }
    void setState(State* state) {
        _currentState = state;
    }
    State* getState() {
        return _currentState;
    }
};

int main() {

}