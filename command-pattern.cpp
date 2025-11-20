#include <iostream>
using namespace std;

class ICommand {
public:
    virtual void execute() = 0;
    virtual ~ICommand() = default;
    ICommand() = default;
};
//клас отримувач//
class Light {
public:
    void turnOn() {
        cout << "Light is ON." << endl;
    }

    void turnOff() {
        cout << "Light is OFF." << endl;
    }
};
class LightOnCommand : public ICommand {
private:
    Light* light;
public:
    LightOnCommand(Light* l) : light(l) {}
    void execute() override {
        light->turnOn();
    }
};
class LightOffCommand : public ICommand {
private:
    Light* light;
public:
    LightOffCommand(Light* l) : light(l){}
    void execute() override {
        light->turnOff();
    }
};
//ініціатор//
class RemoteControl {
private:
    ICommand* command;
public:
    void SetCommand(ICommand* c) {
        command = c;
    }
    void PressButton() {
        if (command)
            command->execute();
    }
};
int main() {
    Light light;
    LightOnCommand onCmd(&light);
    LightOffCommand offCmd(&light);
    RemoteControl remote;

    int choice;
    cout << "Choose command:\n1 - Turn ON\n2 - Turn OFF\n> ";
    cin >> choice;

    if (choice == 1) {
        remote.SetCommand(&onCmd);
    }
    else if (choice == 2) {
        remote.SetCommand(&offCmd);
    }
    else {
        cout << "Invalid choice." << endl;
        return 1;
    }
    remote.PressButton();
    return(0);
}
