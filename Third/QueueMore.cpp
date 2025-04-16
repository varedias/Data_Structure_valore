#include <iostream>
#include <string>
#include <iomanip>

struct info {
    std::string name;
    std::string Gender;
    int age;
    long Number;
    info* next;
    info(std::string Name, std::string gender, int ages, long Num) 
        : name(Name), Gender(gender), age(ages), Number(Num), next(nullptr) {}
    info() : name(""), Gender(""), age(0), Number(0), next(nullptr) {}
};

class queue {
private:
    info* front;
    info* rear;
    int count;
public:
    queue() : front(nullptr), rear(nullptr), count(0) {}

    void Enque(std::string name, std::string Gender, int age, long Number) {
        info* NewInfo = new info(name, Gender, age, Number);
        if (rear == nullptr) {
            front = rear = NewInfo;
        } else {
            rear->next = NewInfo;
            rear = NewInfo;
        }
        count++;
        std::cout << name << " current people: " << count << std::endl;
    }

    info dequeue() {
        info tempInfo;
        if (empty()) {
            std::cout << "no patient in queue" << std::endl;
            return tempInfo;
        } else {
            tempInfo = *front;
            info* tempNode = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete tempNode;
            count--;
            std::cout << "please " << tempInfo.name << " left people: " << count << std::endl;
            return tempInfo;
        }
    }

    bool empty() {
        return front == nullptr;
    }

    void displayQueue() {
        if (empty()) {
            std::cout << "no patient！" << std::endl;
            return;
        }
        info* current = front;
        std::cout << "\n====queue ====" << std::endl;
        std::cout << std::left << std::setw(15) << "name" 
                  << std::setw(8) << "gender" 
                  << std::setw(5) << "age" 
                  << std::setw(15) << "Number" << std::endl;
        while (current != nullptr) {
            std::cout << std::left << std::setw(15) << current->name 
                      << std::setw(8) << current->Gender 
                      << std::setw(5) << current->age 
                      << std::setw(15) << current->Number << std::endl;
            current = current->next;
        }
        std::cout << "=================" << std::endl;
    }


};

int main() {
    queue hospitalQueue;


    hospitalQueue.Enque("valroe", "male", 35, 13800138000);
    hospitalQueue.Enque("varedias", "female", 28, 13900139000);
    hospitalQueue.Enque("steve", "male", 42, 13700137000);

    hospitalQueue.displayQueue();

 
    hospitalQueue.dequeue();
    hospitalQueue.dequeue();

    hospitalQueue.displayQueue();


    hospitalQueue.dequeue();
    hospitalQueue.dequeue();  

    return 0;
}