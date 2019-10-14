#include <iostream>
#include <map>
#include <tuple>
#include <string>
#include <cstdint>

using namespace std;

enum class TaskStatus {
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const {
		return tasksdb.at(person);
	}
	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person) {
		tasksdb[person][TaskStatus::NEW] += 1;
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count) {
		TasksInfo updated_tasks, untouched_tasks;
		if (tasksdb.count(person) != 0) {
			untouched_tasks = tasksdb.at(person);
			for (int i = (int)TaskStatus::NEW; i < (int)TaskStatus::DONE; ++i) {
				if (task_count > untouched_tasks[(TaskStatus)i]) {
					task_count -= untouched_tasks[(TaskStatus)i];
					updated_tasks[(TaskStatus)(i+1)] += untouched_tasks[(TaskStatus)i];
					untouched_tasks.erase((TaskStatus)i);
				}
				else {
					untouched_tasks[(TaskStatus)i] -= task_count;
					updated_tasks[(TaskStatus)(i+1)] += task_count;
					task_count = 0;
				}

				tasksdb.at(person)[(TaskStatus)i] = untouched_tasks[(TaskStatus)i] + updated_tasks[(TaskStatus)(i)];
			}
			tasksdb.at(person)[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

			GarbageCollector(updated_tasks);
			GarbageCollector(untouched_tasks);
			GarbageCollector(tasksdb[person]);
			untouched_tasks.erase(TaskStatus::DONE);
		}

		return tie(updated_tasks, untouched_tasks);
	}
private:
	map<string, TasksInfo> tasksdb;
	void GarbageCollector(TasksInfo& ti) {
		for (int i = (int)TaskStatus::NEW; i < 1 + (int)TaskStatus::DONE; ++i) {
			if(ti[(TaskStatus)i] == 0) {
				ti.erase((TaskStatus)i);
			}
		}
	}
};


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь




void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}
int main() {
  TeamTasks tasks;
 /*
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  */
  TasksInfo updated_tasks, untouched_tasks;
  tasks.AddNewTask("Ilia");
  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ilia", 1);
  for (int i = 0; i < 4; ++i) {
      tasks.AddNewTask("Ilia");
  }
  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ilia", 5);
  for (int i = 0; i < 2; ++i) {
	  tasks.AddNewTask("Ilia");
  }
  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ilia", 120);
  for (int i = 0; i < 3; ++i) {
      tasks.AddNewTask("Ilia");
  }
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ilia", 4);
  cout << "Updated Ilia's tasks: ";
   PrintTasksInfo(updated_tasks);
   cout << "Untouched Ilia's tasks: ";
   PrintTasksInfo(untouched_tasks);
   PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));



  return 0;
}

