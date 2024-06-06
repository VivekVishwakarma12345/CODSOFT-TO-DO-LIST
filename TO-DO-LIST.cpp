#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string &desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string &taskDescription) {
        tasks.push_back(Task(taskDescription));
        std::cout << "Task added: " << taskDescription << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << std::endl;
            }
        }
    }

    void markTaskAsCompleted(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task " << taskIndex << " marked as completed." << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex > 0 && taskIndex <= tasks.size()) {
            std::cout << "Task removed: " << tasks[taskIndex - 1].description << std::endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option:";
}

int main() {
    ToDoList todoList;
    int choice;
    std::string taskDescription;
    size_t taskIndex;

    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Ignore leftover newline character
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;

            case 2:
                todoList.viewTasks();
                break;

            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;
                todoList.markTaskAsCompleted(taskIndex);
                break;

            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;

            case 5:
                std::cout << "Exiting..." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
